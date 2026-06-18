const express = require("express");
const jwt = require("jsonwebtoken");

const validateUser = (req, res, next) => {

  // const token = req.cookies?.authorization;
  // if (!token) res.status(400).json({ success: false, message: "Unauthorized" });
  // try {
  //   const decode = jwt.verify(token, process.env.JWT_SECRET);
  //   req.user = decoded;
  //   next();
  // } catch (err) {
  //   res.status(400).json({ success: false, message: "Unauthorized" });
  //   return;
  // }

  const {authorization} = req.cookies || {};
  if(!authorization){
    // throw new err("No cookies found in the request");
    return res.status(401).json({ success: false, message: "invalid token"});
  }
  const [_, token] = authorization.includes("Bearer%20")?authorization.split("%20"):authorization.split(" ");

  jwt.verify(token, process.env.JWT_SECRET, (err,data)=>{
    if(err){
      console.log("err in verifying token", err.message);
      return res.status(401).json({ success: false, message: "Unauthorized" });
    } else {
      console.log("Decoded data from token", data);
      req.user = data;
      next();
    }
  })
};

module.exports = {validateUser};
