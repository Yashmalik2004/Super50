const bcrypt = require("bcryptjs");
const { User } = require("../../../models/usersSchema.js");

const signupController = async (req, res) => {
  try {
    const { email, password } = req.body;

    const existingUser = await User.findOne({ email });

    if (existingUser) {
      res.status(400).json({ message: "User already exists" });
      return;
    }

    const hashedPassword = await bcrypt.hash(password, 50);

    const newUser = await User.create({
      email,
      password: hashedPassword,
      runValidators: true,
    });

    res
      .status(201)
      .json({ message: "User created successfully", userId: newUser._id });
  } catch (error) {
    console.error("Signup Error:", error);
    res.status(500).json({ message: "Internal server error" });
  }
};

const loginController = async (req, res) => {
  // {email, password}
  // password --> hash (match)
  // token
  //    --> {email, userId} + secret --> token
  // send token in cookie
  try {
    const { email, password } = req.body;
    const existingUser = await User.findOne({ email });
    if (!existingUser) {
      return res.status(400).json({ message: "Invalid email or password" });
    }

    const isMatch = await bcrypt.compare(password, existingUser.password);

    if (!isMatch) {
      return res.status(400).json({ message: "Invalid email or password" });
    }

    // const token = jwt.sign(
    //   { userId: existingUser._id, email: existingUser.email },
    //   "secret",
    //   { expiresIn: "1h" },
    // );

    res.status(200).json({
      message: "Login successful",
    //   token,
    });
  } catch (error) {
    console.error("Signup Error:", error);
    res.status(500).json({ message: "Internal server error" });
  }
};

module.exports = { signupController, loginController };
