#include <iostream>

using namespace std;

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {4, 2, 7, 1, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int target = 8;
    
    int result = linear_search(arr, size, target);
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << "." << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }
    
    return 0;
}

