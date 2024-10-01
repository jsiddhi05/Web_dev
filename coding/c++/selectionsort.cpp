#include <iostream>
using namespace std;

// Function to perform selection sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Swap arr[i] and arr[minIndex]
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to print the sorted array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
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

    // Perform selection sort
    selectionSort(arr, size);

    cout << "Sorted array in ascending order: ";
    printArray(arr, size);

    return 0;
}
