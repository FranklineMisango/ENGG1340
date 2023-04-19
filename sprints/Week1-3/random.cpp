#include <iostream>
using namespace std;

int main ()
{
	int num = 23;
	int guess;
	bool isGuessed;

	isGuessed = false;

	while (!isGuessed)
	{
		cout<<"Make a guess between 0 - 99 :  " <<endl;
		cin >> guess;
	if (guess == num) 
	{
		cout << "Your guess is correct " <<endl;
		isGuessed  = true;
	}
	else if (guess < num )
	{
		cout << "The guess is too small , try again ! " <<endl;
	}
	else
	{
		cout << "The guess is too large, Guess again" <<endl;
	}
	return 0;

	}
}

