#include <iostream>
#include <string>
using namespace std;

// Student class (base)
class Student {
protected:
    string name;
    int roll;
public:
    void inputStudent() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> roll;
        cin.ignore();
    }
    void showStudent() {
        cout << "Name: " << name << "\nRoll: " << roll << endl;
    }
};

// Test class (derived from Student)
class Test : public Student {
protected:
    float marks1, marks2;
public:
    void inputTest() {
        cout << "Enter marks for Subject 1: ";
        cin >> marks1;
        cout << "Enter marks for Subject 2: ";
        cin >> marks2;
        cin.ignore();
    }
    void showTest() {
        cout << "Marks1: " << marks1 << " Marks2: " << marks2 << endl;
    }
};

// Result class (derived from Test)
class Result : public Test {
public:
    void display() {
        showStudent();
        showTest();
        float total = marks1 + marks2;
        cout << "Total Marks: " << total << endl;
    }
};

int main() {
    Result r;
    r.inputStudent();
    r.inputTest();
    r.display();
    return 0;
}
