#include <iostream>
#include "gcd.h"
using namespace std;



int main(){
	int a,b,c;
	cout<<"Please input two positive numbers : "<<endl;
	cin >> a >> b;
	c = gcd(a,b);
	cout<<"The GCD is "<< c <<endl;
}
