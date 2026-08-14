#include <iostream>
#include <vector>
#include <string>
#include <algorithm> //for_each

using namespace std;

struct Intern {
    string nama;
    int umur;
    bool inColage;
    int Experience;
};
int clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    return 0;
}
void prosesPointerIntern(Intern* ptr){  
    if (ptr==nullptr){
        cout<< "[System] Warning : Pointer intern bernilai kosong"<<endl;
    }
    else{
        cout<< "[System] Prosesing Intern : "<< ptr->nama <<endl;
    }
}
void sortbyage(vector<Intern>& katalog){
        sort(katalog.begin(), katalog.end(), [](const auto& a, const auto& b) {
        return a.umur < b.umur;
    });
}
void sortbyxp(vector<Intern>& katalog){
        sort(katalog.begin(), katalog.end(), [](const auto& a, const auto& b) {
        return a.Experience < b.Experience;
    });
}
void AllIntern(const vector<Intern>& katalog){
    int i = 1;
    for (const auto& intern : katalog) {
        cout<< "======================"<<endl;
        cout<<i++<<'.'<<endl;
        cout<<"Nama: "<< intern.nama <<endl;
        cout<<"Umur: "<< intern.umur <<endl;
        cout<<"In College: "<< (intern.inColage ? "Yes" : "No")<<endl;
        cout<<"Experience: "<< intern.Experience <<" Years"<<endl;
    }
}
int main(){
    // compiler otomatis tahu jika katalog adalah vector<Intern>
    auto katalog= vector<Intern>{
        {"Jhon Limber",23,true,6},
        {"Liz Corona",22,false,3},
        {"Troy soman",25,true,30},
        {"Lily Smith",21,false,1},
        {"Mia Wong",24,true,5},
        {"David Lee",26,true,10},
        {"Sophia Chen",20,false,2},
        {"Ethan Kim",27,true,15},
        {"Olivia Patel",23,false,4},
        {"Lucas Nguyen",22,true,8},
        {"Ava Martinez",25,true,7},
        {"Noah Johnson",24,true,12},
        {"Isabella Garcia",21,false,3},
        {"Liam Brown",26,true,9},
        {"Mia Davis",23,false,6},
        {"Ethan Wilson",22,true,11},
        {"Sophia Anderson",25,false,5},
        {"Jackson Thomas",24,true,14},
        {"Avery Taylor",21,true,2},
        {"Andreas bonji linkdata mangaraja",31,true,3},
        {"Zui feng tao smith",19,true,0},
    };
    cout<< "===Intern Job DATA "<<endl;
    cout<< "[System] Jumlah intern dalam katalog: "<< katalog.size() <<endl;
    AllIntern(katalog);
    int choice;
    do{
        cout<< "======================"<<endl;
        cout<<"1. Sort"<<endl;
        cout<<"2. Filter"<<endl;
        cout<<"3. Hire"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter the number of your choice: ";

        int x;
        int y;
        cin>>choice;
        clearScreen();
        switch (choice) {        
            case 1:
                cout<<"Sorting intern data..."<<endl;

                cout<<"1. Sort by Age"<<endl;
                cout<<"2. Sort by Experience"<<endl;
                cout<<"Enter the number of your choice: ";
                cin>>choice;
                if(choice==1){
                    sortbyage(katalog);
                }
                else if(choice==2){
                    sortbyxp(katalog);   
                }
                AllIntern(katalog);
                break;
            case 2:
                cout<<"Filtering intern data..."<<endl;
                cout<<"1. Filter by Age"<<endl;
                cout<<"2. Filter by Experience"<<endl;
                cout<<"Enter the number of your choice: ";
                cin>>choice;
                if(choice==1){

                    cout<<"Enter age minimum: ";
                    cin>>x;
                    cout<<"Enter age maximum: ";
                    cin>>y;

                    int i = 1;
                    for (const auto& intern : katalog) {
                        if (intern.umur >= x && intern.umur <=  y){ 
                            cout<< "======================"<<endl;
                            cout<<i++<<'.'<<endl;
                            cout<<"Nama: "<< intern.nama <<endl;
                            cout<<"Umur: "<< intern.umur <<endl;
                            cout<<"In College: "<< (intern.inColage ? "Yes" : "No")<<endl;
                            cout<<"Experience: "<< intern.Experience <<" Years"<<endl;
                        }
                    }
                }
                else if(choice==2){
                    cout<<"Enter experience minimum: ";
                    cin>>x;
                    cout<<"Enter experience maximum: ";
                    cin>>y;

                    int i = 1;
                    for (const auto& intern : katalog) {
                        if (intern.Experience >= x && intern.Experience <= y){ 
                            cout<< "======================"<<endl;
                            cout<<i++<<'.'<<endl;
                            cout<<"Nama: "<< intern.nama <<endl;
                            cout<<"Umur: "<< intern.umur <<endl;
                            cout<<"In College: "<< (intern.inColage ? "Yes" : "No")<<endl;
                            cout<<"Experience: "<< intern.Experience <<" Years"<<endl;
                        }
                    }   
                }
                break;        
            case 3:
                cout<<"Hiring intern..."<<endl;
                break;            
            
            case 4:
                cout<<"Exiting program..."<<endl;
                break;        
            default:
                cout<<"Invalid choice!"<<endl;
                break;            
        }
    }while(choice!=4);
    return 0;
}