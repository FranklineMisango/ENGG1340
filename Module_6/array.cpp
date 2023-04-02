#include <iostream>
#include <math.h>
using namespace std;

int main(){
int num, currPos;
cin >> num;
int arr[15];

//initializing if num is more than or equal to 15
if (num >= 15){
    num = 15;
}

//powering first num
for (int i = 0; i < num; i++){
    arr[i] = i * i;
}
currPos = num;

if(currPos <= 10){
    for (int i = currPos; i < currPos + 5; i++){
        arr[i] = 0;
    }
    for (int i = currPos + 5; i < 15; i++){
        arr[i] = pow(3,i);
    }
} else if(currPos >= 10 && currPos < 15){
    for (int i = currPos; i < currPos + 5; i++){
        arr[i] = 0;
    }
}

//printing out the 15 values
for (int i = 0; i < 15; i++){
    cout << arr[i] << " ";
}

return 0;

}