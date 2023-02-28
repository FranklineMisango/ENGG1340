#include <iostream>
using namespace std;

int main() {
   double weight, height, bmi;

   cin >> weight >> height;
   bmi = weight / (height * height);
   
   cout << "Your BMI = " << bmi << endl;
   cout<<"BMI VALUES\n";
   cout<<"Underweight: less than 18.5\n";
   cout<<"Normal: between 18.5 and 24.9\n";
   cout<<"Overweight: between 25 and 29.9\n";
   cout<<"Obese: 30 or greater\n";

   return 0;
}
