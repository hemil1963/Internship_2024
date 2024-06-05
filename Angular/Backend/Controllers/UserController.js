import { User } from "../models/UserModel.js";
import bcrypt from "bcryptjs";
import jwt from "jsonwebtoken";

// function to register a new user
export const signup = async (req, res, next) => {
  try {
    // trying to extract fields from request's body
    const { name, email, password, confirmPassword } = req.body;
    //if any one of them is not preset then return unsuccessful response
    if (!email || !password || !name || !confirmPassword) {
      return res.status(403).json({
        success: false,
        message: "All fields are required",
      });
    }
    // now check if password and confirm password match or not 
    if (password !== confirmPassword) {
      return res.status(400).json({
        success: false,
        message:
          "Password and confirm password value does'not match,please try again..",
      });
    }
    //check if user is already present with following email
    const user = await User.findOne({ email });
    if (user) {
      return res.status(400).json({
        success: false,
        message: "User already exists..",
      });
    }
    const saltRounds = 10;
    //encrypting password using bcrypt
    const hashedPassword = await bcrypt.hash(password, saltRounds);
    //creating entry of user in database 
    const usr = await User.create({ email, password: hashedPassword, name });
    console.log("registered successfully 1234");
    
    return res.status(200).json({
      success: true,
      message: "User registered successfully..",
      usr,
    });
  } catch (error) {
    //return unsuccessful if there is any error
    console.log(error);
    return res.status(500).json({
      success: false,
      message: "User can'not be registered..",
    });
  }
};
//function for logging in the user
export const login = async (req, res, next) => {
  try {
    // console.log("Inside Login");
    const { email, password } = req.body;
    // console.log(email,password);
    if (!email || !password) {
      return res.status(403).json({
        success: false,
        message: "All fields are required",
      });
    }

    const user = await User.findOne({ email });

    if (!user) {
      return res.status(401).json({
        success: false,
        message: "Please register first then try to login...",
      });
    }

    if (await bcrypt.compare(password, user.password)) {
      const payload = { email: user.email, id: user._id, name: user.name };
      const token = jwt.sign(payload, process.env.JWT_SECRET, {
        expiresIn: "2h",
      });
      user.token = token;
      // console.log("token ---->",token);
      user.password = undefined;

      const options = {
        expires: new Date(Date.now() + 3 * 24 * 60 * 60 * 1000),
        httpOnly: false,
        secure: true,
        sameSite: "none",
      };

      return res.status(200).cookie("token", token, options).json({
        success: true,
        token,
        user,
        message: "Logged in successfully",
      });
    } else {
      return res.status(401).json({
        success: false,
        message: "Password is incorrect",
      });
    }
  } catch (error) {
    console.log(error);
    return res.status(500).json({
      success: false,
      message: "Failed to login please try again...",
    });
  }
};

export const logOutUser = (req, res, next) => {
  // console.log("Inside logout");
  return res
    .status(200)
    .cookie("token", null, {
      expires: new Date(Date.now()),
      httpOnly: true,
    })
    .json({
      success: true,
      message: "Logged out successfully",
    });
};

export const getUserDetails = (req, res, next) => {
  const { user } = req;
  console.log(user);
  return res.status(200).json({
    success: true,
    message: "Details fetched successfully",
    user,
  });
};
