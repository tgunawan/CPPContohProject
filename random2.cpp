#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));   
 
    int glorgoskuss = 0;
    while (true) {
 
    int bopster = (rand()%100) + 1;
    int dringking = (rand()%100) + 1;
// its a game called hello neighbor
    int pulsormines = (rand()%3) ;
    
    int blorb;
    
    // INI UNTUK SOAL +
    if (pulsormines == 0){
        cout << bopster<< "  +" <<dringking <<" =" << endl;
        cin >> blorb;
      
        int gloinkqueen = bopster + dringking;
        
        
        if (blorb == gloinkqueen) {
            cout <<"OOHH YYESSSSSIRREE BOI!"<<endl;
            glorgoskuss += 1;
        } else {
            cout <<"NOO YOU WERE WRONG NGAAHH"<<endl;
            break; 
            glorgoskuss -= 1;
        }
    }
    
    // for -
    else if (pulsormines == 1){
        cout << bopster<< " - " <<dringking <<" ="<< endl;
        cin >> blorb;
        
        int gloinkqueen = bopster - dringking;
        
        
         
            
            if(blorb == gloinkqueen) {
            cout <<"OOHH YYESSSSSIRREE BOI!"<<endl;
            glorgoskuss += 1;
        } else {
            cout <<"NOO YOU WERE WONG NGAAHH"<<endl;
            break;
         }     
            
    }
        
        //💀💀💀💀💀💀💀👺💀
        

        
        else if (pulsormines == 2){
            cout << bopster<< " * " <<dringking <<" ="<< endl;
            cin >> blorb;
            
            int gloinkqueen = bopster * dringking;
            
            
            if(blorb == gloinkqueen) {
                cout<<"OOHH YYESSSSSIRREE BOI!"<<endl;
                glorgoskuss += 1;
            } else {
                cout <<"NOO YOU WERE WROGN NGAAHH"<<endl;
                break;
                
            }
        }
    }
    
    
    
    
    

     
    cout <<"--. --- / .... --- -- . / .- -. -.. / -.. --- -. - / -.-. --- -- . / -... .- -.-. -.- / ..-. --- .-. / .... . / .. ... / .- -... --- ..- - / - --- / -... ..- .-. -. / - .... .. ... / .--. .-.. .- -.-. . / .... ..- -- .- -. .-.-.- got"<< glorgoskuss <<" correct!! WOWIE YOU ARE GOODETH IN MATH"<< endl;
        
 }