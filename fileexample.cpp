#include<iostream>
#include<fstream>
#include<string>
#include<random>
using namespace std;

// definisikan struct
struct Pemain {
    string name;
    int skor;
    double durasiMain; //menit
};

int main(){

    Pemain pemainTerbaik;
    pemainTerbaik.name="Jojo Bizare";
    pemainTerbaik.skor=100;
    pemainTerbaik.durasiMain=90.5;

    // buat / tulis file baru bernama HighScore.txt
    ofstream fileKeluar("HighScore.txt");
    if (fileKeluar.is_open()){
        fileKeluar<<pemainTerbaik.name<<"\n";
        fileKeluar<<pemainTerbaik.skor<<endl;
        fileKeluar<<pemainTerbaik.durasiMain<<endl;
        fileKeluar.close(); 
    }else{
        cout<<"Gagal membuat file!"<<endl;
    }
    
    // baca file HighScore.txt 
    Pemain pemainDimuat;
    ifstream fileMasuk("HighScore.txt");
    if (fileMasuk.is_open()){
        getline(fileMasuk,pemainDimuat.name);
        fileMasuk>>pemainDimuat.skor;
        fileMasuk>>pemainDimuat.durasiMain;
        fileMasuk.close();
    }else{
        cout<<"Gagal membuka file!"<<endl;
    }

cout<<"Pemain dimuat: "<<pemainDimuat.name<<endl;
cout<<"Skor: "<<pemainDimuat.skor<<endl;
cout<<"Durasi main: "<<pemainDimuat.durasiMain<<" menit"<<endl;

    return 0;
}