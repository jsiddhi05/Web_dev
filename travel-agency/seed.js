const mongoose = require('mongoose');
const Tour = require('./models/Tour');
require('dotenv').config();

const tours = [
  {
    name: 'Bali Paradise Escape',
    destination: 'Bali, Indonesia',
    description: 'Experience the magical island of Bali with its stunning temples, terraced rice paddies, and vibrant culture. Enjoy world-class resorts, spiritual experiences, and breathtaking sunsets.',
    duration: '7 Days / 6 Nights',
    price: 1299,
    rating: 4.8,
    reviews: 234,
    image: 'https://images.unsplash.com/photo-1537996194471-e657df975ab4?w=800',
    category: 'Beach',
    highlights: ['Tanah Lot Temple at sunset', 'Ubud rice terraces walk', 'Traditional Kecak dance', 'Seminyak beach day'],
    included: ['Hotel accommodation', 'Daily breakfast', 'Airport transfers', 'Licensed guide'],
    featured: true
  },
  {
    name: 'Santorini Sunset Cruise',
    destination: 'Santorini, Greece',
    description: 'Sail the crystal-clear Aegean Sea and explore the iconic white-washed villages of Santorini. Watch the legendary sunset from Oia and savour authentic Greek cuisine.',
    duration: '5 Days / 4 Nights',
    price: 1899,
    rating: 4.9,
    reviews: 189,
    image: 'https://images.unsplash.com/photo-1570077188670-e3a8d69ac5ff?w=800',
    category: 'Beach',
    highlights: ['Caldera volcano hike', 'Wine tasting in Pyrgos', 'Perissa Black Beach', 'Oia sunset viewpoint'],
    included: ['Boutique hotel', 'Breakfast & dinner', 'Catamaran cruise', 'Wine tasting tour'],
    featured: true
  },
  {
    name: 'Machu Picchu Trek',
    destination: 'Cusco, Peru',
    description: 'Journey through the Inca Trail to the legendary lost city of Machu Picchu. Experience the stunning Andean landscapes and uncover the mysteries of the ancient Inca civilization.',
    duration: '8 Days / 7 Nights',
    price: 2199,
    rating: 4.7,
    reviews: 156,
    image: 'https://images.unsplash.com/photo-1526392060635-9d6019884377?w=800',
    category: 'Adventure',
    highlights: ['Inca Trail hiking', 'Sacred Valley exploration', 'Cusco city tour', 'Sun Gate sunrise'],
    included: ['Trek permits', 'Camping equipment', 'Meals on trek', 'Expert guide'],
    featured: true
  },
  {
    name: 'Safari in Serengeti',
    destination: 'Tanzania, Africa',
    description: 'Witness the Great Migration and explore the vast Serengeti plains. Encounter the Big Five in their natural habitat and experience authentic African bush life.',
    duration: '6 Days / 5 Nights',
    price: 3499,
    rating: 4.9,
    reviews: 98,
    image: 'https://images.unsplash.com/photo-1516426122078-c23e76319801?w=800',
    category: 'Wildlife',
    highlights: ['Great Migration viewing', 'Big Five game drives', 'Ngorongoro Crater', 'Maasai village visit'],
    included: ['Luxury tented camp', 'All meals', 'Game drives', 'Park fees'],
    featured: false
  },
  {
    name: 'Kyoto Cultural Immersion',
    destination: 'Kyoto, Japan',
    description: 'Discover the timeless beauty of Kyoto with its ancient temples, traditional tea houses, and stunning bamboo groves. Experience authentic Japanese culture in the heart of the ancient capital.',
    duration: '6 Days / 5 Nights',
    price: 1799,
    rating: 4.8,
    reviews: 212,
    image: 'https://images.unsplash.com/photo-1493976040374-85c8e12f0c0e?w=800',
    category: 'Cultural',
    highlights: ['Arashiyama bamboo grove', 'Fushimi Inari torii gates', 'Traditional tea ceremony', 'Geisha district walk'],
    included: ['Ryokan stay', 'Breakfast daily', 'JR Pass 3-day', 'Tea ceremony'],
    featured: false
  },
  {
    name: 'Swiss Alps Adventure',
    destination: 'Interlaken, Switzerland',
    description: 'Challenge yourself in the spectacular Swiss Alps with skiing, paragliding, and mountain hiking. Breathe in the crisp alpine air and soak in panoramic views of snow-capped peaks.',
    duration: '7 Days / 6 Nights',
    price: 2899,
    rating: 4.7,
    reviews: 143,
    image: 'https://images.unsplash.com/photo-1506905925346-21bda4d32df4?w=800',
    category: 'Mountain',
    highlights: ['Jungfraujoch excursion', 'Paragliding over Alps', 'Skiing in Grindelwald', 'Lauterbrunnen valley walk'],
    included: ['Chalet accommodation', 'Swiss Travel Pass', 'Ski rental', 'Paragliding flight'],
    featured: false
  }
];

async function seedDB() {
  try {
    await mongoose.connect(process.env.MONGO_URI);
    await Tour.deleteMany({});
    await Tour.insertMany(tours);
    console.log('Database seeded successfully!');
    process.exit(0);
  } catch (err) {
    console.error(err);
    process.exit(1);
  }
}

seedDB();
