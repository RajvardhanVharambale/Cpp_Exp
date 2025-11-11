#include <iostream>
using namespace std;

class Number {
    int value;
public:
    Number(int v=0) : value(v) {}

    // Unary minus
    Number operator-() { return Number(-value); }

    // Binary +
    Number operator+(const Number& n) { return Number(value + n.value); }

    // Relational operator >
    bool operator>(const Number& n) { return value > n.value; }

    // Display value
    void show() { cout << "Value: " << value << endl; }
};

int main() {
    Number a(5), b(3);
    Number c = -a;   // unary
    c.show();
    Number d = a + b; // binary
    d.show();
    cout << (a > b ? "a > b" : "a <= b") << endl; // relational
    return 0;
}
