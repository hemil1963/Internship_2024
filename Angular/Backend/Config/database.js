import mongoose from "mongoose";


// function used to connect with database
export const connectDB = () => {
  mongoose
    .connect("mongodb://localhost:27017", {
      dbName: "Angular_Auth_Assignment",
    })
    .then((c) => console.log(`Db connected to ${c.connection.host}`))
    .catch((e)=>console.log(`Error in connecting with DB`));
};
