#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;
public:
    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }
    void display() {
        cout << real;
        if (imag >= 0) cout << " + " << imag << "i" << endl;
        else cout << " - " << -imag << "i" << endl;
    }
    Complex add(Complex c2) {
        Complex temp;
        temp.real = real + c2.real;
        temp.imag = imag + c2.imag;
        return temp;
    }
    Complex subtract(Complex c2) {
        Complex temp;
        temp.real = real - c2.real;
        temp.imag = imag - c2.imag;
        return temp;
    }
};

int main() {
    Complex c1, c2, sum, diff;
    cout << "Enter first complex number\n";
    c1.input();
    cout << "Enter second complex number\n";
    c2.input();

    sum = c1.add(c2);
    diff = c1.subtract(c2);

    cout << "\nFirst Number: "; c1.display();
    cout << "Second Number: "; c2.display();
    cout << "Sum: "; sum.display();
    cout << "Difference: "; diff.display();

    return 0;
}
