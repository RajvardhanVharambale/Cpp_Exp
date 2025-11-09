#include <iostream>
using namespace std;

class AreaCalc {
public:
    double area(double r) { // Circle
        return 3.14159 * r * r;
    }
    double area(double l, double w) { // Rectangle
        return l * w;
    }
    double area(double b, double h, bool triangle) { // Triangle
        if(triangle)
            return 0.5 * b * h;
        else
            return 0.0;
    }
};

int main() {
    AreaCalc ac;
    double r, l, w, b, h;
    cout << "Enter radius for circle: ";
    cin >> r;
    cout << "Circle Area: " << ac.area(r) << endl;

    cout << "Enter length and width for rectangle: ";
    cin >> l >> w;
    cout << "Rectangle Area: " << ac.area(l, w) << endl;

    cout << "Enter base and height for triangle: ";
    cin >> b >> h;
    cout << "Triangle Area: " << ac.area(b, h, true) << endl;

    return 0;
}
