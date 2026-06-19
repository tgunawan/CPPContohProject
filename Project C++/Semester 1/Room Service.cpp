#include <iostream>
#include <unistd.h>
#include <random>
using namespace std;
int main() {
  string Pizza, Burger, Spaghetti, Mineral_Water, Tea, Coffee, Cake, Ice_Cream, Biscuit;
  int amount;
  menu:
  int choice;
  int choose;
  string name;
  string cls= "\033[2J\033[1;1H";
  cout << "--------------------" << endl;
  cout << "Welcome to our menu!" << endl;
  cout << "--------------------" << endl;
  cout << "1. Main Food" << endl;
  cout << "2. Drinks" << endl;
  cout << "3. Desserts" << endl;
  cout << "4. Order" << endl;
  cin >> choice;
  switch(choice){
    case 1:
    cout << cls;
    cout << "--------------------" << endl;
    cout << "Main Food Menu" << endl;
    cout << "--------------------" << endl;
    cout << "1. Pizza (15$)" << endl;
    cout << "2. Burger (7$)" << endl;
    cout << "3. Spaghetti (10$)" << endl;
    cout << "Would you like to exit" << endl;
    cin >> choose; 
    if (choose==1){
      cout << cls;
      goto menu;
    }
  break;
    case 2:
      cout << cls;
      cout << "--------------------" << endl;
      cout << "Drinks Menu" << endl;
      cout << "--------------------" << endl;
      cout << "1. Mineral Water (1$)" << endl;
      cout << "2. Tea (1$)" << endl;
      cout << "3. Coffee (2$)" << endl;
      cout << "Would you like to exit" << endl;
      cin >> choose; 
      if (choose==1){
        cout << cls;
        goto menu;
      }
  break;
    case 3:
      cout << cls;
      cout << "--------------------" << endl;
      cout << "Dessert Menu" << endl;
      cout << "--------------------" << endl;
      cout << "1. Cake (7$)" << endl;
      cout << "2. Ice Cream (3$)" << endl;
      cout << "3. Biscuit (10$)" << endl;
      cout << "Would you like to exit" << endl;
      cin >> choose; 
      if (choose==1){
        cout << cls;
        goto menu;
      }
  break;
    case 4:
      cout << cls;
      cout << "--------------------" << endl;
      cout << "Your order"<< endl;
      cout << "--------------------" << endl;
      cout << "Please insert your order" << endl;
      cin >> name;
      cout << "How many would you like?" << endl;
      cin >> amount;
      
        
        if (name=="Pizza"){
          cout << amount << " Pizza for " << amount*15 << "$" << endl;
        }
      
        else if (name=="Burger"){
          cout << amount << " Burger for " << amount*7 << "$" << endl;
        }
       
       
        else if (name=="Spaghetti"){
          cout << amount << " Spaghetti for " << amount*10 << "$" << endl;
        }
        
        
        else if (name=="Mineral_Water"){
          cout << amount << " Mineral Water for " << amount*1 << "$" << endl;
        }
        
        
        else if (name=="Tea"){
          cout << amount << " Tea for " << amount*1 << "$" << endl;
        }
        
        else if (name=="Coffee"){
          cout << amount << " Coffee for " << amount*2 << "$" << endl;
        }
        
        else if (name=="Cake"){
          cout << amount << " Cake for " << amount*7 << "$" << endl;
        }
        
        else if (name=="Ice_Cream"){
          cout << amount << " Ice Cream for " << amount*3 << "$" << endl;
        }
        
        else if (name=="Biscuit"){
          cout << amount << " Biscuit for " << amount*10 << "$" << endl;
        }
      cout << "Thank you for your purchase\nRedirecting to the menu" << endl;
      sleep(2);
      cout << cls;
      goto menu;
    break;
  }
}