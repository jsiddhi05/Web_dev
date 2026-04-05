const express = require('express');
const router = express.Router();
const Tour = require('../models/Tour');

// Home page
router.get('/', async (req, res) => {
  try {
    const featuredTours = await Tour.find({ featured: true }).limit(3);
    res.render('index', { title: 'Travel World - Explore the Globe', featuredTours });
  } catch (err) {
    res.render('index', { title: 'Travel World', featuredTours: [] });
  }
});

// About page
router.get('/about', (req, res) => {
  res.render('about', { title: 'About Us | Travel World' });
});

// Dashboard (protected)
router.get('/dashboard', (req, res) => {
  if (!req.isAuthenticated()) return res.redirect('/auth/login');
  res.render('dashboard', { title: 'My Dashboard | Travel World' });
});

module.exports = router;
