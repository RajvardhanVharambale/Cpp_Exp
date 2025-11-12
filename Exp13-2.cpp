// C++ program to demonstrate the use of try, catch, and throw in exception handling.
#include <iostream>
using namespace std;

double division(int a, int b) {
    if (b == 0) {
        throw "Division by zero condition!";
    }
    return static_cast<double>(a) / b; // ensure floating-point division
}

int main() {
    int x = 50;
    int y = 0;
    double z = 0;

    try {
        z = division(x, y);
        cout << z << endl;
    } 
    catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}