#include <iostream>
#include <cstdlib>
#include <cstdio>

//simple search algorithm
using namespace std;

int search(int a[] , int input)
{
    //returns not found incase it aint
    int index = -1;

    for (int i = 0; i < 5 ; i++)
    {
        if (a[i] == input)
        {
            index = i;
            break;
        }
    }
    return index;
}
