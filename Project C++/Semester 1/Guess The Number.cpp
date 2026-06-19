#include <iostream>
#include <unistd.h>
#include <random>
using namespace std;

int main() {
int number;
random_device rd;
uniform_int_distribution<int> masternum(1,100);
  int x = masternum(rd);
  string name;
  cout << "Guess The Number" << endl;
  cout << "Please write your name: " << endl;
  cin >> name; 
  cout << "Greetings " << name << endl;
  cout << "Welcome to the game called \"Guess The Number\"";
  cout << "The rules are simple, you have to guess the number that the computer has chosen, you have infinite tries to guess the number, good luck!" << endl;
  while (true) {
  cout << "The number is between 1 and 100" << endl;
  cout << "Please enter your first guess: " << endl;
  cin >> number; 
  if (number > x) {
    cout << "Your guess is too high, try again" << endl;
  }
  else if (number < x) {
    cout << "Your guess is too low, try again" << endl;
  }
  else if (number == x) {
    cout << "Your guess is right!, thank you for playing!" << endl;
    break;
  } 
  }
}