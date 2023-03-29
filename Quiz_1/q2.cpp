#include <iostream>
using namespace std;

int reverse(int Number) 
{
    int reversed_value = 0;
    while (Number != 0)
    {
        reversed_value = reversed_value * 10 + Number % 10 ;
        Number /= 10;
    }

    return -reversed_value;
}
int main() {
    int N;
    cin >> N;
    cout << reverse(N) << endl;
    return 0;
}
