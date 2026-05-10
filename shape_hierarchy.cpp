#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
using namespace std;

const double PI = 3.14159265358979;

// Abstract base class
class Shape {
public:
    virtual double area()      = 0;
    virtual double perimeter() = 0;
    virtual string name()      = 0;
    virtual ~Shape() {}

    void display() {
        cout << name() << ":\n";
        cout << "  Area      : " << area() << "\n";
        cout << "  Perimeter : " << perimeter() << "\n";
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area()      override { return PI * radius * radius; }
    double perimeter() override { return 2 * PI * radius; }
    string name()      override { return "Circle (r=" + to_string(radius) + ")"; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area()      override { return width * height; }
    double perimeter() override { return 2 * (width + height); }
    string name()      override { return "Rectangle (" + to_string(width) + "x" + to_string(height) + ")"; }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
    double area() override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s-a) * (s-b) * (s-c));
    }
    double perimeter() override { return a + b + c; }
    string name()      override { return "Triangle (" + to_string(a) + "," + to_string(b) + "," + to_string(c) + ")"; }
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double area()      override { return side * side; }
    double perimeter() override { return 4 * side; }
    string name()      override { return "Square (s=" + to_string(side) + ")"; }
};

int main() {
    vector<unique_ptr<Shape>> shapes;

    shapes.push_back(make_unique<Circle>(5));
    shapes.push_back(make_unique<Rectangle>(4, 6));
    shapes.push_back(make_unique<Triangle>(3, 4, 5));
    shapes.push_back(make_unique<Square>(7));

    cout << "=== Shape Hierarchy ===\n\n";
    for (auto& s : shapes) {
        s->display();
        cout << "\n";
    }

    // Find largest area
    double maxArea = 0;
    string largest;
    for (auto& s : shapes) {
        if (s->area() > maxArea) {
            maxArea = s->area();
            largest = s->name();
        }
    }
    cout << "Largest area: " << largest << " (" << maxArea << ")\n";

    return 0;
}