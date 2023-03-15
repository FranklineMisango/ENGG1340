#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calculate_mean(double x1, double x2, double x3, double x4, double x5) {
    return (x1 + x2 + x3 + x4 + x5) / 5;
}

double calculate_standard_deviation(double x1, double x2, double x3, double x4, double x5) {
    double mean = calculate_mean(x1, x2, x3, x4, x5);
    double variance = ((x1 - mean) * (x1 - mean) + (x2 - mean) * (x2 - mean) + (x3 - mean) * (x3 - mean) + (x4 - mean) * (x4 - mean) + (x5 - mean) * (x5 - mean)) / 5;
    return sqrt(variance);
}

int main() {
    double x1, x2, x3, x4, x5;
    cout << "Enter 5 numbers: ";
    cin >> x1 >> x2 >> x3 >> x4 >> x5;

    double mean = calculate_mean(x1, x2, x3, x4, x5);
    double standard_deviation = calculate_standard_deviation(x1, x2, x3, x4, x5);

    cout << fixed;
    cout << setprecision(2);
    cout << "Mean =  " << mean << endl;
    cout << "Standard deviation = " << standard_deviation << endl;

    return 0;
}
