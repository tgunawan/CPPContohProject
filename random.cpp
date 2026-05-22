#include<iostream>
#include<random>
using namespace std;

int random(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1,100);
    return distr(gen);
}

int main(){
    
    cout<< "Angka acak modern: "<<random<<endl; 
    cout<<"\033[2J\033[H"; //\033[2J adalah untuk clear layar, \033[H untuk kursore kembali ke awal
    cout<< "Angka acak modern: "<<random<<endl; 
    cout<< "Angka acak modern: "<<random<<endl; 
    cout<< "Angka acak modern: "<<random<<endl; 
    cout<< "Angka acak modern: "<<random<<endl; 
    
    return 0;
}