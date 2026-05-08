using namespace std;
#include <iostream>
#include <string>

int main() {
    int umur;
    string hobi;
    cout << "Masukkan umur: ";
    cin >> umur;
    cin.ignore(); // Mengabaikan karakter newline setelah input umur
    cout << "Masukkan hobi: ";
    getline(cin, hobi); // Menggunakan getline untuk membaca seluruh baris input
    cout << "Hobi: " << hobi << endl;

    return 0;
}