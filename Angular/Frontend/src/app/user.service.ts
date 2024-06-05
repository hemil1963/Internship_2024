import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Router } from '@angular/router';
import { loginUserType, registerUserType } from '../types/userTypes';

@Injectable({
  providedIn: 'root',
})
export class UserService {
  constructor(private http: HttpClient, private router: Router) {}

  registerUser(userData: registerUserType) {
    return this.http.post(
      'http://localhost:3000/api/v1/signup',
      userData,
      {
        headers: new HttpHeaders({
          'Content-Type': 'application/json',
        }),
        observe: 'response',
        withCredentials: true,
      }
    );
  }

  loginUser(loginData: loginUserType) {
    return this.http.post(
      'http://localhost:3000/api/v1/login',
      loginData,
      {
        headers: new HttpHeaders({
          'Content-Type': 'application/json',
        }),
        observe: 'response',
        withCredentials: true,
      }
    );
  }

  getUserData() {
    return this.http.get('http://localhost:3000/api/v1/getUserDetails', {
      withCredentials: true,
    });
  }

  logoutUser() {
    return this.http.get('http://localhost:3000/api/v1/logout', {
      withCredentials: true,
    });
  }
}
