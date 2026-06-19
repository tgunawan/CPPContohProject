#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
int main() {
  string cls= "\033[2J\033[1;1H";
  int num1, num2, num3, num4, num5, avg;
  cout << "Please enter your math score: ";
  cin >> num1;
  cout << "Please enter your Physics score: ";
  cin >> num2;
  cout << "Please enter your English score: ";
  cin >> num3;
  cout << "Please enter your History score: ";
  cin >> num4;
  cout << "Please enter your PE score: ";
  cin >> num5;
  avg = (num1+num2+num3+num4+num5)/5;
  cout << "Calculating the average score...";
  sleep(3);
  cout << cls;
  cout << "---------------------------------" << endl;
  cout << " Math score: " << num1 << endl;
  cout << " Physics score: " << num2 << endl;
  cout << " English score: " << num3 << endl;
  cout << " History score: " << num4 << endl;
  cout << " PE score: " << num5 << endl;
  cout << " Average: " << avg << endl;
  if ((avg >=90) && (avg <=100)) {
    cout << " Grade: A" << endl;
    cout << " Excellent" << endl;
    cout << "---------------------------------" << endl;
  }
  else if ((avg >=80) && (avg < 90)) {
    cout << " Grade: B" << endl;
    cout << " Very Good" << endl;
    cout << "---------------------------------" << endl;
  }
  else if ((avg >=70) && (avg < 80)) {
    cout << " Grade: C" << endl;
    cout << " Good" << endl;
    cout << "---------------------------------" << endl;
  }
  else if ((avg>=60) && (avg < 70)) {
    cout << " Grade: D" << endl;
    cout << " Pass" << endl;
    cout << "---------------------------------" << endl;
  }
  else if (( avg>=0) && (avg < 60)) {
    cout << " Grade: F" << endl;
    cout << " 5Fail" << endl;
    cout << "---------------------------------" << endl;
  }
}