#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    int detik;

    cout << "=== Countdown Timer (for loop, unistd.h) ===" << endl;
    cout << "Masukkan waktu dalam detik: ";
    cin >> detik;

    if (detik <= 0) {
        cout << "Masukkan angka yang lebih besar dari 0!" << endl;
        return 1;
    }

    for (int i = detik; i > 0; i--) {
        cout << "Waktu tersisa: " << i << " detik" << endl;
        sleep(1);
    }

    cout << "Waktu Habis!" << endl;
    return 0;
}
