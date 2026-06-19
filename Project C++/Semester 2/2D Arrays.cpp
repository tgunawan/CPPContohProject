#include <iostream>

using namespace std;

int main() {
    const int baris = 3;
    const int kolom = 3;

    int matriksA[baris][kolom];
    int matriksB[baris][kolom];
    int hasil[baris][kolom];

    cout << "--- Program Penjumlahan Dua Matriks (" << baris << "x" << kolom << ") ---\n";

    cout << "\nMasukkan elemen Matriks A:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> matriksA[i][j];
        }
    }

    cout << "\nMasukkan elemen Matriks B:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> matriksB[i][j];
        }
    }

    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            hasil[i][j] = matriksA[i][j] + matriksB[i][j];
        }
    }

    cout << "\n--- Hasil Penjumlahan Matriks ---\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << hasil[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}