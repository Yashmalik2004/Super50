const express = require("express");
const jwt = require("jsonwebtoken");

const validateUser = (req, res, next) =>{
   const token = req.cookies?.authorization;
   if(!token) res.status(400).json({message:"Unauthorized"});

   const decode = jwt.verify(token, process.env.JWT_SECRET);
}