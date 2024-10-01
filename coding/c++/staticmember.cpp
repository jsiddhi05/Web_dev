#include <iostream>
#include <string>

class Employee {
private:
    int id;
    std::string name;
    double salary;
    static int nextId;

public:
    // Constructor
    Employee(std::string empName, double empSalary) {
        id = nextId++;
        name = empName;
        salary = empSalary;
    }

    // Function to display employee details
    void displayDetails() {
        std::cout << "Employee ID: " << id << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Salary: " << salary << std::endl;
    }

    // Static function to get the next available employee ID
    static int getNextId() {
        return nextId;
    }
};

// Initialize static member
int Employee::nextId = 1;

int main() {
    // Creating employee objects
    Employee emp1("Kshitij", 50000);
    Employee emp2("Megha", 60000);

    // Displaying employee details
    std::cout << "Employee 1 Details:" << std::endl;
    emp1.displayDetails();
    std::cout << std::endl;

    std::cout << "Employee 2 Details:" << std::endl;
    emp2.displayDetails();
    std::cout << std::endl;

    // Getting the next available employee ID
    std::cout << "Next available employee ID: " << Employee::getNextId() << std::endl;

    return 0;
}
