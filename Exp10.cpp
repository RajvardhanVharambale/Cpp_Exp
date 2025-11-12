#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
};

class Circle : public Shape {
    double r;
public:
    Circle(double radius) : r(radius) {}
    double area() { return M_PI * r * r; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double width, double height) : w(width), h(height) {}
    double area() { return w * h; }
};

int main() {
    Shape* s;
    Circle c(5);
    Rectangle r(4, 6);

    s = &c;
    cout << "Circle area: " << s->area() << endl;

    s = &r;
    cout << "Rectangle area: " << s->area() << endl;

    return 0;
}
