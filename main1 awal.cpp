#include <iostream>
using namespace std;

int main() {
    int usia =80;
    float tinggi=140.5;
    char grade='A';
    string nama="Jojo";
    bool lulus=true;

    // cout << "Nama: " << nama << endl;
    // cout << "Usia: " << usia << " tahun" << endl;

    int HealthPoint = 100;

    int& HP=HealthPoint;
    HealthPoint-=10;
    cout<<HealthPoint<<endl;
    HP-=20;
    cout<<HP<<endl;

    // & ambil alamat memori, * dereference memori
   cout<< &HP<<endl;
   cout<< &HealthPoint;







    return 0;
}
