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

# function
void halo(){

} // fungsi yang di jalankan tanpa return / mengembalikan nilai

int / string nilai(){

return 0 / "" } jika pakai suatu tipe data tertentu maka perlu mengembalikan nilai berdasarkan tipe data yang di set untuk fungsi tersebut

parameter bisa di set sebagai default
void tambah (int a, float b){

return a*b} 
## scope dari variable

void tambahGaji(int &gaji) { // & berfungsi untuk dapat mengubah variable di luar fungsi / variable global
    cout << "Gaji sebelum ditambah: " << gaji << endl;
    gaji += 200; // Menambahkan tambahan ke gaji
}

bisa panggil dari file lain tapi perlu
- Header file (.h / .hpp)
- source fungsi (.cpp)
- main.cpp (main file) > panggil header

i/o,variable,operator, control(conditional - looping),function,list / array,string manipulation, nested loop,pointer(basic), OOP 