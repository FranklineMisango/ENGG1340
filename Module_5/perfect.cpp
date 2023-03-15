/*
   This program prints out the perfect numbers between 1 and N
*/

#include <iostream>
using namespace std;

const int N = 1000;
//The helper function
bool isPerfect(int number)
{
    int sum = 1; 
    for (int i = 2; i < number; ++i) {
        if (number % i == 0) {
            sum += i; 
        }
    }
    return sum == number; 
}

int main()
{
	cout << "For the integers from 1 to " << N << ":\n";

	for (int j = 2; j <= N; ++j)
		if (isPerfect(j))
			cout << j << " is perfect\n";

	cout << endl;

	return 0;
}