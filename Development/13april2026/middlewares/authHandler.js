const express = require("express");
const jwt = require("jsonwebtoken");

const validateUser = (req, res, next) => {
  const token = req.cookies?.authorization;
  if (!token) res.status(400).json({ success: false, message: "Unauthorized" });
  try {
    const decode = jwt.verify(token, process.env.JWT_SECRET);
    req.user = decoded;
    next();
  } catch (error) {
    res.status(400).json({ success: false, message: "Unauthorized" });
    return;
  }
};
