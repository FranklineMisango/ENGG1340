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

void swap(int &a, int &b)
{
    //simple swap
    int tmp = a;
    a = b;
    b = tmp;
}

void selection_sort(int a[], int size)
{
    int i,j;
    int min_value;
    int id_of_min_value;

    //The i-th iteration
    for (i = 0; i < size - 1; i++)
    {
        //initialize the min_value and slot_id in each iteration
        min_value = a[i];
        id_of_min_value = i;

        //Finding the minimum in the i-th iteration
        for (j = i; j < size ; j++)
        {
            if (a[j] < min_value)
            {
                min_value = a[j];
                id_of_min_value = j;
            }
        }
        swap(a[i], a[id_of_min_value]);
    }
}

int main()
{
    const int size = 5;
    int score[size] = {80,100,63,70,52};

    cout << "Original array: " << endl;
    print_array(score , size);

    selection_sort(score,size);
    
    cout << "The sorted array is : " << endl;
    print_array(score,size);

    return 0;
}
