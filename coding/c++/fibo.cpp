#include <iostream>
using namespace std;

// Function to generate Fibonacci series and print the first n terms
void generateFibonacci(int n) {
    int first = 0, second = 1, nextTerm;
    
    cout << "Fibonacci Series: ";
    for (int i = 0; i < n; ++i) {
        if (i <= 1)
            nextTerm = i;
        else {
            nextTerm = first + second;
            first = second;
            second = nextTerm;
        }
        cout << nextTerm << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input! Number of terms should be greater than 0." << endl;
        return 1;
    }

    generateFibonacci(n);

    return 0;
}
