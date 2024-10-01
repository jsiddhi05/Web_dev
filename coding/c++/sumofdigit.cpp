#include <iostream>
using namespace std;

// Function to calculate the sum of individual digits
int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (num <= 0) {
        cout << "Invalid input! Please enter a positive integer." << endl;
        return 1;
    }

    int sum = sumOfDigits(num);
    cout << "Sum of individual digits of " << num << " is: " << sum << endl;

    return 0;
}
