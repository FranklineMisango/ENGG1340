#include <iostream>
#include <cstdlib>
using namespace std;

int fib(int num)
{
    if (num < 2)
    {
        return num;
    }
    else
    {
        return fib(num - 1) + fib (num -2);
    }
}

int main()
{
    int num;
    cout << "Enter the number " << endl;
    cin >> num ;
    cout << "The fibonnaci sequence is : " << fib(num) << endl;
    return 0;
}