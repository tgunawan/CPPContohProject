#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

/*
Project sederhana yang menarik:
Mini Quest Shop

Konsep yang dipakai:
1. Function Template -> cariMaksimum, tambahNilai
2. Class Template -> KotakPenyimpanan<T>
3. Exception Handling -> try, throw, catch

Tujuan: membuat contoh yang mudah dipahami pemula.
*/

template <typename T>
T cariMaksimum(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
T tambahNilai(T a, T b) {
    return a + b;
}

template <typename T>
class KotakPenyimpanan {
private:
    vector<T> items;
    size_t kapasitas;

public:
    KotakPenyimpanan(size_t maxSize = 3) : kapasitas(maxSize) {}

    void tambah(const T& item) {
        if (items.size() >= kapasitas) {
            throw out_of_range("Kotak sudah penuh, tidak bisa menambah item lagi.");
        }
        items.push_back(item);
    }

    T ambil(size_t index) {
        if (index >= items.size()) {
            throw out_of_range("Index item tidak valid.");
        }
        T item = items[index];
        items.erase(items.begin() + index);
        return item;
    }

    void tampilkan() const {
        if (items.empty()) {
            cout << "Kotak kosong.\n";
            return;
        }

        for (size_t i = 0; i < items.size(); ++i) {
            cout << "[" << i + 1 << "] " << items[i] << "\n";
        }
    }
};

class Player {
private:
    string nama;
    int gold;

public:
    Player(string n, int awal) : nama(move(n)), gold(awal) {}

    string getNama() const {
        return nama;
    }

    int getGold() const {
        return gold;
    }

    void tambahGold(int amount) {
        if (amount < 0) {
            throw invalid_argument("Jumlah gold tidak boleh negatif.");
        }
        gold += amount;
    }

    void bayar(int amount) {
        if (amount < 0) {
            throw invalid_argument("Jumlah bayar tidak boleh negatif.");
        }
        if (amount > gold) {
            throw runtime_error("Gold tidak cukup untuk membeli item.");
        }
        gold -= amount;
    }
};

void tampilkanMenu() {
    cout << "\n=== Mini Quest Shop ===\n";
    cout << "1. Beli Potion (30 gold)\n";
    cout << "2. Coba function template\n";
    cout << "3. Lihat isi kotak\n";
    cout << "4. Ambil item dari kotak\n";
    cout << "5. Keluar\n";
}

int main() {
    cout << "Selamat datang di Mini Quest Shop!\n";
    cout << "Masukkan nama player: ";
    string nama;
    getline(cin, nama);
    if (nama.empty()) {
        nama = "Hero";
    }

    Player player(nama, 100);
    KotakPenyimpanan<string> kotak(3);
    kotak.tambah("Potion");
    kotak.tambah("Pedang");

    while (true) {
        tampilkanMenu();
        cout << "Pilih menu: ";
        int pilihan;
        if (!(cin >> pilihan)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Coba lagi.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        try {
            switch (pilihan) {
                case 1:
                    player.bayar(30);
                    cout << "Beli Potion berhasil!\n";
                    cout << "Gold tersisa: " << player.getGold() << "\n";
                    break;
                case 2:
                    cout << "Maksimum dari 10 dan 20: " << cariMaksimum(10, 20) << "\n";
                    cout << "Maksimum dari 3.5 dan 7.2: " << cariMaksimum(3.5, 7.2) << "\n";
                    cout << "Hasil tambah template: " << tambahNilai(15, 10) << "\n";
                    break;
                case 3:
                    cout << "Isi kotak saat ini:\n";
                    kotak.tampilkan();
                    break;
                case 4:
                    cout << "Ambil item pertama dari kotak...\n";
                    cout << "Item yang diambil: " << kotak.ambil(0) << "\n";
                    break;
                case 5:
                    cout << "Terima kasih sudah bermain!\n";
                    return 0;
                default:
                    throw invalid_argument("Pilihan tidak tersedia.");
            }
        } catch (const invalid_argument& e) {
            cout << "Error input: " << e.what() << "\n";
        } catch (const runtime_error& e) {
            cout << "Error runtime: " << e.what() << "\n";
        } catch (const out_of_range& e) {
            cout << "Error index: " << e.what() << "\n";
        } catch (const exception& e) {
            cout << "Error umum: " << e.what() << "\n";
        }
    }

    return 0;
}
