# Ampersand dan asterix
Dalam bahasa pemrograman C++, simbol & (ampersand) dan * (asterisk/bintang) di sekitar variabel memiliki fungsi yang berkaitan dengan alamat memori (RAM). [1] (https://www.duniailkom.com/tutorial-belajar-c-plus-plus-pengertian-variabel-dalam-bahasa-c-plus-plus/), [2] (https://www.tutorialspoint.com/cplusplus/cpp_pointer_operators.htm)
Berikut adalah penjelasan dan contoh fungsinya:

## 1. Simbol & (Ampersand)

Simbol & memiliki dua arti utama tergantung cara penggunaannya:
• Sebagai Referensi (Reference Type)
Membuat nama lain (alias) dari sebuah variabel yang sudah ada. Keduanya merujuk ke kotak memori yang sama persis.
• Sebagai Operator Alamat (Address-of Operator)
Mengambil letak atau alamat memori suatu variabel di dalam RAM. [1] (https://www.reddit.com/r/cpp_questions/comments/1ma3jc9/im_so_confused_with_the_and_operators/), [2] (https://www.youtube.com/shorts/wFDIHRBhFok), [3] (https://www.tutorialspoint.com/cplusplus/cpp_pointer_operators.htm)

Contoh Kode Penggunaan &:

cpp
#include <iostream>
using namespace std;

int main() {
    int angka = 10;
    
    // 1. Penggunaan & sebagai Reference (alias)
    int &refAngka = angka; 
    refAngka = 20; // Mengubah refAngka juga mengubah nilai 'angka'
    cout << "Nilai angka: " << angka << endl; // Output: 20

    // 2. Penggunaan & sebagai Address-of (melihat alamat memori)
    cout << "Alamat memori angka: " << &angka << endl; // Output: contohnya 0x6dfe14

    return 0;
}
Use code with caution.

## 2. Simbol * (Asterisk / Bintang)

Simbol * juga memiliki dua arti utama:
• Sebagai Deklarasi Pointer
Menandakan bahwa sebuah variabel adalah pointer — yaitu variabel khusus yang menyimpan alamat memori dari variabel lain, bukan menyimpan nilai datanya secara langsung. [1] (https://www.reddit.com/r/Cplusplus/comments/y10l7g/what_do_ampersands_and_asterisks_mean_when_the/), [2] (https://study.com/academy/lesson/video/how-to-use-pointers-in-c-plus-plus-programming.html), [3] (https://www.reddit.com/r/cpp_questions/comments/1ma3jc9/im_so_confused_with_the_and_operators/), [4] (https://www.tutorialspoint.com/cplusplus/cpp_pointer_operators.htm)
• Sebagai Operator Dereference (Dereference/Indirection Operator)
Mengambil atau mengubah nilai yang tersimpan di dalam suatu alamat memori yang ditunjuk oleh pointer. [1] (https://www.quora.com/What-do-ampersand-and-asterisk-mean-before-a-variable-name-in-the-C-programming-language), [2] (https://www.sololearn.com/en/Discuss/372727/in-pointer-what-is-and-do), [3] (https://www.reddit.com/r/cpp_questions/comments/1ma3jc9/im_so_confused_with_the_and_operators/), [4] (https://www.tutorialspoint.com/cplusplus/cpp_pointer_operators.htm)

Contoh Kode Penggunaan *:

cpp
#include <iostream>
using namespace std;

int main() {
    int x = 50;
    
    // 1. Mendeklarasikan pointer yang menunjuk ke alamat memori 'x'
    int *ptr = &x; 

    cout << "Nilai x: " << x << endl;             // Output: 50
    cout << "Alamat yang disimpan ptr: " << ptr << endl; // Output: alamat memori x

    // 2. Dereferencing: Mengambil nilai dari alamat yang ditunjuk 'ptr'
    cout << "Nilai dari *ptr: " << *ptr << endl;  // Output: 50

    // Mengubah nilai 'x' melalui pointer
    *ptr = 100;
    cout << "Nilai x setelah diubah lewat *ptr: " << x << endl; // Output: 100

    return 0;
}
Use code with caution.

Ringkasan Perbedaan Cepat


Simbol	Konteks	Fungsi
& (saat deklarasi tipe)	int &b = a;	Membuat referensi (nama lain dari variabel a).
& (di depan variabel)	&a	Mengambil alamat memori milik variabel a.
* (saat deklarasi tipe)	int *ptr;	Membuat variabel pointer (penyimpan alamat memori).
* (di depan pointer)	*ptr	Mengakses nilai yang ada di dalam alamat memori tersebut (dereference).

Jika Anda ingin, kita bisa lanjut membahas:
• Bagaimana cara mengirim & atau * ke dalam sebuah fungsi (Pass by Reference / Pass by Pointer).
• Perbedaan kapan sebaiknya menggunakan Reference (&) daripada Pointer (*).
Bagian mana yang ingin Anda pelajari lebih lanjut?


====================================================
# Dalam <stdexcept>, ada banyak standard exception class yang sering dipakai untuk error handling di C++.

Hierarkinya kira-kira seperti ini:

exception
│
├── logic_error
│   ├── invalid_argument
│   ├── domain_error
│   ├── length_error
│   └── out_of_range
│
└── runtime_error
    ├── range_error
    ├── overflow_error
    └── underflow_error


## Contoh penggunaannya:

1. invalid_argument

Untuk input yang tidak valid.

throw invalid_argument("Umur harus positif");

catch(const invalid_argument& e){
    cout << e.what();
}

2. out_of_range

Untuk nilai atau indeks di luar batas.

vector<int> data = {1,2,3};

try{
    cout << data.at(5);
}
catch(const out_of_range& e){
    cout << e.what();
}

3. length_error

Untuk ukuran container melebihi batas.

throw length_error("Ukuran terlalu besar");

4. domain_error

Untuk nilai yang tidak masuk domain matematika.

Misalnya:

double akar(double x){
    if(x < 0)
        throw domain_error("Tidak bisa akar bilangan negatif");
    return sqrt(x);
}

5. runtime_error

Error saat program berjalan yang tidak termasuk kategori lain.

throw runtime_error("Gagal membuka file");

6. overflow_error

Saat nilai melebihi kapasitas tipe data.

throw overflow_error("Integer overflow");

7. underflow_error

Saat nilai terlalu kecil hingga kehilangan representasi.

throw underflow_error("Underflow");

8. range_error

Error terkait rentang nilai hasil komputasi.

throw range_error("Nilai di luar rentang");

9. exception

Kelas induk semua exception standar.

Karena semua exception di atas turunan dari exception, kita bisa menangkap semuanya sekaligus:

try{
    throw invalid_argument("Input salah");
}
catch(const exception& e){
    cout << e.what();
}


Output:

Input salah


Ini sering dipakai sebagai "penjaring terakhir":

try{
    // kode
}
catch(const out_of_range& e){
    cout << "Out of range\n";
}
catch(const invalid_argument& e){
    cout << "Invalid argument\n";
}
catch(const exception& e){
    cout << "Error lain: " << e.what();
}


Untuk training C++ dasar seperti yang sedang kamu kerjakan, yang paling sering dipakai biasanya:

invalid_argument
out_of_range
runtime_error
exception

Empat exception itu sudah mencakup sebagian besar kasus latihan OOP, file handling, dan data structure.

## Buat error sendiri
Cara 1: Turun dari std::exception

Contoh:

#include <iostream>
#include <exception>

using namespace std;

class UmurTidakValid : public exception {
public:
    const char* what() const noexcept override {
        return "Umur harus antara 0 dan 120";
    }
};

int validasiUmur(int umur) {
    if (umur < 0 || umur > 120) {
        throw UmurTidakValid();
    }
    return umur;
}

int main() {
    try {
        int umur = 150;
        validasiUmur(umur);
    }
    catch (const UmurTidakValid& e) {
        cout << e.what() << endl;
    }
}


Output:

Umur harus antara 0 dan 120

Cara 2: Turun dari std::runtime_error

Kalau ingin bisa mengirim pesan error yang berbeda-beda.

#include <iostream>
#include <stdexcept>

using namespace std;

class UmurTidakValid : public runtime_error {
public:
    UmurTidakValid(const string& pesan)
        : runtime_error(pesan) {}
};

int main() {
    try {
        throw UmurTidakValid("Usia tidak boleh lebih dari 120");
    }
    catch (const UmurTidakValid& e) {
        cout << e.what() << endl;
    }
}


Output:

Usia tidak boleh lebih dari 120

Cara 3: Throw object biasa

Secara teknis juga bisa:

class ErrorSaya {};

throw ErrorSaya();


Lalu:

catch (const ErrorSaya&) {
    cout << "Terjadi error";
}


Tetapi ini kurang fleksibel karena tidak memiliki fungsi what().

Yang biasanya diajarkan di OOP

Misalnya untuk sistem akademik:

class NilaiTidakValid : public exception {};
class UmurTidakValid : public exception {};
class SaldoKurang : public exception {};
class LoginGagal : public exception {};


Lalu:

throw NilaiTidakValid();
throw SaldoKurang();


Sehingga catch bisa membedakan jenis error:

catch (const NilaiTidakValid& e) {
    cout << "Error nilai";
}
catch (const SaldoKurang& e) {
    cout << "Saldo tidak cukup";
}


Untuk latihan yang sedang kamu kerjakan tentang validasi umur, membuat class:

class UmurTidakValid : public exception


justru lebih bagus daripada memakai out_of_range, karena nama exception-nya langsung menjelaskan masalah yang terjadi.

