#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

//Finding the errors and correcting the output
int main()
{
    int a1, a2, a3, a4, test, exam, average;
    double a_weight, test_weight = 0.2;
    double exam_Weight = 0.6;
    cout << "a1: ";
    cin >> a1;
    cout << "a2: ";
    cin >> a2;
    cout << "a3: ";
    cin >> a3;
    cout << "a4: ";
    cin >> a4;
    cout << "Test: ";
    cin >> test;
    cout << "Exam: ";
    cin >> exam;
    average = (a1+a2+a3+a4) / 4;
    average *= a_weight+test*test_weight+exam*exam_Weight;
    cout << "Average: " << average <<endl;
}


