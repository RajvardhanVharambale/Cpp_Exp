// C++ program to demonstrate the use of list containers
#include <iostream>
#include <list>
using namespace std;

int main() {
    // Defining a list
    list<int> gqList = {12, 45, 8, 6};

    // Display elements of the list
    for (auto i : gqList) {
        cout << i << ' ';
    }

    return 0;
}