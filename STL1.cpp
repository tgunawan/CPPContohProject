#include <iostream>
#include <vector> // wadah vector
#include <map> // wadah map
#include <set> // wadah set
#include <algorithm> // algoritma STL (Sort,Find,...)
#include <string>

int main(){
    // 1. Contoh penggunaan STL Vector
    std::cout<<"Daftar Produk:"<<std::endl;
    std::vector<std::string> daftarGame;

    daftarGame.push_back("GTA xXx");
    daftarGame.push_back("Elders neclese ");
    daftarGame.push_back("The Witcher 3: Wild Hunt");
    daftarGame.push_back("Cypherpunk 2077");

    //algorithm STL Sort
    sort(daftarGame.begin(), daftarGame.end()); // Mengurutkan daftar game secara alfabet

    // Menampilkan daftar game setelah diurutkan
    std::cout<<"Daftar Game setelah diurutkan:"<<std::endl;
    for (const auto& game : daftarGame){
        std::cout<<"- "<<game<<std::endl;
    }

    daftarGame.erase(std::remove(daftarGame.begin(), daftarGame.end(), "Elders neclese "), daftarGame.end()); // Menghapus game tertentu dari daftar
    daftarGame.insert(daftarGame.begin() + 1, "Resident Evil 4"); // Menambahkan game baru di posisi tertentu 
    daftarGame[0] = "Cyberpunk 2077"; // Mengubah nama game di indeks tertentu
    daftarGame.erase(daftarGame.begin() + 2); // Menghapus game di indeks tertentu

    // Iterator
    std::cout<<"Jumlah Game: "<<daftarGame.size()<<std::endl;
    for (std::vector<std::string>::iterator it = daftarGame.begin(); it != daftarGame.end(); ++it){
        std::cout<<"- "<<*it<<std::endl;
    }

    

    
    return 0;
}