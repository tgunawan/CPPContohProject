#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //for_each

using namespace std;

struct Produk {
    string nama;
    double harga;
    bool isDiskon;
};
void prosesPointerProduk(Produk* ptr){  
    if (ptr==nullptr){
        cout<< "[System] Warning : Pointer produk bernilai kosong"<<endl;
    }
    else{
        cout<< "[System] Prosesing Produk : "<< ptr->nama <<endl;
    }
}

int main(){
    // compiler otomatis tahu jika katalog adalah vector<Produk>
    auto katalog= vector<Produk>{
        {"Laptop Gaming",1699,true},
        {"Mouse Wireless",59,true},
        {"Keyboard Mechanic",99,false},
        {"Monitor Gaming",299,true},
        {"Laptop Consumer",399,true},
    };

    // tes nullptr
    Produk* produkPilihan = nullptr;
    prosesPointerProduk(produkPilihan);
    prosesPointerProduk(&katalog[1]);

    // Looping dengan kondisi true pada item
    cout<<"Daftar Produk: "<<endl;
    for(const auto& item:katalog){
        cout<<"- "<< item.nama<<"| Harga: $ "<<item.harga<<(item.isDiskon ? " (Diskon)" : "")<<endl;

    }

    // lambda inline function | anonimous function
    double persenDiskon = 0.10;
    auto terapkanDiskon =[persenDiskon](Produk& item){
        if (item.isDiskon){
            item.harga -= (item.harga*persenDiskon);
        }
    };
    for_each(katalog.begin(),katalog.end(),terapkanDiskon);
    cout<<"Daftar Produk dengan Diskon: "<<endl;

    for(auto& item:katalog){
        cout<<"- "<< item.nama<<"| Harga setelah discount: $ "<<item.harga<<endl;
    }

    return 0;
}