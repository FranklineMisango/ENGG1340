#include <iostream>
using namespace std;

void g(int& k){
    static int num = 6;


    if (k % 2 == 0){
        num += 2;
        k = k + 6;
    }
    else{
        num -= 2;
        k = k - 6;
    }
    cout << num << ", " << k << endl;
}

int main(){
    int y = 9;
    int x = 7;
    int i = 0;


    while (i < 3){
        if (i % 2 == 0){
            g(x);
            i++;
        }
        else{
            g(y);
            i++;
        }
    }
}

