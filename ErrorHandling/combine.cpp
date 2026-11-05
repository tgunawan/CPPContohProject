#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

using namespace std;

struct Siswa {
    string nama;
    int nilai;
};

void validasiNilai(int nilai) {
    if (nilai < 0 || nilai > 100) {
        throw invalid_argument("Nilai harus 0 - 100");
    }
}

void simpanKeFile(const vector<Siswa>& daftar) {

    ofstream file("nilai.txt");

    for (const auto& siswa : daftar) {
        file << siswa.nama << " "
             << siswa.nilai << endl;
    }

    file.close();
}

void bacaFile() {

    ifstream file("nilai.txt");

    string nama;
    int nilai;

    cout << "\nData dari file:\n";

    while (file >> nama >> nilai) {
        cout << nama << " - "
             << nilai << endl;
    }

    file.close();
}

int main() {

    vector<Siswa> daftarSiswa;

    int jumlah;

    cout << "Jumlah siswa: ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {

        Siswa s;

        cout << "\nNama: ";
        cin >> s.nama;

        cout << "Nilai: ";
        cin >> s.nilai;

        try {

            validasiNilai(s.nilai);

            daftarSiswa.push_back(s);

        }
        catch (const invalid_argument& e) {

            cout << "Error: "
                 << e.what()
                 << endl;

            i--;
        }
    }

    simpanKeFile(daftarSiswa);

    cout << "\nData berhasil disimpan.\n";

    bacaFile();

    return 0;
}