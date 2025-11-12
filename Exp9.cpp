#include <iostream>
using namespace std;

class Item {
    int price;
public:
    Item(int p=0) : price(p) {}

    friend ostream& operator<<(ostream& out, const Item& i);
    friend istream& operator>>(istream& in, Item& i);
};

ostream& operator<<(ostream& out, const Item& i) {
    out << "Price: " << i.price;
    return out;
}

istream& operator>>(istream& in, Item& i) {
    in >> i.price;
    return in;
}

int main() {
    Item i;
    cout << "Enter price: ";
    cin >> i;
    cout << i << endl;
    return 0;
}
