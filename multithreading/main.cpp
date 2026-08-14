#include <iostream>
#include <thread> // library utama untuk multi threading
#include <mutex> //library pengaman
#include <future> // library async
#include <vector>
#include <chrono> // simulasi delay

using namespace std;

int saldoBank = 1000; // shared / global variable
mutex kunciRekening; // mutex mengamankan saldo

void SETORWONG(int id , int jumlah){
    for(int i=0; i<3; i++){
        //setting agar terlihat pakai waktu
        this_thread::sleep_for(chrono::milliseconds(200));
        {
            //agar otomatis terkunci pakai lockguard dalam 1 block code
            lock_guard<mutex> lock(kunciRekening);
            saldoBank += jumlah;
            cout<<"Setoran thread "<<id<<"Menyetor: Rp"<<jumlah<<"Saldo sekarang jadi: Rp"<<saldoBank<<endl;
        } 
    }
}

int perhitunganKompleks(int angka){
    cout<<"Simulasi mulai di latar"<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    return angka*100;
}
int main(){
    cout<<"== Bank Jojo =="<<endl;
    cout<<"========================="<<endl;

    //1. buat thread
    cout<<"Simulasi multithreading bank"<<endl;
    cout<<"Saldo awal: "<<saldoBank<<endl;

    thread t1(SETORWONG, 1  , 200);
    thread t2(SETORWONG, 2  , 400);

    //wajib pakai join
    t1.join();
    t2.join();
    cout<<"Saldo terakhir"<<saldoBank<<endl;

     //2. buat async
    cout<<"===================Simulasi async================="<<endl;

    future<int> hasilFuture = async(launch::async,perhitunganKompleks,45);
    cout<<"Main thread mengerjakan loop"<<endl;
    for(int i=0; i<3; i++){
        cout<<"Main thread mengerjakan loop"<<endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    int hasilAkhir=hasilFuture.get();
    cout<<"Thread selesai akhir hasil: "<<hasilAkhir<<endl;

    return 0;
}

