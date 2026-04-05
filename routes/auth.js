const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const passport = require('passport');
const User = require('../models/User');

// Login page
router.get('/login', (req, res) => {
  if (req.isAuthenticated()) return res.redirect('/');
  res.render('login', { title: 'Login | Travel World' });
});

// Register page
router.get('/register', (req, res) => {
  if (req.isAuthenticated()) return res.redirect('/');
  res.render('register', { title: 'Register | Travel World' });
});

// Register POST
router.post('/register', async (req, res) => {
  const { name, email, password, password2 } = req.body;
  let errors = [];

  if (!name || !email || !password || !password2) errors.push({ msg: 'Please fill in all fields' });
  if (password !== password2) errors.push({ msg: 'Passwords do not match' });
  if (password && password.length < 6) errors.push({ msg: 'Password must be at least 6 characters' });

  if (errors.length > 0) {
    return res.render('register', { title: 'Register | Travel World', errors, name, email });
  }

  try {
    const existingUser = await User.findOne({ email });
    if (existingUser) {
      errors.push({ msg: 'Email is already registered' });
      return res.render('register', { title: 'Register | Travel World', errors, name, email });
    }

    const salt = await bcrypt.genSalt(10);
    const hashedPassword = await bcrypt.hash(password, salt);

    const newUser = new User({ name, email, password: hashedPassword });
    await newUser.save();

    req.flash('success_msg', 'Registration successful! Please log in.');
    res.redirect('/auth/login');
  } catch (err) {
    console.error(err);
    res.render('register', { title: 'Register | Travel World', errors: [{ msg: 'Server error, please try again' }] });
  }
});

// Login POST
router.post('/login', (req, res, next) => {
  passport.authenticate('local', {
    successRedirect: '/',
    failureRedirect: '/auth/login',
    failureFlash: true
  })(req, res, next);
});

// Logout
router.get('/logout', (req, res, next) => {
  req.logout(err => {
    if (err) return next(err);
    req.flash('success_msg', 'You have been logged out');
    res.redirect('/auth/login');
  });
});

module.exports = router;
