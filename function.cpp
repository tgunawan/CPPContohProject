#include <iostream>
#include <string>
using namespace std;

// string inputnama(){
//     string nama;
//     cout << "Masukkan nama: ";
//     getline(cin, nama);
//     return nama;
// }
// void halo() {
//     cout << "Halo, Dunia!" << endl;
// }
// void truth() {
//     cout << "Kaktedi Jahat!!!!!" << endl;
// }
// void Loop(int X=2) {
//     for (int i = 0; i < X; i++) {
//         cout << i << endl;
//     }
// }

void tambahGaji(int &gaji) {
    cout << "Gaji sebelum ditambah: " << gaji << endl;
    gaji += 200; // Menambahkan tambahan ke gaji
}

int main() {
    // halo(); // Memanggil fungsi halo
    // truth(); // Memanggil fungsi truth
    // Loop();
    // string user = inputnama();
    // cout << "Nama yang dimasukkan: " << user << endl;


    int gajiSaya=3000;
    cout<<"Gaji saya: "<<gajiSaya<<endl;
    tambahGaji(gajiSaya); // Memanggil fungsi
    cout<<"Gaji saya setelah ditambah: "<<gajiSaya<<endl;
    return 0;
}