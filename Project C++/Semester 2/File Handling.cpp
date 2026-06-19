#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string nama_file = "data_laporan.txt";

int main() {
    string input_data;
    fstream file;
    file.open(nama_file.c_str(), ios::out); 
    
    cout << "--- Bagian 1: Menulis Data ke File ---\n";

    if (file.is_open()) {
        cout << "Masukkan teks atau data yang ingin disimpan (ketik STOP untuk selesai):\n";

        while (getline(cin, input_data) && input_data != "STOP") {
            file << input_data << endl; 
        }
    
        cout << "\n[Sukses] Data telah selesai ditulis ke file " << nama_file << endl;
        file.close();
    } else {
        cerr << "[ERROR] File " << nama_file << " gagal dibuka untuk operasi TULIS." << endl;
        return 1;
    }

    file.open(nama_file.c_str(), ios::in); 
    
    cout << "\n--- Bagian 2: Membaca Data dari File ---\n";

    if (file.is_open()) {
        cout << "Isi dari file " << nama_file << " adalah:\n";
        cout << "--------------------------------------\n";
        
        string baris_baca;

        while (getline(file, baris_baca)) {
            cout << baris_baca << endl;
        }
        
        cout << "--------------------------------------\n";
        cout << "[Sukses] Pembacaan file selesai." << endl;

        file.close();
    } else {
        cerr << "[ERROR] File " << nama_file << " gagal dibuka untuk operasi BACA." << endl;
    }

    return 0;
}