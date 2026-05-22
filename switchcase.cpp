#include <iostream>
using namespace std;

int main(){
    char pilihan;


    cout<<"a. Main\n";
    cout<<"b. Setting\n";
    cout<<"c. Exit\n";
    cin>> pilihan;
    switch (pilihan)
    {
    case 'a':
        cout<<"a. Main\n";
        break;
    case 'b':
        cout<<"a. Setting\n";
        break;
    case 'c':
        cout<<"a. Exit\n";
        break;
    
    default:
        break;
    }

    return 0;
}