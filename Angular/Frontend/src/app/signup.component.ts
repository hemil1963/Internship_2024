import { Component, inject } from '@angular/core';
import { ReactiveFormsModule, FormBuilder, Validators } from '@angular/forms';
import { MatFormFieldModule } from '@angular/material/form-field';
import { MatInputModule } from '@angular/material/input';
import { MatIconModule } from '@angular/material/icon';
import { MatButtonModule } from '@angular/material/button';
import { MatCardModule, MatCardTitle } from '@angular/material/card';
import { MatSelectModule } from '@angular/material/select';
import { MatRadioModule } from '@angular/material/radio';
import { UserService } from '../services/user.service';
import { Router } from '@angular/router';
import { NgToastService } from 'ng-angular-popup';
import { CommonService } from '../services/common.service';
import { registerUserType } from '../types/userTypes';
@Component({
  selector: 'app-signup',
  standalone: true,
  imports: [
    ReactiveFormsModule,
    MatFormFieldModule,
    MatInputModule,
    MatIconModule,
    MatButtonModule,
    MatCardModule,
    MatCardTitle,
    MatSelectModule,
    MatRadioModule,
  ],
  templateUrl: './signup.component.html',
  styleUrl: './signup.component.css',
})
export class SignupComponent {
  
  constructor(
    private userService: UserService,
    private router: Router,
    private commonService: CommonService,
    private toaster: NgToastService
  ) {}
  formBuilder = inject(FormBuilder);
  passwordHide: boolean = true;
  cPasswordHide: boolean = true;

  userRegistration = this.formBuilder.group({
    name: [
      '',
      [
        Validators.required,
        Validators.pattern(/^[a-zA-Z]+$/),
        Validators.minLength(2),
        Validators.maxLength(30),
      ],
    ],
    email: ['', [Validators.email, Validators.required]],
    password: ['', Validators.required],
    confirmPassword: ['', Validators.required],
  });
  // registerUser() {}
  changePasswordVisibility(event: MouseEvent) {
    this.passwordHide = !this.passwordHide;
    event.stopPropagation();
  }
  changeCPasswordVisibility(event: MouseEvent) {
    this.cPasswordHide = !this.cPasswordHide;
    event.stopPropagation();
  }
  submitUserData() {
    if (this.userRegistration.valid) {
      const newUser: registerUserType = {
        name: this.userRegistration.value.name!,
        email: this.userRegistration.value.email!,
        password: this.userRegistration.value.password!,
        confirmPassword: this.userRegistration.value.confirmPassword!,
      };

      this.userService.registerUser(newUser).subscribe({
        next: (data) => {
          this.router.navigate(['/']);
          this.commonService.userLoggedIn.emit(true);
          // console.log("User Registered successfully");
          this.toaster.success({
            detail: 'SUCCESS',
            summary: 'User Registered successfully',
            duration: 3000,
          });
          // console.log("User Registered successfully24");
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
