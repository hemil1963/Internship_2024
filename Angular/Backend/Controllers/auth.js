import jwt from "jsonwebtoken";
import { User } from "../models/UserModel.js";
// this function will check that the user trying to access private
// routes is a valid user or not
export const isAuthenticated = async (req, res, next) => {
  try {
    // trying to extract token from request
    const token = req.cookies.token || req.body.token;
    // if token not found then throw error
    if (!token) {
      return res.status(400).json({
        message: "Login first to access the resources",
      });
    }
    // if token is present then verify it using jwt.verify
    const decoded = jwt.verify(token, process.env.JWT_SECRET);
    //if token is not a valid token then again throw error
    if (!decoded) {
      return res.status(400).json({
        message: "Login first to access the resources",
      });
    }
    //extract id from decoded token
    const id = decoded.id;
    //find user on the basis of id extracted above
    const user = await User.findOne({ _id: id });
    //if user not exist of particular id then return failed response from here
    if (!user) {
      return res.status(400).json({
        message: "Login first to access the resources",
      });
    }
    // now add the user in the request
    req.user = user;
    // call the next controller
    next();
  } catch (error) {
    //throw error in response
    console.error(error);
    return res.status(500).json({
      message: "An error occurred while authenticating",
    });
  }
};
