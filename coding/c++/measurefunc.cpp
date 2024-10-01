#include <iostream>

using namespace std;

const double GALLONS_TO_CUBIC_FEET = 7.481;

double convert_gallons_to_cubic_feet(double gallons) {
    return gallons / GALLONS_TO_CUBIC_FEET;
}

int main() {
    double gallons;
    
    // Ask the user to enter the number of gallons
    cout << "Enter the number of gallons: ";
    cin >> gallons;
    
    // Convert gallons to cubic feet
    double cubic_feet = convert_gallons_to_cubic_feet(gallons);
    
    // Display the equivalent in cubic feet
    cout << gallons << " gallons is equivalent to " << cubic_feet << " cubic feet." << endl;
    
    return 0;
}
