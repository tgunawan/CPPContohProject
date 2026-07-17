#include <iostream>
#include <string>
#include <stdexcept> //tryexcept
using namespace std;

//1. Template Function
template <typename T>
T cariMaksimum(T a, T b){
    return (a > b) ? a : b;
}


//2 . Template Class
template <typename T>
class KotakPenyimpanan{
    private:
        T isi; 
    public:
        KotakPenyimpanan(T input) : isi(input) {}
        T getIsi() {return isi;}
};

double hitungBagi(double n1,double n2){
    if (n2 == 0){
        throw runtime_error("Error Matematika: Pembagian dengan nol tidak diperbolehkan.");
    }
    return n1 / n2;
}

int main(){
    cout << cariMaksimum(5, 10) << endl;
    cout << cariMaksimum(5.6, 10.8) << endl;
    // cout << cariMaksimum("Hello", "World") << endl;

    
    KotakPenyimpanan<int> kotakangka(43);
    cout << kotakangka.getIsi() << endl;

    KotakPenyimpanan<float> kotakangka2(43.2f);
    cout << kotakangka2.getIsi() << endl;

    try{
        double angka1=10.0;
        double angka2=0.0;

        double hasil = hitungBagi(angka1, angka2);
        cout << "Hasil pembagian: " << hasil << endl;
    }
    catch (const runtime_error& e){
        cout << "Error caused: " << e.what() << endl;
    }



    return 0;
}
