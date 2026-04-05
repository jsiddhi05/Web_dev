// Hamburger menu
const hamburger = document.getElementById('hamburger');
const navLinks = document.querySelector('.nav-links');
const navAuth = document.querySelector('.nav-auth');
if (hamburger) {
  hamburger.addEventListener('click', () => {
    navLinks && navLinks.classList.toggle('open');
    navAuth && navAuth.classList.toggle('open');
  });
}

// Auto-dismiss alerts
document.querySelectorAll('.alert').forEach(el => {
  setTimeout(() => el.style.display = 'none', 4000);
});

// Navbar scroll shadow
window.addEventListener('scroll', () => {
  const navbar = document.querySelector('.navbar');
  if (navbar) {
    navbar.style.boxShadow = window.scrollY > 10
      ? '0 4px 20px rgba(0,0,0,0.12)'
      : '0 2px 12px rgba(0,0,0,0.06)';
  }
});
