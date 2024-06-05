import express from "express";
import { connectDB } from "./config/database.js";
import userRoute from "./routes/UserRoute.js";
import cookieParser from "cookie-parser";
import bodyParser from "body-parser";
import dotenv from "dotenv";
import cors from "cors";

const app = express();


const result = dotenv.config({ path: ".env" });
if (result.error) {
  throw result.error;
}

connectDB();
const port = 3000;
const corsOptions = {
  origin: "http://localhost:4200",
  methods: ["GET", "POST", "PUT", "DELETE"],
  allwedHeaders: ["Content-Type", "Authorization"],
  credentials: true,
};

app.use(cors(corsOptions));
app.use(express.json());
app.use(cookieParser());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use("/api/v1", userRoute);
app.listen(port, () => {
  console.log(`App is listening at port number ${port}`);
});
