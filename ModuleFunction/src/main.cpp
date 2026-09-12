#include <iostream>
#include "Kalkulator.h"

using namespace std;

int main(){
    cout<<"Aplikasi Kalkulator\n";
    Kalkulator kalko;

    double x=10.0;
    double y=2.0;

    double hasil=kalko.tambah(x,y);
    cout<<"Hasil tambah adalah: "<<hasil<<endl;


    return 0;
}