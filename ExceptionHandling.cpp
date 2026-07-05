#include <iostream>
#include <string>
#include <stdexcept> // wajib di masukkan untuk pakai runtime_error
using namespace std; // jika sudah mulai terbiasa ini bisa di hilangkan

//1. Template Function 
//T adalah place holder untuk tipe data yang akan di gunakan
template <typename T>
T cariMaksimum(T a, T b){
    return (a > b) ? a : b;
}

// 2 . Template Class
// membuat class "kotak penyimpanan" yang dapat menampung tipe data apapun
template <typename T>
class KotakPenyimpanan{
    private:
    T isi; 
    public:
    KotakPenyimpanan(T input) : isi(input) {}
    T getIsi() {return isi;}
};

// 3. Function with Exception Handling
double hitungBagi(double pembilang, double penyebut){
    if (penyebut == 0){
        // melempar error keluar jika penyebut di isi 0
        throw runtime_error("Error Matematika: Pembagian dengan nol tidak diperbolehkan.");
    }
    return pembilang / penyebut;
}

int main(){
    cout<< "=== Contoh Template Function dengan Error Handling===" << endl;

    cout<<"Fungsi"<<endl;
    cout << "Mencari nilai maksimum dari 10 dan 20: " << cariMaksimum(10, 20) << endl;// cariMaksimum<double>(10, 20.7) jika ingin memaksa mengubah template fungsi dengan tipe data tertentu
    cout << "Mencari nilai maksimum dari 3.5 dan 2.1: " << cariMaksimum(3.5, 2.1) << endl;

    cout<<"Class"<<endl;
    KotakPenyimpanan<int> kotakInt(42);
    KotakPenyimpanan<string> kotakString("Hello, World!");
    cout<< "Isi Kotak :" << kotakInt.getIsi()<<endl;
    cout<< "Isi Kotak :" << kotakString.getIsi()<<endl;

    cout<<"Error Handling"<<endl;
    try{
        double angka1=10.0, angka2=0.0;
        cout<<"Mencoba membagi angka"<<endl;
        double hasil = hitungBagi(angka1, angka2);
        cout << "Hasil pembagian: " << hasil << endl;
    }
    catch (const runtime_error& e){
        // menangani error tanpa membuat program berhenti
        cout << "Error caused: " << e.what() << endl;
        cout << "Solusi : ubah pembagi otomatis jadi 1 agar lebih aman" << endl;
    }
    cout << "Program selesai dengan aman." << endl;
    return 0;
}