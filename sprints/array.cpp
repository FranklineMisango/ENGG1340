#include <iostream>
#include <cstdio>
using namespace std;

//our aim is to create a new dynamic array
void dynamic_array(int &val)
{
    val = val * 10;
}

int main()
{
    int arr[3] = {1,2,3};
    dynamic_array(arr[1]);
    cout << "The new value of array is " << arr[1] <<endl;
    return 0;
}