// #include <iostream>
// using namespace std;

// int tambah(int a, int b){
//     return a+b;
// }

// double tambah(double a, double b){
//     return a+b;
// }

// string username(string nama){
//     return "Selamat datang "+nama;
// }

// int main(){
// cout<< tambah(2,3)<<endl;
// cout<< tambah(3.45,3.5)<<endl;
// cout<< username("Jojo");
//     return 0;
// }


#include <iostream>
#include <string>
using namespace std;

string nama="Budi";

int angka=50; // global variable 

void prosesInput(int id){ // id parameter / lokal bawaan fungsi
    int angka1=20;// local variable
    cout <<"\n [Sistem] Menghubungi Database..."<<endl;
    cout <<"Mencari data berdasarkan ID: "<<id<<endl;
    cout <<"Status di temukan"<<endl;
}

void prosesInput(string nama){
    cout <<"\n [Sistem] Menyapa user..."<<endl;
    cout <<"Halo "<<nama<<", Selamat datang."<<endl;
}

int main(){
    int pilihan;
    // cout<<angka1;
    if (false){
        int x=2; // variable block scope
        cout<<x;
    }
    // cout<<x;
    cout<<"Masukkan pilihan"<<endl;
    cout<<"1. Masukkan id"<<endl;
    cout<<"2. Masukkan username"<<endl;
    cout<<"Pilihan (1/2): ";
    cin>>pilihan;
    cin.ignore();

    int iduser;
    string namauser;
    switch (pilihan)
    {
    case 1:
        {
        cout<<"Masukkan id user anda: ";
        cin>>iduser;
        prosesInput(iduser);
        break;}
    case 2:
        {
        cout<<"Masukkan nama username: ";
        // getline(cin,namauser); // string dengan spasi
        cin>>namauser; //string tanpa spasi, jika ada spasi maka hanya 1 kata yang diambil
        prosesInput(namauser);
        break;}

    default:
        break;
    }
}