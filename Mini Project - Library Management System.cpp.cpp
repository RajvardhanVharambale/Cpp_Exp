#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class Storage
{
public:
    T data[100];
    int count;

    Storage()
    {
        count = 0;
    }

    void addItem(T item)
    {
        if (count < 100)
        {
            data[count++] = item;
            cout << "Item added" << endl;
        }
        else
        {
            cout << "Storage full" << endl;
        }
    }

    void displayAll()
    {
        if (count == 0)
        {
            cout << "No items" << endl;
        }
        else
        {
            for (int i = 0; i < count; i++)
            {
                cout << "Item " << i + 1 << endl;
                cout << data[i] << endl;
            }
        }
    }
};

class Book
{
public:
    int id;
    string title;
    string author;
    int issued;
    string issuedTo;

    void inputDetails()
    {
        cout << "Enter Book ID: ";
        cin >> id;
        cout << "Enter Title: ";
        cin >> title;
        cout << "Enter Author: ";
        cin >> author;
        issued = 0;
        issuedTo = "None";
    }

    void displayDetails()
    {
        cout << "Book ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        if (issued)
        {
            cout << "Issued: Yes" << endl;
        }
        else
        {
            cout << "Issued: No" << endl;
        }
        if (issued)
        {
            cout << "Issued To: " << issuedTo << endl;
        }
    }

    void saveToFile()
    {
        ofstream fout("books.txt", ios::app);
        fout << id << " " << title << " " << author << " " << issued << " " << issuedTo << endl;
        fout.close();
    }

    void displayFromFile()
    {
        ifstream fin("books.txt");
        if (!fin)
        {
            cout << "No books available" << endl;
            return;
        }
        Book b;
        while (fin >> b.id >> b.title >> b.author >> b.issued)
        {
            if (!(fin >> b.issuedTo))
            {
                b.issuedTo = "None";
                fin.clear();
            }

            b.displayDetails();
            cout << endl;
        }
        fin.close();
    }

    void issueFromFile(int bookID)
    {
        Book arr[100];
        int n = 0;
        ifstream fin("books.txt");
        while (fin >> arr[n].id >> arr[n].title >> arr[n].author >> arr[n].issued >> arr[n].issuedTo)
        {
            n++;
        }
        fin.close();
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].id == bookID)
            {
                found = true;
                if (arr[i].issued == 1)
                {
                    cout << "Book already issued" << endl;
                }
                else
                {
                    string name;
                    cout << "Enter your name: ";
                    cin >> name;
                    arr[i].issued = 1;
                    arr[i].issuedTo = name;
                    cout << "Book issued successfully" << endl;
                }
            }
        }
        ofstream fout("books.txt");
        for (int i = 0; i < n; i++)
        {
            fout << arr[i].id << " " << arr[i].title << " " << arr[i].author << " " << arr[i].issued << " " << arr[i].issuedTo << endl;
        }
        fout.close();

        if (!found)
        {
            cout << "Book not found" << endl;
        }
    }

    void returnFromFile(int bookID)
    {
        Book arr[100];
        int n = 0;
        ifstream fin("books.txt");
        while (fin >> arr[n].id >> arr[n].title >> arr[n].author >> arr[n].issued>> arr[n].issuedTo)
        {
            n++;
        }
        fin.close();
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].id == bookID)
            {
                found = true;
                if (arr[i].issued == 0)
                {
                    cout << "Book was not issued" << endl;
                }
                else
                {
                    arr[i].issued = 0;
                    arr[i].issuedTo = "None";
                    cout << "Book returned successfully" << endl;
                }
            }
        }

        ofstream fout("books.txt");
        for (int i = 0; i < n; i++)
        {
            fout << arr[i].id << " " << arr[i].title << " " << arr[i].author << " "
                 << arr[i].issued << " " << arr[i].issuedTo << endl;
        }
        fout.close();

        if (!found)
            cout << "Book not found" << endl;
    }
};

class Library
{
    Storage<Book> books;
    Book bookObj;

public:
    void addBook()
    {
        Book b;
        b.inputDetails();
        b.saveToFile();
        books.addItem(b);
    }

    void viewBooks()
    {
        cout << "Book List:" << endl;
        bookObj.displayFromFile();
    }

    void issueBook()
    {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;
        bookObj.issueFromFile(id);
    }

    void returnBook()
    {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;
        bookObj.returnFromFile(id);
    }
};

int main()
{
    Library lib;
    int choice;

    do
    {
        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. View Books" << endl;
        cout << "3. Issue Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            lib.addBook();
            break;
        case 2:
            lib.viewBooks();
            break;
        case 3:
            lib.issueBook();
            break;
        case 4:
            lib.returnBook();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 5);
    return 0;
}