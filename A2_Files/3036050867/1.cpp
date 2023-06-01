#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cardNums[13] = {0};
    for (int i = 0; i < n; i++) {
        string card;
        cin >> card;
        int num;
        if (isdigit(card[1])) {
            num = stoi(card.substr(1, 2));
        } else {
            num = card[1] - '0';
        }
        cardNums[num-1]++;
    }

    int totalPairs = 0;
    for (int i = 0; i < 13; i++) {
        if (cardNums[i] >= 2) {
            totalPairs += cardNums[i] / 2;
        }
    }

    cout << totalPairs << endl;
    return 0;
}
