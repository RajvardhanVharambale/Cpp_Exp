#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
public:
    void inputPerson() {
        cout << "Enter name: ";
        getline(cin, name);
    }
};

// Student class derived from Person
class Student : public Person {
protected:
    int roll;
public:
    void inputStudent() {
        cout << "Enter roll number: ";
        cin >> roll;
        cin.ignore();
    }
};

// Teacher class derived from Person
class Teacher : public Person {
protected:
    string subject;
public:
    void inputTeacher() {
        cout << "Enter subject: ";
        getline(cin, subject);
    }
};

// Derived class (TA) inheriting both Student and Teacher (Hybrid inheritance)
class TA : public Student, public Teacher {
public:
    void displayTA() {
        cout << "TA Name (Student): " << Student::name << ", Roll: " << roll << endl;
        cout << "TA Name (Teacher): " << Teacher::name << ", Subject: " << subject << endl;
    }
};

int main() {
    TA ta;
    cout << "Details as Student:\n";
    ta.Student::inputPerson();
    ta.inputStudent();
    cout << "Details as Teacher:\n";
    ta.Teacher::inputPerson();
    ta.inputTeacher();
    ta.displayTA();
    return 0;
}
