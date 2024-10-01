#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    // Dynamically allocate memory for n GPA values
    float *gpa = new float[n];

    // Input GPA values for n students
    cout << "Enter the GPA of " << n << " students:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> gpa[i];
    }

    // Display GPA of each student
    cout << "GPA of the students:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Student " << (i + 1) << ": " << gpa[i] << endl;
    }

    // Deallocate the dynamically allocated memory
    delete[] gpa;

    // Display GPA after deletion
    cout << "GPA after deletion:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Student " << (i + 1) << ": " << gpa[i] << endl;
    }

    // Assign null to the pointer
    gpa = nullptr;

    // Display GPA after assigning null
    cout << "GPA after assigning null:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Student " << (i + 1) << ": " << gpa[i] << endl;
    }

    return 0;
}
