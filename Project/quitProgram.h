#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#ifndef QUITPROGRAM_H
#define QUITPROGRAM_H

//Quits the program all together
void quitProgram() {
    cout << "Quitting the program..." << endl;
    exit(0); // terminate the program with exit status 0
}

#endif // QUITPROGRAM_H

