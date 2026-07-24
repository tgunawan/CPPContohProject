#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

int random(int min, int max){
    // static random_device rd;
    // static mt19937_64 gen(rd());
    static mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distr(min,max);
    return distr(gen);
}

string randomType(){
    vector<string> types= {
    "Leafe","Toxic","FLame","Levetating","wet",
    "Battery","Dirt","Stone","Magic",
    "Cold","Lizard","VOID","Metal", "Spirit" };

    int opport= random(1,10);
    cout<<"Opportunity: "<<opport;

    if (opport>5){
        cout<<"Dual Type"<<endl;
        int idx1 = random(0,types.size()-1);
        int idx2;
        do{
            idx2 = random(0,types.size()-1);
        } while (idx1 == idx2);
        cout<<"tipe 1: "<<types[idx1]<<endl;
        cout<<"tipe 2: "<<types[idx2]<<endl;
        return types[idx1]+"/"+types[idx2];
    }else{
        cout<<"Single Type"<<endl;
        int idx = random(0,types.size()-1);
        cout<<"tipe: "<<types[idx]<<endl;
        return types[idx];
    } 
}

int main(){
    // int hasil;
    // hasil=random(1,8);
    // cout<<hasil;
    string tipe = randomType();
    cout<<tipe<<endl;
    return 0;
}