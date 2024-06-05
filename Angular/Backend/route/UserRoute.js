import express from "express";
import {
  getUserDetails,
  logOutUser,
  login,
  signup,
} from "../controllers/UserController.js";
import { isAuthenticated } from "../controllers/auth.js";
const app = express.Router();
app.post("/signup", signup);
app.post("/login", login);
app.get("/logout", logOutUser);
app.get("/getUserDetails", isAuthenticated, getUserDetails);
export default app;
