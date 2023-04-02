#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int i;
    cin >> i;

    int arr[20];
    for (int j = 0; j < i && j < 15; j++) {
        arr[j] = j * j;
    }
    for (int j = i; j < 15; j++) {
        arr[j] = 0;
    }
    for (int j = 15; j < i + 5 && j < 20; j++) {
        arr[j] = pow(3, j - 15);
    }
    for (int j = i + 5; j < 20; j++) {
        arr[j] = pow(3, j - i - 2);
    }
    for (int j = 0; j < 20; j++) {
        if (j < 6) {
            cout << "0 ";
        } else {
            cout << arr[j] << " ";
        }
    }
    cout << endl;

    return 0;
}
