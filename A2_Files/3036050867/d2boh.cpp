#include <iostream>
#include "d2boh.h"
using namespace std;

int decimal_to_binary(int input, int output[12]) {
	//Implemented
    int index = 0;
    while (input > 0 && index < 12) {
        output[index] = input % 2;
        input /= 2;
        index++;
    }
    return index;
}

int decimal_to_octal(int input, int output[12]) {
	//Implemented
    int index = 0;
    while (input > 0 && index < 12) {
        output[index] = input % 8;
        input /= 8;
        index++;
    }
    return index;
}

int decimal_to_hexadecimal(int input, char output[12]) {
	//Implemented
    int index = 0;
    while (input > 0 && index < 12) {
        int rem = input % 16;
        if (rem < 10) {
            output[index] = rem + '0';
        }
        else {
            output[index] = rem - 10 + 'A';
        }
        input /= 16;
        index++;
    }
    return index;
}
