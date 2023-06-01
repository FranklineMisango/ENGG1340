#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int SearchWord(string searchWord, string fileName, int& numLines, int& totalCount)
{
    int resultCode = 0;
    bool foundWord = false;
    ifstream inFile(fileName);
    if (!inFile.is_open()) {
        resultCode = 1;
        return resultCode;
    }
    string currentLine;
    while (getline(inFile, currentLine)) {
        string temp;
        foundWord = false;
        for (int i = 0; i < currentLine.length(); i++) {
            temp = "";
            int currentIndex = i;
            while (!isspace(currentLine[currentIndex])) {
                temp += tolower(currentLine[currentIndex]);
                currentIndex++;
                i = currentIndex;
                if (currentIndex == currentLine.length()) {
                    break;
                }
            }
            if (temp == searchWord) {
                totalCount++;
                foundWord = true;
            }
        }
        if (foundWord) {
            numLines++;
        }
    }
    inFile.close();
    return resultCode;
}