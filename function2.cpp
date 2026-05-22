#include<iostream>
using namespace std;

int tambah(int a){
    return a+a;
}
char tambah(char a){
    return a*a;
}


int main(){
    cout<<tambah(2)<<endl;//end line
    cout<<tambah(3)<<endl;

    return 0;
}