#include <iostream>
using namespace std;

char CaesarShift(char c, int k) {
    if (c >= 'A' && c <= 'Z') {
        int x = c - 'A';
        int y = (x + k) % 26;
        if (y < 0) y += 26;
        char w = y + 'a';
        return w;
    }
    else if (c >= 'a' && c <= 'z') {
        int x = c - 'a';
        int y = (x + k) % 26;
        if (y < 0) y += 26;
        char w = y + 'A';
        return w;
    }
    else {
        return c;
    }
}


int main() {
    char op, c;
    int k1, k2, k3, k;
    cin >> op >> k >> c;

    k1 = k / 10000;
    k2 = (k / 100) % 100;
    k3 = k % 100;

    int counter = 1;
    while (c != '!') {
        if (op == 'e') {
            if (counter % 3 == 1) {
                cout << CaesarShift(c, k1) << " ";
            }
            else if (counter % 3 == 2) {
                cout << CaesarShift(c, k2) << " ";
            }
            else {
                cout << CaesarShift(c, k3) << " ";
            }
        }
        else if (op == 'd') {
            if (counter % 3 == 1) {
                cout << CaesarShift(c, -k1) << " ";
            }
            else if (counter % 3 == 2) {
                cout << CaesarShift(c, -k2) << " ";
            }
            else {
                cout << CaesarShift(c, -k3) << " ";
            }
        }
        counter++;
        cin >> c;
    }
    cout << "! " << endl;

    return 0;
}
