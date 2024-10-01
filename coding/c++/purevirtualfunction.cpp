#include <iostream>
#include <cmath>

// Base class Shape
class Shape {
public:
    virtual double calculateArea() = 0; // Pure virtual function
    virtual void displayInfo() = 0;     // Pure virtual function
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() {
        return M_PI * radius * radius; // Area of a circle
    }

    void displayInfo() {
        std::cout << "Circle - Radius: " << radius << ", Area: " << calculateArea() << std::endl;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() {
        return length * width; // Area of a rectangle
    }

    void displayInfo() {
        std::cout << "Rectangle - Length: " << length << ", Width: " << width << ", Area: " << calculateArea() << std::endl;
    }
};

// Derived class Triangle
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double calculateArea() {
        return 0.5 * base * height; // Area of a triangle
    }

    void displayInfo() {
        std::cout << "Triangle - Base: " << base << ", Height: " << height << ", Area: " << calculateArea() << std::endl;
    }
};

int main() {
    // Creating objects of each shape
    Circle circle(5);
    Rectangle rectangle(4, 6);
    Triangle triangle(3, 8);

    // Demonstrating polymorphism
    circle.displayInfo();
    rectangle.displayInfo();
    triangle.displayInfo();

    // Using pointers for both base and derived classes
    Shape* shapes[] = {&circle, &rectangle, &triangle};
    for (Shape* shape : shapes) {
        shape->displayInfo();
    }

    return 0;
}
