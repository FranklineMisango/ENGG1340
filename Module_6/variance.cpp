#include <iostream>
using namespace std;

double calculateVariance(double numbers[], int count) {
    double sum = 0.0, mean, variance = 0.0;

    // calculate mean
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    mean = sum / count;

    // calculate variance
    for (int i = 0; i < count; i++) {
        variance += (numbers[i] - mean) * (numbers[i] - mean);
    }
    variance /= count;

    return variance;
}

int main() {
    int count;
    double numbers[20];
    // user input
    cin >> count;
    for (int i = 0; i < count; i++) {
        cin >> numbers[i];
    }
    double variance = calculateVariance(numbers, count);
    cout << "Variance = " << variance << endl;

    return 0;
}
