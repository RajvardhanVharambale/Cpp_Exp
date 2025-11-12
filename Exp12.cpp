#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Writing to file
    ofstream out("data.txt");
    cout << "Enter some text: ";
    string text;
    getline(cin, text);
    out << text;
    out.close();

    // Reading from file
    ifstream in("data.txt");
    string input;
    getline(in, input);
    cout << "Text read from file: " << input << endl;
    in.close();

    return 0;
}
