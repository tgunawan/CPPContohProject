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

using namespace std;

struct pabric{
    int cash;
    int gold;
    float Market_Price;
};

int methgen(pabric,int A){
    while(true){
            this_thread::sleep_for(chrono::seconds(A));
            gold = gold + 1;
    }
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
    thread meth(methgen, pabric, 5);
    return 0;
}