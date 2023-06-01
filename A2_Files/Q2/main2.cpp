// main2.cpp

#include "searchword.h"
#include <iostream>
#include <string>

using namespace std;

// argc is the number of arguments from the command line
// argv[0] == program name
// argv[1..argc-1] are the arguments
// e.g., if the following command is run at the command prompt:
// > ./main word file1 file2
// then in the main function, argc is 4, and argv[0] is "./main",
// argv[1] is "word", argv[2] = "file1", argv[3] = "file2"
//
// usage: ./main2 word_to_search file1 file2 files3 ...
//
int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "usage: " << argv[0] << " [word_to_search] [file1] [file2] [file3]...\n";
        exit(1);
    }

    string word = argv[1];  // word to search for

    for (int i = 0; i < word.length(); i++) {
        word[i] = tolower(word[i]); //in case the input contains uppercase letter
    }

    // loop through all the filenames in the command line argument
    for (int i = 2; i < argc; ++i) {
        string filename = argv[i];
        int lineCount=0, totalCount=0;
        // search word in file
        if (SearchWord(word, filename, lineCount, totalCount))
            cout << filename << ": error opening file" << endl;
        else
            cout << filename << ": " << lineCount << " " << totalCount << endl;
    }

    return 0;

}
