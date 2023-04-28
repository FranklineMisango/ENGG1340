#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int size;
    cout << "Enter the size of the set: ";
    cin >> size;

    int *set = new int[size];
    cout << "Enter the elements of the set:\n";
    for (int i = 0; i < size; ++i) {
        cin >> set[i];
    }

    unordered_map<int, int> freq_map;
    for (int i = 0; i < size; ++i) {
        ++freq_map[set[i]];
    }

    int mode = 0;
    int max_freq = 0;
    for (const auto &p : freq_map) {
        if (p.second > max_freq) {
            max_freq = p.second;
            mode = p.first;
        }
    }

    cout << "The mode of the set is: " << mode << endl;

    delete[] set;

    return 0;
}
