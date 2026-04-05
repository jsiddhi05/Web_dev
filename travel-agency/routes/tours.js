const express = require('express');
const router = express.Router();
const Tour = require('../models/Tour');
const Booking = require('../models/Booking');
const { ensureAuthenticated } = require('../config/auth');

// All tours
router.get('/', async (req, res) => {
  try {
    const { category, search } = req.query;
    let query = {};
    if (category && category !== 'All') query.category = category;
    if (search) query.$or = [
      { name: new RegExp(search, 'i') },
      { destination: new RegExp(search, 'i') }
    ];
    const tours = await Tour.find(query);
    const categories = ['All', 'Adventure', 'Beach', 'Cultural', 'Wildlife', 'Mountain', 'City'];
    res.render('tours', { title: 'Tours | Travel World', tours, categories, selectedCategory: category || 'All', search: search || '' });
  } catch (err) {
    res.render('tours', { title: 'Tours | Travel World', tours: [], categories: [], selectedCategory: 'All', search: '' });
  }
});

// Single tour
router.get('/:id', async (req, res) => {
  try {
    const tour = await Tour.findById(req.params.id);
    if (!tour) { req.flash('error_msg', 'Tour not found'); return res.redirect('/tours'); }
    res.render('tour-detail', { title: `${tour.name} | Travel World`, tour });
  } catch (err) {
    res.redirect('/tours');
  }
});

// Book tour (POST)
router.post('/:id/book', ensureAuthenticated, async (req, res) => {
  try {
    const tour = await Tour.findById(req.params.id);
    if (!tour) { req.flash('error_msg', 'Tour not found'); return res.redirect('/tours'); }

    const { travelers, travelDate } = req.body;
    const totalPrice = tour.price * parseInt(travelers);

    const booking = new Booking({
      user: req.user._id,
      tour: tour._id,
      travelers: parseInt(travelers),
      travelDate: new Date(travelDate),
      totalPrice
    });
    await booking.save();

    req.flash('success_msg', `🎉 Booking confirmed for ${tour.name}! Total: $${totalPrice}`);
    res.redirect('/dashboard');
  } catch (err) {
    console.error(err);
    req.flash('error_msg', 'Booking failed, please try again');
    res.redirect(`/tours/${req.params.id}`);
  }
});

// Dashboard bookings
router.get('/user/bookings', ensureAuthenticated, async (req, res) => {
  try {
    const bookings = await Booking.find({ user: req.user._id }).populate('tour').sort('-createdAt');
    res.render('bookings', { title: 'My Bookings | Travel World', bookings });
  } catch (err) {
    res.render('bookings', { title: 'My Bookings | Travel World', bookings: [] });
  }
});

module.exports = router;
