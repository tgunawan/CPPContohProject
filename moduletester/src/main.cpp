#include <iostream>

// Header memberi tahu file ini bahwa fungsi jumlahkan tersedia.
#include "fungsi.h"

int main() {
    // Panggil fungsi seperti fungsi biasa, lalu simpan nilai yang dikembalikan.
    int hasil = jumlahkan(7, 5);

    std::cout << "Hasil penjumlahan: " << hasil << '\n';
    return 0;
}
