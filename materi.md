# Materi 1

#include <iostream>
using namespace std;
main() > Fungsi utama program
cout > Output Layar
cin > input user
return 0 => Program selesai

# Materi 2
## Variable dan tipe data

- int = bilangan bulat
- float = desimal (untuk perhitungan kurang presisi) > jauh lebih kecil
- double = desimal (presisi yang tinggi) > jauh lebih berat
- char = karakter (n,5,",@)
- string = Teks (s3#%%) 
- bool = True / False

## operator
- Aritmatika
    +,-,*,/
- Assignment
    =,+=,-=,*=
- Perbandingan
    ==,!=, >=, 

## reference Variable dari memori langsung
int HealthPoint = 100;

    int& HP=HealthPoint;
    HealthPoint-=10;
    cout<<HealthPoint<<endl;
    HP-=20;
    cout<<HP<<endl;

    // & ambil alamat memori, * dereference memori
   cout<< &HP<<endl;
   cout<< &HealthPoint;


# Materi 3
## input
cin>>nama;
## getline
getline(cin,nama);


# Materi 4 Conditional
if (nilai>45 && usia>12)
else if
else
 
switch(para){
    case 'a':
    case 'b':
    default:
}
- operator logika = && , ||, !

# Materi 5 Looping
for( int i;i<5;i++)

# Materi 6 function
void halo(){

} // fungsi yang di jalankan tanpa return / mengembalikan nilai

int / string nilai(){

return 0 / "" } jika pakai suatu tipe data tertentu maka perlu mengembalikan nilai berdasarkan tipe data yang di set untuk fungsi tersebut

parameter bisa di set sebagai default
void tambah (int a, float b){

return a*b} 

## Overloading
buat sebuah fungsi dengan nama yang sama namun berbeda parameter

## scope dari variable

### reference parameter
void tambahGaji(int &gaji) { // & berfungsi untuk dapat mengubah variable di luar fungsi / variable global
    cout << "Gaji sebelum ditambah: " << gaji << endl;
    gaji += 200; // Menambahkan tambahan ke gaji
}

bisa panggil dari file lain tapi perlu
- Header file (.h / .hpp)
- source fungsi (.cpp)
- main.cpp (main file) > panggil header

i/o,variable,operator, control(conditional - looping),function,list / array,string manipulation, nested loop,pointer(basic), OOP 

### local variable
hanya bisa di pakai dalam 1 lingkup fungsi itu sendiri

### Global variable
bisa di pakai di semua fungsi

### block scope
hanya berlaku / bisa di panggil dalam {}

# Built in string 
# Materi 7 Array 1D 
# Materi 8 Object-Oriented Programming (Class, Object, Encapsulation, Inheritance, Polymorphism, Abstraction)
- class = klasifikasi - template object / blueprint object
- Object = instance - bentuk asli hasil dari class -> sebuah variable yang menyimpan / di definisikan sebagai class tertentu ( adam=manusia("Adam") )
Kenapa perlu OOP / perlu objek
fungsi => menyimpan perintah dan data sementara / global tidak bisa membuat data aman
object => membuat data lebih aman dan mudah untuk program menjadi modular dan mudah untuk di debug / di kembangkan lagi

4 pilar utama OOP :
- Encapsulation = untuk membuat data menjadi lebih aman (private,protected / public)
- Inheritance = Parent - child => untuk mendapatkan method dari parent
- Polymorphism = sebuah fungsi yang bisa di pakai untuk memanggil method yang berbeda
- Abstraction = template yang harus ada di class bawah nya..(kendaraan -> bergerak )

# Materi 9  Dynamic memory & Smart Pointer

- Memory stack:
    - analogi : LiFo(Last in First Out) -> tumpukan piring setelah di cuci tumpukan paling atas yang di ambil pertama
    - ukuran apps / program lebih kecil, alokasi memori otomatis dari komputer dan langsung di hapus begitu fungsi selesai (keluar dengan tanda '}')
    - contoh yang ada di stack int x = 10;

- Memory Heap(set manual memori):
    - analogi : tempat parkir-> bebas mau parkir dimana saja tapi harus ingat mengeluarkan kendaraan.
    - ukuran bisa sebesar sisa RAM, dengan heap yang tidak di hapus. pakai dengan 'new' dengan perlu 'delete'
    - memori leak: buat banyak new tapi lupa delete-> hasilnya menumpuk dan memori habis lama-lama program crash

- Gaya lama heap memory menggunakan new dan delete
- gaya baru heap memory 
    - std::unique_ptr = eksklusif hanya boleh ada 1 pointer yang pegang alamat memori, jadi tidak bisa di copy hanya bisa di move
    - std::shared_ptr = pointer bisa di bagi, alamat memori dapat di pegang bersama-sama di beberapa pointer

# Materi 10 Struct & File Handling
- struct = struktur kumpulan variable dengan tipe data yang berbeda di bungkus dalam 1 nama
- class vs struct? = struct semua anggotanya public, class private
- kapan pakai?? = jika ingin buat group atau untuk cloning data tanpa pakai inheritance / polymorph

- Filehandling <fstream\>
    - ofstream = output menulis data ke file
    - ifstream = membaca data dari file
    - fstream  = bisa pakai keduanya

Next buat project dengan file handling => bisa save slot game