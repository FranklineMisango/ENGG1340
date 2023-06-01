#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream instream("temperature.txt");
    ofstream outstream("average.txt");

    if (!instream || !outstream) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    string date;
    double temp, sum;
    int count;

    while (instream >> date) {
        sum = 0.0;
        count = 0;

        for (int i = 0; i < 24; i++) {
            instream >> temp;
            sum += temp;
            count++;
        }

        double average = sum / count;
        outstream << date << " " << fixed << setprecision(1) << average << endl;
    }

    instream.close();
    outstream.close();

    return 0;
}
