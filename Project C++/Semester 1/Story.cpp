#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
  int num3=356, num4=537;
  cout << "Once upon a time, there was a student named Oliver\n";
  sleep(1);
  cout << "Oliver was doesn't know how to count big numbers\n";
  sleep(1);
  cout << "But then, he found a device that could count any numbers he chose\n";
  sleep(1);
  cout << "He tried out the device and asks the device to count the number he chose which was " << num3 << " and " << num4 << endl;
  sleep (1);
  cout << "The device said that the answer was...\n";
  sleep(2);
    cout << num3 << " + " << num4 << " = " << num3+num4 << endl;
    cout << num3 << " - " << num4 << " = " << num3-num4 << endl;
    cout << num3 << " * " << num4 << " = " << num3*num4 << endl;
    cout << num3 << " / " << num4 << " = " << num3/num4 << endl;
    cout << "He was so happy that he could count big numbers\n";
    cout << "Ever since then he used that device to count big numbers\n";
    cout << "The end\n";
}