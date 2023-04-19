#include <iostream>
using namespace std;

void birthday(int age){
    age++;
}

int main(){
    int myAge;
    cin >> myAge;
    birthday(myAge);
    cout << "My age after birthday is " << myAge;
}
