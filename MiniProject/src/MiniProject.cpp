#include<iostream>
using namespace std;

class complex {
public:
    int x, y;

    complex() {
        x = 0;
        y = 0;
    }

    friend ostream &operator <<(ostream &cout, const complex &t) {
        cout << t.x << "+" << t.y << "i";
        return cout;
    }

    friend istream &operator >>(istream &cin, complex &t) {
        cout << "Enter real number: ";
        cin >> t.x;
        cout << "Enter imaginary number: ";
        cin >> t.y;
        return cin;
    }

    complex operator +(complex t) {
        complex temp;
        temp.x = x + t.x;
        temp.y = y + t.y;
        return temp;
    }

    complex operator *(complex c) {
        complex temp1;
        temp1.x = (x * c.x) - (y * c.y);
        temp1.y = (y * c.x) + (x * c.y);
        return temp1;
    }
};

int main() {
    complex c1, c2, c3, c4;

    cout << "Enter 1st complex number " << endl;
    cin >> c1;

    cout << "Enter 2nd complex number " << endl;
    cin >> c2;

    cout << "First number: " << c1 << endl;
    cout << "Second number: " << c2 << endl;

    c3 = c1 + c2;
    cout << "Addition is: " << c3 << endl;

    c4 = c1 * c2;
    cout << "Multiplication is: " << c4 << endl;

    return 0;
}
