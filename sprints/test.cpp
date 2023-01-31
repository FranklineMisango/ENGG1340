#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	//computing the root mean square of 10 input numbers
	
	int i;
	double n, sq_sum = 0;


	for (i = 0; i < 10; i++)
	{
		cout << i + 1 << ":";
		cin >> n;
		sq_sum += pow(n,2.0);

	}

	cout << "The root mean square is " << sqrt (sq_sum / 10 ) <<endl;

	return 0;

}
