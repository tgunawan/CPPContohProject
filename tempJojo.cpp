// Love your self
// Tycoon Gold mine
//pABRUK mAKE STUFF TO SELL FOR CASH
//USE CASH LVL UP MORE CASH
#include<iostream>
#include<string>
#include<random>
#include<vector>
#include<chrono>
#include<thread>
#include<mutex>
#include <future>

using namespace std;
mutex mx;
struct pabric{
    int cash;
    int gold;
    float Market_Price;
};

int methgen(pabric p,int A){
        lock_guard<mutex> lock(mx);
            this_thread::sleep_for(chrono::seconds(A));
            p.gold = p.gold + 1;
            cout<<"You have made 1 gold"<<endl;
}

int main(){
    cout<<"Welc0Me tO E**g*l Me** L*b Si*uL*Ti*N"<<endl;
    cout<<"Lets Continue The last yOU kNOW Dr *******"<<endl;
    cout<<"Wait, Your acc has been terminated Welp gtg make a new one"<<endl;
    cout<<"Pls Enter YOur new Name DR"<<endl;
    string name;
    cin>>name;
    cout<<"Oh WOW DR "<<name<<" What a nice name"<<endl;
    cout<<"Now lets get started with your new acc"<<endl;
    
    pabric Lab;
    Lab.cash = 0;
    thread meth(methgen,Lab,5);
    thread meth2(methgen,Lab,12);
    return 0;
}