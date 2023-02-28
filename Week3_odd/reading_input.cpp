#include <iostream>
using namespace std;

int main() {
    double user_input,total,average;
    int count = 0;

//A while loop to run input until a -1 is entered

while(true) {
    cin >> user_input;
    
    if(user_input == -1) {
        break;
    }
    
    total += user_input;
    count++;
}

average = total/count;

cout << average << endl;

return 0;

}
