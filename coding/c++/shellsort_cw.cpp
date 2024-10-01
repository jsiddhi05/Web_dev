#include<iostream>
using namespace std;

void shellSort(int a[], int n) {
    int gap = n / 2; // Initialize gap

    while (gap >= 1) {
        for (int j = gap; j < n; j++) { // Start j from gap, not 0
            for (int i = j - gap; i >= 0; i -= gap) {
                if (a[i + gap] > a[i]) {
                    break;
                } else {
                    int temp = a[i + gap];
                    a[i + gap] = a[i];
                    a[i] = temp;
                }
            }
        }
        gap = gap / 2;
    }
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int a[n]; // Declare array with size n

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    shellSort(a, n);
    cout << "Sorted array: ";
    print(a, n);

    return 0;
}
