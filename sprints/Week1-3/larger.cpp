#include <iostream>
using namespace std;

double larger (double x , double y);

int main()
{
	double a;
	double b;
	cout << "Enter two numbers " <<endl;
	cin >> a >> b ;

	double c = larger ( a , b);
	cout << "The larger number is : " << c << endl;

}
double larger (double x , double y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}
