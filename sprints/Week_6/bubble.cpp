#include <iostream>
#include <cstdlib>
#include <cstdio>

//simple search algorithm
using namespace std;

void print_array(int a[], int size)
{
    //simple printing the contents of the array
    int i;
    for (i = 0; i < size; i++)
    {
        cout << a[i] << " " ;
    }
    cout << endl;
}
//The bubble sort

void bubble_sort(int a[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for (int j = 0 ; j < size -1 - i;j++)
        {
            if(a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}



int main()
{
    const int size = 5;
    int score[size] = {5,3,4,1,2};

    cout << "Original array: " << endl;
    print_array(score , size);

    bubble_sort(score,size);
    
    cout << "The sorted array is : " << endl;
    print_array(score,size);

    return 0;
}
