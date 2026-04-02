// ===== SHARED CART SYSTEM =====

let cart = JSON.parse(localStorage.getItem("cart")) || [];

function saveCart() {
  localStorage.setItem("cart", JSON.stringify(cart));
}

function addToCart(name, price) {

  cart.push({ name, price });

  saveCart();
  updateCartDisplay();

  alert(name + " added to cart!");
}

function updateCartDisplay() {

  let total = cart.reduce((sum, item) => sum + item.price, 0);

  let display = document.getElementById("cartTotal");

  if (display) display.innerText = total;
}

// Cart popup
function showCart() {

  if (cart.length === 0) {
    alert("Cart is empty!");
    return;
  }

  let message = "🛒 Your Cart:\n\n";
  let total = 0;

  cart.forEach(item => {
    message += item.name + " — ₹" + item.price + "\n";
    total += item.price;
  });

  message += "\nTotal: ₹" + total;

  alert(message);
}

// Checkout → go to login/bill page
function goToCheckout() {
  window.location.href = "checkout.html";
}

// Clear cart after purchase
function clearCart() {
  cart = [];
  saveCart();
  updateCartDisplay();
}

// Always update when page loads
updateCartDisplay();
