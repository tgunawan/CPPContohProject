#include <iostream>
#include <unistd.h>
using namespace std;
int main() {
  int num1, num2, choose;
  cout << "Please insert a number: ";
  cin >> num1;
  cout << "Please insert another number: ";
  cin >> num2;
  cout << "Menu:\n1. +\n2. -\n3. *\n4. / " << endl;
  cout << "Please choose an option:\n";
  cin >> choose;
  if (choose == 1){
    cout << num1 << " + " << num2 << " = " << num1+num2 << endl;
  } else if (choose == 2){
    cout << num1 << " - " << num2 << " = " << num1-num2 << endl;
  } else if (choose == 3){ cout << num1 << " * " << num2 << " = " << num1*num2 << endl;
  } else if(choose == 4){
    cout << num1 << " / " << num2 << " = " << num1/num2 << endl;
  } else {
    cout << "Invalid option" << endl;
  }
} 