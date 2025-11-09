#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;
public:
    Rectangle(double l = 1, double w = 1) {
        length = l;
        width = w;
        cout << "Rectangle created" << endl;
    }
    ~Rectangle() {
        cout << "Rectangle destroyed" << endl;
    }
    double area() {
        return length * width;
    }
    double perimeter() {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle r(10, 5);
    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;
    return 0;
}
