#include "pythonlike.h"

int main() {
    print("Halo dari C++ mirip Python!\n");
    std::string nama = input("Masukkan nama: ");
    print("Halo, " + nama + "!\n");
    return 0;
}