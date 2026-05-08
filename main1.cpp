#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama;
    int Nilai;
    cout<<"Nilai: ";
    cin>>Nilai;
    if (Nilai > 100) {
        cout<<"Nilai lebih besar dari 100";
    }
    else if(Nilai<50){
        cout<<"Nilai lebih kecil dari 50";
    }
    else{
        cout<<"Nilai antara 50 dan 100";
    }

    cout << "Nama: ";
    getline(cin, nama);
    return 0;
}
