#include <iostream>
#include <vector> // wadah vector
#include <map> // wadah map
#include <set> // wadah set
#include <algorithm> // algoritma STL (Sort,Find,...)
#include <string>

using namespace std;
int main(){
    // map di python = dictionary == JSON
     // 2. Contoh penggunaan Map 
    cout<<"Map Informasi harga"<<endl;
    // format map: map<key,value>
    map<string,double> katalogHarga;

    katalogHarga["GTA xXx"] = 69900.00;
    katalogHarga["Elders neclese "] = 55000.00;
    katalogHarga["The Witcher 3: Wild Hunt"]= 30000.0;
    katalogHarga["Cypherpunk 2077"]= 200000.0;

    string cariGame="Cypherpunk 2077";
    cout<<"Harga dari "<<cariGame<<"adalah Rp."<<katalogHarga[cariGame]<<endl;

    // STL => SET

    cout<<"Id pelanggan Management"<<endl;
    set<int> idPelanggan;

    idPelanggan.insert(1024);
    idPelanggan.insert(5024);
    idPelanggan.insert(1024); // percobaan menyamakan id
    idPelanggan.insert(3024);
    
    cout<<"List id pelanggan: "<<endl;
    for (int id : idPelanggan){
        cout<<"ID: "<<id<<endl;
    }

    return 0;
}