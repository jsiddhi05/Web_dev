#include <iostream>
using namespace std;

// Function to find the largest number
int findLargest(int arr[], int size) {
    int largest = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}

// Function to find the smallest number
int findSmallest(int arr[], int size) {
    int smallest = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < smallest)
            smallest = arr[i];
    }
    return smallest;
}

int main() {
    int size;
    cout << "Enter the number of elements in the list: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid input! Number of elements should be greater than 0." << endl;
        return 1;
    }

    int arr[size];
    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    int largest = findLargest(arr, size);
    int smallest = findSmallest(arr, size);

    cout << "Largest number: " << largest << endl;
    cout << "Smallest number: " << smallest << endl;

    return 0;
}
