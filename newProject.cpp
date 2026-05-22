//Project dengan do while, switch, array1D, dan function overloading

#include <iostream>
#include <string>

using namespace std;

// === FUNCTION OVERLOADING ===
double hitungTotal(double harga, int jumlah) {
    return harga * jumlah;
}

double hitungTotal(double harga, int jumlah, double potongan) {
    return (harga * jumlah) - potongan;
}

int main() {
    // === ARRAY 1D ===
   double riwayatBelanja[5] = {0, 0, 0, 0, 0}; 
    int jumlahTransaksi = 0; // Untuk melacak berapa transaksi yang sudah tercatat

    int pilihanMenu;

    do {
        cout << "\n===================================" << endl;
        cout << "   SISTEM KASIR TOKO KELONTONG" << endl;
        cout << "===================================" << endl;
        cout << "1. Entri Transaksi Baru" << endl;
        cout << "2. Lihat Riwayat 5 Transaksi Terakhir" << endl;
        cout << "3. Keluar Aplikasi" << endl;
        cout << "Pilih menu (1-3): ";
        cin >> pilihanMenu;

        // === SWITCH CASE ===
        switch (pilihanMenu) {
            case 1: {
                double hargaBarang;
                int jumlahBeli;
                char tipePembelian;
                double totalAkhir = 0;

                cout << "\n--- Input Transaksi Baru ---" << endl;
                cout << "Masukkan harga barang : Rp ";
                cin >> hargaBarang;
                cout << "Masukkan jumlah beli  : ";
                cin >> jumlahBeli;
                cout << "Apakah ini pembelian grosir? (y/n): ";
                cin >> tipePembelian;

                if (tipePembelian == 'y' || tipePembelian == 'Y') {
                    double diskonGrosir;
                    cout << "Masukkan potongan harga grosir: Rp ";
                    cin >> diskonGrosir;
                    
                    totalAkhir = hitungTotal(hargaBarang, jumlahBeli, diskonGrosir);
                } else {
                    totalAkhir = hitungTotal(hargaBarang, jumlahBeli);
                }

                cout << ">> Total yang harus dibayar: Rp " << totalAkhir << endl;

                if (jumlahTransaksi < 5) {
                    riwayatBelanja[jumlahTransaksi] = totalAkhir;
                    jumlahTransaksi++;
                } else {
                    for (int i = 0; i < 4; i++) {
                        riwayatBelanja[i] = riwayatBelanja[i + 1];
                    }
                    riwayatBelanja[4] = totalAkhir;
                }
                cout << "[Sistem] Transaksi berhasil disimpan ke riwayat!" << endl;
                break;
            }

            case 2: {
                cout << "\n--- Riwayat 5 Transaksi Terakhir ---" << endl;
                if (jumlahTransaksi == 0) {
                    cout << "Belum ada transaksi yang tercatat." << endl;
                } else {
                    for (int i = 0; i < 5; i++) {
                        cout << "Transaksi ke-" << (i + 1) << ": Rp " << riwayatBelanja[i] << endl;
                    }
                }
                break;
            }

            case 3:
                cout << "\nTerima kasih telah menggunakan sistem kasir!" << endl;
                break;

            default:
                cout << "\nPilihan tidak valid! Silakan pilih menu 1-3." << endl;
                break;
        }

    } while (pilihanMenu != 3);

    return 0;
}