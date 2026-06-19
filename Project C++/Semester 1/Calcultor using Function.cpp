#include <iostream>
using namespace std;

float tambah(float a, float b) {
    return a + b;
}

float kurang(float a, float b) {
    return a - b;
}

float kali(float a, float b) {
    return a * b;
}

float bagi(float a, float b) {
    if (b != 0)
        return a / b;
    else {
        cout << "Error: Pembagian dengan nol!" << endl;
        return 0;
    }
}

int main() {
    float angka1, angka2;
    char op;

    cout << "=== Kalkulator Sederhana ===" << endl;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan operator (+, -, *, /): ";
    cin >> op;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;
    float hasil;

    switch(op) {
        case '+':
            hasil = tambah(angka1, angka2);
            break;
        case '-':
            hasil = kurang(angka1, angka2);
            break;
        case '*':
            hasil = kali(angka1, angka2);
            break;
        case '/':
            hasil = bagi(angka1, angka2);
            break;
        default:
            cout << "Operator tidak dikenali." << endl;
            return 1;
    }

    cout << "Hasil: " << hasil << endl;
    return 0;
}
