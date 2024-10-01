#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int empID;
    string name;
    float salary;

public:
    // Default constructor
    Employee() : empID(0), name("John Doe"), salary(0.0) {}

    // Member function to set data
    void setData() {
        cout << "Enter employee ID: ";
        cin >> empID;
        cin.ignore(); // Ignore the newline character left in the input buffer
        cout << "Enter employee name: ";
        getline(cin, name);
        cout << "Enter employee salary: ";
        cin >> salary;
    }

    // Member function to display data
    void displayData() {
        cout << "Employee ID: " << empID << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: " << salary << endl;
    }

    // Member function to calculate salary based on performance rating
    float calculateSalary(float performanceRating) {
        return performanceRating * salary;
    }
};

int main() {
    Employee emp;

    // Set data for the employee
    emp.setData();

    // Display employee details
    cout << "\nEmployee Details:\n";
    emp.displayData();

    // Calculate salary based on performance rating
    float performanceRating;
    cout << "\nEnter performance rating (between 1 and 5): ";
    cin >> performanceRating;
    if (performanceRating < 1 || performanceRating > 5) {
        cout << "Invalid performance rating!\n";
    } else {
        float newSalary = emp.calculateSalary(performanceRating);
        cout << "New Salary based on performance rating: " << newSalary << endl;
    }

    return 0;
}
