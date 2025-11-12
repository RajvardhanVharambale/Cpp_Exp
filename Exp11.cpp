#include <iostream>
using namespace std;

class Employee {
public:
    virtual double calculateSalary() = 0;
};

class SalaryEmployee : public Employee {
    double monthlySalary;
public:
    SalaryEmployee(double s) : monthlySalary(s) {}
    double calculateSalary() { return monthlySalary; }
};

class HourlyEmployee : public Employee {
    double hours, rate;
public:
    HourlyEmployee(double h, double r) : hours(h), rate(r) {}
    double calculateSalary() { return hours * rate; }
};

class CommissionedEmployee : public Employee {
    double base, commission;
public:
    CommissionedEmployee(double b, double c) : base(b), commission(c) {}
    double calculateSalary() { return base + commission; }
};

int main() {
    SalaryEmployee se(50000);
    HourlyEmployee he(160, 200);
    CommissionedEmployee ce(30000, 12000);

    cout << "SalaryEmployee Salary: " << se.calculateSalary() << endl;
    cout << "HourlyEmployee Salary: " << he.calculateSalary() << endl;
    cout << "CommissionedEmployee Salary: " << ce.calculateSalary() << endl;

    return 0;
}
