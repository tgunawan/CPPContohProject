#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    const int ukuran = 5;
    int nilai[ukuran]; 
    int total = 0;
    double rata_rata;

    cout << "--- Program Penghitung Rata-Rata Nilai ---\n";

    for (int i = 0; i < ukuran; i++) {
        cout << "Masukkan nilai mata pelajaran ke-" << i + 1 << ": ";
        cin >> nilai[i];
        
        total += nilai[i];
    }

    cout << "\nNilai yang dimasukkan adalah: ";
    for (int i = 0; i < ukuran; i++) {
        cout << nilai[i];
        if (i < ukuran - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    rata_rata = (double)total / ukuran; 
    cout << "\n--- Hasil Perhitungan ---" << endl;
    cout << "Total seluruh nilai: " << total << endl;
    cout << fixed << setprecision(2); 
    cout << "Rata-rata nilai: " << rata_rata << endl;

    return 0;
}