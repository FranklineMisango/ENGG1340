#include <iostream>
#include <cstdlib>
using namespace std;


int factorial(int num)
{
    if (num ==0)
    {
        return 1;
    }
    else
    {
        return num * factorial (num - 1);
    }
}
int main()
{
    int n;
    cout << "Enter the n you need factorial for  : " << endl;
    cin >> n ;
    cout << "The answer is : " << factorial(n) <<endl;
    return 0;

}