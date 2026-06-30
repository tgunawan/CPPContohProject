#include<iostream>
#include<random>
using namespace std;

int random(int min, int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(min, max);//Jika kamu ingin menghasilkan angka desimal pecahan (float/double), kamu tinggal mengganti std::uniform_int_distribution menjadi std::uniform_real_distribution.
    return distr(gen);
}

int main(){
    
    cout<< "Angka acak modern: "<<random(1, 100)<<endl; 
    cout<< "Angka acak modern: "<<random(0,1)<<endl; 
    cout<< "Angka acak modern: "<<random(1, 10)<<endl; 
    cout<< "Angka acak modern: "<<random(10, 20)<<endl; 
    cout<< "Angka acak modern: "<<random(100, 200)<<endl; 
    
    int opportunity = random(1, 100);
    if (opportunity > 50){
        cout<<"Anda bertemu moster biasa!"<<endl;
    } else if (opportunity >80){
        cout<<"Anda bertemu moster mini boss!"<<endl;
    }
    else{
        cout<<"Anda berjalan dengan aman, tidak ada monster yang muncul!"<<endl;
    }
  

    int tesacak = random(1, 100);
    cout << "Tes acak: " << tesacak << endl;
    tesacak = random(1, 100);
    cout << "Tes acak: " << tesacak << endl;
      return 0;
}