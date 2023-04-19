#include <iostream>
using namespace std;

int divisorCount(int N) {
  int NumberOfDivisors = 0;
  int divisor = 1;
  while (divisor <= N){
    if (N % divisor == 0){
      NumberOfDivisors += 1;
    }
    divisor += 1;
  }
  
  return NumberOfDivisors;
  
}



bool antiprime(int N){
    int init = divisorCount(N);
    for (int i = 1; i < N; i++) {
        if (divisorCount(i) >= init)

            return false;
    }
    return true;
}


int main() {
  int b;
  cin >> b;
  int NumberOfDivisors = divisorCount(b);
  if (b<=0){
    cout << 1 << endl;
  }
  else if (antiprime(b)){
    cout << b << endl;
  }
  else {
    while (antiprime(b) == false){
      b += 1;
      if (antiprime(b)){
        cout << b << endl;
      }
    }
  }
  return 0;
}