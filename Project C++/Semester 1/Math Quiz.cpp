#include <iostream>
using namespace std;

int main() {
    int jawaban;
    int skor = 0;

    cout << "=== Math Quiz Sederhana ===" << endl;
    cout << "\nSoal 1: Berapa hasil dari 5 x 3?" << endl;
    cout << "1. 8\n2. 15\n3. 10\n4. 20" << endl;
    cout << "Jawaban Anda (1-4): ";
    cin >> jawaban;

    if (jawaban == 1) {
        if (5 * 3 == 8)
            skor++;
    } else if (jawaban == 2) {
        if (5 * 3 == 15)
            skor++;
    } else if (jawaban == 3) {
        if (5 * 3 == 10)
            skor++;
    } else if (jawaban == 4) {
        if (5 * 3 == 20)
            skor++;
    } else {
        cout << "Pilihan tidak valid." << endl;
    }

    cout << "\nSoal 2: Berapa hasil dari 12 / 4?" << endl;
    cout << "1. 2\n2. 3\n3. 4\n4. 6" << endl;
    cout << "Jawaban Anda (1-4): ";
    cin >> jawaban;

    if (jawaban == 1) {
        if (12 / 4 == 2)
            skor++;
    } else if (jawaban == 2) {
        if (12 / 4 == 3)
            skor++;
    } else if (jawaban == 3) {
        if (12 / 4 == 4)
            skor++;
    } else if (jawaban == 4) {
        if (12 / 4 == 6)
            skor++;
    } else {
        cout << "Pilihan tidak valid." << endl;
    }

    cout << "\nSoal 3: Berapa hasil dari 7 + 6?" << endl;
    cout << "1. 13\n2. 14\n3. 12\n4. 15" << endl;
    cout << "Jawaban Anda (1-4): ";
    cin >> jawaban;

    if (jawaban == 1) {
        if (7 + 6 == 13)
            skor++;
    } else if (jawaban == 2) {
        if (7 + 6 == 14)
            skor++;
    } else if (jawaban == 3) {
        if (7 + 6 == 12)
            skor++;
    } else if (jawaban == 4) {
        if (7 + 6 == 15)
            skor++;
    } else {
        cout << "Pilihan tidak valid." << endl;
    }

    cout << "\n=== Skor Akhir Anda: " << skor << " dari 3 ===" << endl;

    if (skor == 3) {
        cout << "Luar biasa! Semua jawaban benar." << endl;
    } else if (skor == 2) {
        cout << "Bagus! Hanya salah satu." << endl;
    } else if (skor == 1) {
        cout << "Lumayan, coba lagi yuk!" << endl;
    } else {
        cout << "Yah, belum ada yang benar. Semangat belajar!" << endl;
    }
    return 0;
}
