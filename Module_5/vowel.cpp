/*
   This program prompts the user to input a sequence of characters and outputs the number of vowels
*/

#include <iostream>
using namespace std;

bool isVowel(char c) {
    switch (c) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

int main()
{
    int n;
    int numVowel = 0;
    char c;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> c;
        if (isVowel(c))
            numVowel++;
    }

    cout << "Number of vowels = " << numVowel << endl;

    return 0;
}
