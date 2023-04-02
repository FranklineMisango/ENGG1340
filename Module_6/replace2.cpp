#include <iostream>
#include <string>

using namespace std;

int main() {
    string input1, input2, input3;
    getline(cin, input1);
    cin >> input2 >> input3;

    string result;
    size_t start = 0;
    while (start < input1.length()) {
        size_t end = input1.find(input2, start);
        if (end == string::npos) {
            result += input1.substr(start);
            break;
        }
        result += input1.substr(start, end - start);
        result += input3;
        start = end + input2.length();
    }

    cout << result << endl;
    return 0;
}
