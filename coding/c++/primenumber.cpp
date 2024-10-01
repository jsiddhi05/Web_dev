#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Function to generate and print all prime numbers between 1 and n
void generatePrimes(int n) {
    cout << "Prime numbers between 1 and " << n << " are:" << endl;
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i))
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input! Please enter a positive integer." << endl;
        return 1;
    }

    generatePrimes(n);

    return 0;
}
