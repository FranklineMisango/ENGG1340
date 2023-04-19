// searchword.h
#ifndef SEARCHWORD_H
#define SEARCHWORD_H

#include <string>

using namespace std;

// Search for a word w in a file named fn
// word: word to search for
// fn: name of file to search
// nLines: (output) number of lines w appear in fn
// total: (output) total number of occurrences of w in fn
// return 0 if file operation is successful
// return 1 otherwise
int SearchWord(string word, string fn, int &nLines, int &total);

#endif
