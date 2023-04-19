#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    int nums[13] = {0};
    for (int i = 0; i < N; i++) {
        string card;
        cin >> card;
        int num;
        if (isdigit(card[1])) {
            num = stoi(card.substr(1, 2));
        } else {
            num = card[1] - '0';
        }
        nums[num-1]++;
    }

    int total_pairs = 0;
    for (int i = 0; i < 13; i++) {
        if (nums[i] >= 2) {
            total_pairs += nums[i] / 2;
        }
    }

    cout << total_pairs << endl;
    return 0;
}
