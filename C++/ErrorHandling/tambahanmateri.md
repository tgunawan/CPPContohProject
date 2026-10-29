Dalam bahasa pemrograman C++, simbol & (ampersand) dan * (asterisk/bintang) di sekitar variabel memiliki fungsi yang berkaitan dengan alamat memori (RAM). [1] (https://www.duniailkom.com/tutorial-belajar-c-plus-plus-pengertian-variabel-dalam-bahasa-c-plus-plus/), [2] (https://www.tutorialspoint.com/cplusplus/cpp_pointer_operators.htm)
Berikut adalah penjelasan dan contoh fungsinya:

1. Simbol & (Ampersand)

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

2. Simbol * (Asterisk / Bintang)

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
