#include <iostream>
#include <cstdlib>
using namespace std;

//The function should output the slot ID that contains the student values
//Output -1 if not found
int search(int array[], int variable)
{
    if(array[variable])
    {
        cout << array[variable] <<endl;
    }
    else
    {
        cout << "Output not found" <<endl;
    }
    return 0;
}
int main()
{
    int student_ids[5] = { 526172, 569078, 850039, 123456, 854489 };
    double scores[5] = {95.5, 100, 98.5, 99.5, 100};
    int input_id;
    cout << "Please input a student ID: ";
    cin >> input_id;
    int index;
    index = search(student_ids, input_id);
    if ( index != -1)
    {
        cout << "The score of " << input_id << " is: " << scores[index] << endl;
    }else{
    cout << "Sorry, no student with student ID " << input_id << " is found! " << endl;
        }
return 0;
}

