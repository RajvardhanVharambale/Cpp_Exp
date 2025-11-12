#include <iostream>
#include <exception>
using namespace std;

class InvalidAgeException : public exception {
    const char* what() const throw() { return "Invalid age entered!"; }
};

int divide(int a, int b) {
    if (b == 0) throw "Division by zero!";
    return a / b;
}

void validateAge(int age) {
    if (age < 0 || age > 150) throw InvalidAgeException();
}

int main() {
    // Division by zero
    try {
        cout << divide(10, 0) << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }

    // InvalidAgeException
    try {
        validateAge(200);
    } catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
