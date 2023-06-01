#include <iostream>

using namespace std;

bool match(string& str, string& pattern, int pos) {
    for (int i = 0; i < pattern.length(); i++) {
        if (pos + i >= str.length() || str[pos + i] != pattern[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string input1, input2, input3;
    getline(cin, input1);
    cin >> input2 >> input3;

    string result;
    int start = 0;
    while (start < input1.length()) {
        int end = start;
        while (end < input1.length() && !match(input1, input2, end)) {
            end++;
        }
        result += input1.substr(start, end - start);
        if (end < input1.length()) {
            result += input3;
            end += input2.length();
        }
        start = end;
    }

    cout << result << endl;
    return 0;
}
