#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <future>
#include <chrono>
#include <utility>

using namespace std;

mutex mtx;

//fungsi worker yang menjalankan tugas 1 detik dalam 1 thread
void worker(int id){
    {
        lock_guard<mutex> lock(mtx);
        cout<<"[System] worker di thread"<<id<<" mulai berjalan(dapat kunci)\n";
    }

    this_thread::sleep_for(chrono::seconds(1));

    {
        lock_guard<mutex> lock(mtx);
        cout<<"[System] worker di thread"<<id<<" selesai berjalan(lepas kunci)\n";
    }
}

int proces_resource(int id){ // proses async
    this_thread::sleep_for(chrono::milliseconds(500));
    cout<<"[System] thread resource"<<id<<" berhasil proses resource\n";
    return 100*id ;
}

int main(){
    cout<<"Simulasi Game Tycon\n";

    
    cout<<"Simulasi Async ambil nilai\n";
    vector<future<int>> futures;

    for (int i=1; i<=3;i++){
        futures.push_back(async(launch::async,proces_resource,i)); //apppend di python
    }

    int total_resource = 0; // menunggu dan ambil hasil dari tiap futures
    for  (auto& ftr : futures){
        int result = ftr.get();
        total_resource += result;
         cout<<"berhasil ambil nilai "<<result<<endl;
    }
    cout<<"berhasil ambil nilai total \n"<<total_resource<<endl;

    //concurent atau thread
    vector<thread> threads;

    for (int i=0;i<5;i++){
        threads.emplace_back(worker,i+1); // buat thread baru
    }

    // tunggu semua thread selesai
    for  (auto& trd : threads){
        trd.join(); // buat main thread menunggu sampai semua thread selesai
    }
    return 0;
}