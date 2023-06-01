#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

//Program that reads integers, prints quotient and remainder when divided by b

int main()
{
    int x;
    int y;
    cin >> x >> y ;
    cout << "quotient = " << x / y <<" and remainder = " << x % y << endl;
    return 0;
}