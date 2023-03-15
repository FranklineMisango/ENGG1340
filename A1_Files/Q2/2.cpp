#include <iostream>
using namespace std;

//checks whether a number is a composite using a division by error method
//basically if it has any other factor rather than one and itself
bool checkComposite(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return true;
    }
    return false;
}

//main
int main() {
    int num_1, num_2;
    cin >> num_1 >> num_2;
    bool first = true; 
    for (int i = num_1; i <= num_2; i++) {
        if (checkComposite(i)) {
            if (!first) {
                cout << "\n"; 
            }
            cout << i;
            first = false; 
        }
    }
    cout << endl;
    return 0;
}
