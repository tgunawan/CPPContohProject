#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// ==========================================================
// Error Handling dalam C++
// ==========================================================
// Tujuan contoh ini:
// 1. Menangani input pengguna yang salah atau tidak valid.
// 2. Menangani pembagian dengan angka 0.
// 3. Menangani data yang tidak valid (misalnya usia negatif).
// 4. Menangani file yang tidak bisa dibuka.
// 5. Menangani exception yang tidak diperkirakan.
// 6. Menjelaskan bagaimana try-catch dan if-else bekerja.
//
// Catatan:
// - try/catch digunakan untuk menangkap exception.
// - if/else digunakan untuk validasi data atau kondisi yang biasa.
// - throw digunakan untuk melempar error ketika kondisi tidak valid.
// ==========================================================

// Fungsi untuk membaca file teks.
// Jika file tidak ada, function ini akan melempar exception.
string bacaFile(const string& namaFile) {
    ifstream file(namaFile);

    if (!file.is_open()) {
        // throw digunakan untuk memaksa program memberi tahu bahwa ada error.
        throw runtime_error("File tidak ditemukan atau tidak bisa dibuka: " + namaFile);
    }

    string isiFile;
    string baris;

    while (getline(file, baris)) {
        isiFile += baris + "\n";
    }

    return isiFile;
}

// Fungsi untuk menghitung pembagian.
// Jika pembagi == 0, kita lempar exception agar program tidak crash.
double bagi(double pembilang, double penyebut) {
    if (penyebut == 0) {
        throw invalid_argument("Pembagian dengan 0 tidak diperbolehkan.");
    }
    return pembilang / penyebut;
}

// Fungsi validasi umur.
// Jika umur negatif atau > 120, program dianggap data tidak valid.
int validasiUmur(int umur) {
    if (umur < 0 || umur > 120) {
        throw out_of_range("Umur tidak valid. Usia harus berada di rentang 0-120.");
    }
    return umur;
}

// Fungsi untuk membaca input angka dengan validasi.
// Jika pengguna memasukkan bukan angka, fungsi ini akan menolak input.
int bacaInputAngka(const string& pesan) {
    int angka;
    while (true) {
        cout << pesan;
        cin >> angka;

        // Jika input gagal, bersihkan buffer input.
        if (cin.fail()) {
            cout << "[ERROR] Input harus berupa angka bulat. Silakan coba lagi.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // Membersihkan sisa karakter jika user memasukkan data tambahan.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return angka;
    }
}

// Fungsi untuk membaca pilihan menu.
// Memberi contoh validasi terhadap pilihan yang tidak valid.
int pilihMenu() {
    int pilihan;

    while (true) {
        cout << "Pilih menu:\n";
        cout << "1. Hitung pembagian\n";
        cout << "2. Validasi umur\n";
        cout << "3. Baca file\n";
        cout << "4. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        if (cin.fail()) {
            cout << "[ERROR] Pilihan harus berupa angka.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (pilihan >= 1 && pilihan <= 4) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return pilihan;
        }

        cout << "[ERROR] Pilihan tidak valid. Pilih angka 1 sampai 4.\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    cout << "========================================\n";
    cout << "Program Belajar Error Handling di C++\n";
    cout << "========================================\n\n";

    while (true) {
        int pilihan = pilihMenu();

        try {
            switch (pilihan) {
                case 1: {
                    // Contoh menangani pembagian dengan 0.
                    double a = bacaInputAngka("Masukkan angka pembilang: ");
                    double b = bacaInputAngka("Masukkan angka penyebut: ");

                    double hasil = bagi(a, b);
                    cout << "Hasil pembagian: " << hasil << "\n\n";
                    break;
                }

                case 2: {
                    // Contoh menangani umur tidak valid.
                    int umur = bacaInputAngka("Masukkan umur Anda: ");
                    int umurTervalidasi = validasiUmur(umur);
                    cout << "Umur Anda valid: " << umurTervalidasi << " tahun\n\n";
                    break;
                }

                case 3: {
                    // Contoh menangani file tidak ditemukan.
                    string namaFile;
                    cout << "Masukkan nama file yang ingin dibaca: ";
                    getline(cin, namaFile);

                    string isi = bacaFile(namaFile);
                    cout << "Isi file:\n" << isi << "\n";
                    break;
                }

                case 4: {
                    cout << "Terima kasih telah mencoba program ini.\n";
                    return 0;
                }

                default:
                    cout << "[ERROR] Pilihan tidak valid.\n";
                    break;
            }
        }
        catch (const invalid_argument& e) {
            // catch ini menangkap error yang berkaitan dengan argument tidak valid.
            cout << "[ERROR] invalid_argument: " << e.what() << "\n\n";
        }
        catch (const out_of_range& e) {
            // catch ini menangkap error untuk nilai yang berada di luar rentang yang diizinkan.
            cout << "[ERROR] out_of_range: " << e.what() << "\n\n";
        }
        catch (const runtime_error& e) {
            // catch ini menangkap runtime error, misalnya file tidak bisa dibuka.
            cout << "[ERROR] runtime_error: " << e.what() << "\n\n";
        }
        catch (const exception& e) {
            // catch ini menangkap exception umum yang tidak disebutkan jenisnya.
            cout << "[ERROR] exception umum: " << e.what() << "\n\n";
        }
        catch (...) {
            // catch (...) adalah fallback terakhir.
            // Ini menangkap exception yang tidak diketahui tipe-nya.
            cout << "[ERROR] Terjadi error yang tidak diketahui.\n\n";
        }
    }

    return 0;
}

// ==========================================================
// Penjelasan singkat:
//
// 1. throw
//    Digunakan untuk memberi tanda bahwa ada kondisi error.
//    Contoh: pembagian dengan 0, umur tidak valid, file tidak ditemukan.
//
// 2. try
//    Blok ini berisi kode yang bisa menimbulkan error.
//
// 3. catch
//    Blok ini menangkap error dan menjalankan kode penanganan.
//    Kode yang paling spesifik ditulis dulu, lalu generic di akhir.
//
// 4. Kenapa penting?
//    Karena program tidak akan crash atau berhenti tiba-tiba jika ada input
//    yang salah atau file yang tidak ada. Kita bisa memberi pesan yang lebih rapi.
//
// 5. Dalam program ini kita juga menggunakan validasi manual dengan if.
//    Ini penting supaya program kita lebih aman sebelum throw atau catch.
// ==========================================================
