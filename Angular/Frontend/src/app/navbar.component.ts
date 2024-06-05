import { Component } from '@angular/core';
import { MatToolbarModule } from '@angular/material/toolbar';
import { MatButtonModule } from '@angular/material/button';
import { Router, RouterLink } from '@angular/router';
import { UserService } from '../services/user.service';
import { NgToastService } from 'ng-angular-popup';
import { CommonService } from '../services/common.service';

@Component({
  selector: 'app-navbar',
  standalone: true,
  imports: [MatToolbarModule, MatButtonModule, RouterLink],
  templateUrl: './navbar.component.html',
  styleUrl: './navbar.component.css',
})
export class NavbarComponent {
  isLoggedIn: boolean = false;

  constructor(
    private userService: UserService,
    private commonService: CommonService,
    private toaster: NgToastService,
    private router: Router
  ) {}

  ngOnInit(): void {
    this.isLoggedIn = this.commonService.isThereCookie();
    this.commonService.userLoggedIn.subscribe((result) => {
      this.isLoggedIn = result;
    });
  }

  logOutUser() {
    this.userService.logoutUser().subscribe({
      next: () => {
        console.log("In the Logout");
        
        this.isLoggedIn = false;
        this.router.navigate(['/login']);
        this.commonService.userLoggedIn.emit(false);
        this.toaster.success({
          detail: 'SUCCESS',
          summary: 'User logged out successfully',
          duration: 3000,
        });
      },
      error: (err) => {
        this.toaster.error({
          detail: 'ERROR',
          summary: 'Failed to log out',
          duration: 3000,
        });
      },
    });
  }
}
