import { Component, inject } from '@angular/core';
import { MatInputModule } from '@angular/material/input';
import { MatIconModule } from '@angular/material/icon';
import { MatButtonModule } from '@angular/material/button';
import { MatCardModule, MatCardTitle } from '@angular/material/card';
import { MatSelectModule } from '@angular/material/select';
import { MatRadioModule } from '@angular/material/radio';
import { UserService } from '../services/user.service';
import { Router } from '@angular/router';
import { CommonService } from '../services/common.service';
import { NgToastService } from 'ng-angular-popup';
import { FormBuilder, ReactiveFormsModule, Validators } from '@angular/forms';
import { loginUserType } from '../types/userTypes';

@Component({
  selector: 'app-login',
  standalone: true,
  imports: [
    MatInputModule,
    MatIconModule,
    MatButtonModule,
    MatCardModule,
    MatCardTitle,
    MatSelectModule,
    MatRadioModule,
    ReactiveFormsModule
  ],
  templateUrl: './login.component.html',
  styleUrl: './login.component.css',
})
export class LoginComponent {
  constructor(
    private userService: UserService,
    private router: Router,
    private commonService: CommonService,
    private toaster: NgToastService
  ) {}
  formBuilder = inject(FormBuilder);
  passwordHide: boolean = true;

  userLogin = this.formBuilder.group({
    email: ['', [Validators.email, Validators.required]],
    password: ['', Validators.required],
  });
  // registerUser() {}
  changePasswordVisibility(event: MouseEvent) {
    this.passwordHide = !this.passwordHide;
    event.stopPropagation();
  }
 
  submitLoginData() {
    if (this.userLogin.valid) {
      const newUser: loginUserType = {
        email: this.userLogin.value.email!,
        password: this.userLogin.value.password!,
      };

      this.userService.loginUser(newUser).subscribe({
        next: (data) => {
          this.router.navigate(['/']);
          this.commonService.userLoggedIn.emit(true);
          this.toaster.success({
            detail: 'SUCCESS',
            summary: 'User Logged In successfully',
            duration: 3000,
          });
          this.router.navigate(['/home']);
        },
        error: (err) => {
          this.toaster.error({
            detail: 'ERROR',
            summary: err.error.message,
            duration: 3000,
          });
        },
      });
    } else {
      console.log('Form validation failed');
    }
  }
}
