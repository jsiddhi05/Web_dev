const mongoose = require('mongoose');

const TourSchema = new mongoose.Schema({
  name: { type: String, required: true },
  destination: { type: String, required: true },
  description: { type: String, required: true },
  duration: { type: String, required: true },
  price: { type: Number, required: true },
  rating: { type: Number, default: 4.5 },
  reviews: { type: Number, default: 0 },
  image: { type: String },
  category: { type: String, enum: ['Adventure', 'Beach', 'Cultural', 'Wildlife', 'Mountain', 'City'], default: 'Beach' },
  highlights: [String],
  included: [String],
  featured: { type: Boolean, default: false },
  createdAt: { type: Date, default: Date.now }
});

module.exports = mongoose.model('Tour', TourSchema);
