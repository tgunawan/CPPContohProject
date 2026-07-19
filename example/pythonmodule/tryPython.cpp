#include "pythonlike.h"

int main() {
    print("Halo dari C++ mirip Python!\n");

    std::string nama = input<std::string>("Masukkan nama: ");
    print("Halo, " + nama + "!\n");

    int umur = input<int>("Masukkan umur: ");
    print("Umur Anda: " + std::to_string(umur) + "\n");

    std::vector<int> angka = range(0, 5);
    print("Daftar angka:\n");
    for (int x : angka) {
        print(std::to_string(x) + " ");
    }
    print("\n");
    
    return 0;
}