
//Problem 6.1.2 for the arrays

#include <iostream>

using namespace std;

int main() {
    double x[2][2][3] = { { {3, 4, 2}, {0, -3, 9} }, { {13, 4, 56}, {5, 9, 3}}};
    double max_val = x[0][0][0];
    double min_val = x[0][0][0];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                if (x[i][j][k] > max_val) {
                    max_val = x[i][j][k];
                }
                if (x[i][j][k] < min_val) {
                    min_val = x[i][j][k];
                }
            }
        }
    }

    cout << "Maximum value: " << max_val << endl;
    cout << "Minimum value: " << min_val << endl;

    return 0;
}
