#include <iostream>
#include <string>

using namespace std;

int main() {
    string input_string;
    getline(cin, input_string); // read a string with spaces

    // remove spaces and punctuation
    string stripped_string = "";
    for (char c : input_string) {
        if (isalpha(c)) {
            stripped_string += tolower(c);
        }
    }
    
    // check if the string is a palindrome
    bool is_palindrome = true;
    int n = stripped_string.size();
    for (int i = 0; i < n / 2; i++) {
        if (stripped_string[i] != stripped_string[n - i - 1]) {
            is_palindrome = false;
            break;
        }
    }
    
    // output the result
    if (is_palindrome) {
        cout << "The input string is a palindrome." << endl;
    } else {
        cout << "The input string is not a palindrome." << endl;
    }
    
    return 0;
}
