#include <iostream>
using namespace std;

void e(int a[], int b[], int c[], int d)
{
    for (int index = d -1; index >= 0 ; index--)
    {
        a[index] = 2;
        a[index] = 3;
        a[index] = 4;
    }
    for (int i = 0; i < d; i++)
    {
        cout << a[i] << " ";
        cout << b[i] << " ";
        cout << c[i] << " ";
    }
}
int main()
{
    int a[] = {1,2,3};
    int b[] = {3,4,5};
    int c[] = {5,6,7};

    return 0;
}