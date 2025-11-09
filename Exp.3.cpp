#include <iostream>
using namespace std;

class Account {
protected:
    string name;
    long accNum;
    double balance;
public:
    void create(string n, long a, double b) {
        name = n;
        accNum = a;
        balance = b;
    }
    void deposit(double amt) {
        balance += amt;
    }
    void withdraw(double amt) {
        if (amt > balance)
            cout << "Insufficient funds!" << endl;
        else
            balance -= amt;
    }
    void statement() {
        cout << "Account Statement:\n";
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accNum << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
    // Add savings-specific logic if needed
};

class CheckingAccount : public Account {
    // Add checking-specific logic if needed
};

int main() {
    SavingsAccount s;
    string n; long a; double b;
    cout << "Creating Savings Account...\nEnter Name: ";
    getline(cin, n);
    cout << "Enter Account Number: "; cin >> a;
    cout << "Enter Initial Balance: "; cin >> b;
    s.create(n, a, b);

    s.deposit(1000);
    s.withdraw(500);

    s.statement();

    return 0;
}
