#include <iostream>
#include "d2boh.h"
using namespace std;

//Input 1 : mode
//Input 2 : Decimal mode

int main() {
    int mode, num_digits, input;
    cin >> mode;
    cin >> input;

    if (input == 0) {
        cout << "0" << endl;
        return 0;
    }

    int output_int[12];
    char output_char[12];

    if (mode == 2) {
        num_digits = decimal_to_binary(input, output_int);
        for (int i = num_digits - 1; i >= 0; i--) {
            cout << output_int[i];
        }
    }
    else if (mode == 8) {
        num_digits = decimal_to_octal(input, output_int);
        for (int i = num_digits - 1; i >= 0; i--) {
            cout << output_int[i];
        }
    }
    else if (mode == 16) {
        num_digits = decimal_to_hexadecimal(input, output_char);
        for (int i = num_digits - 1; i >= 0; i--) {
            cout << output_char[i];
        }
    }
    else {
        cout << "Invalid mode" << endl;
        return 1;
    }

    cout << endl;
    return 0;
}
