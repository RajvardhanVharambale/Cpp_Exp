#include <iostream>
#include <string>
using namespace std;

// Student class
class Student {
protected:
    string name;
    int roll;
public:
    void inputStudent() {
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> roll;
        cin.ignore();
    }
};

// Faculty class
class Faculty {
protected:
    string facultyName;
public:
    void inputFaculty() {
        cout << "Enter Faculty Name: ";
        getline(cin, facultyName);
    }
};

// Multiple Inheritance
class EducationalInstitute : public Student, public Faculty {
    string institute;
public:
    void inputInstitute() {
        cout << "Enter Institute Name: ";
        getline(cin, institute);
    }
    void displayAll() {
        cout << "Institute: " << institute << "\nStudent: " << name << ", Roll: " << roll << "\nFaculty: " << facultyName << endl;
    }
};

int main() {
    EducationalInstitute ei;
    ei.inputInstitute();
    ei.inputStudent();
    ei.inputFaculty();
    ei.displayAll();
    return 0;
}
