#include <iostream>
#include <string>
using namespace std;

// Base Class
class LibraryItem {
protected:
    string title;
    int id;
public:
    void inputItem() {
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
    }
    void displayItem() {
        cout << "Title: " << title << " | ID: " << id << endl;
    }
};

// Derived Class - Book
class Book : public LibraryItem {
    string author;
public:
    void inputBook() {
        inputItem();
        cout << "Enter Author: ";
        getline(cin, author);
    }
    void displayBook() {
        displayItem();
        cout << "Author: " << author << endl;
    }
};

// Derived Class - Magazine
class Magazine : public LibraryItem {
    int issue;
public:
    void inputMagazine() {
        inputItem();
        cout << "Enter Issue Number: ";
        cin >> issue;
        cin.ignore();
    }
    void displayMagazine() {
        displayItem();
        cout << "Issue: " << issue << endl;
    }
};

int main() {
    Book b;
    Magazine m;
    cout << "--- Book ---\n";
    b.inputBook();
    b.displayBook();
    cout << "--- Magazine ---\n";
    m.inputMagazine();
    m.displayMagazine();
    return 0;
}
