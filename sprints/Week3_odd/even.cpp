#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n << " is even" << std::endl;
  } else {
    cout << n << " is odd" << std::endl;
  }
  return 0;
}
