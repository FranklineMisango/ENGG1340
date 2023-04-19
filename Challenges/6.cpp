#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

//Program that takes 3-digit number and ouputs the reverse of the digits
#include <iostream>
using namespace std;

int main() {
    int num, rev_num = 0, digit;

    cout << "Enter a three digit number: ";
    cin >> num;

    digit = num % 10;
    rev_num = (rev_num * 10) + digit;
     cout << "The value of digit is " <<  digit << endl;
    cout << "The value of num is " <<num << endl;
    cout << "The value of rev_num is " <<  rev_num << endl;

    num /= 10;
    digit = num % 10;
    rev_num = (rev_num * 10) + digit;
    cout << "The value of digit is " <<  digit << endl;
    cout << "The value of num is " <<num << endl;
    cout << "The value of rev_num is " <<  rev_num << endl;

    num /= 10;
    digit = num % 10;
    rev_num = (rev_num * 10) + digit;
    cout << "The value of digit is " <<  digit << endl;
    cout << "The value of num is " <<num << endl;
    cout << "The value of rev_num is " <<  rev_num << endl;

    cout << "The reverse of the number is: " << rev_num << endl;

    return 0;
}

