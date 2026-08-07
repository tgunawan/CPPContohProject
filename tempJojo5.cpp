#include <iostream>
#include <random>
#include <vector> // wadah vector
#include <map> // wadah map
#include <set> // wadah set
#include <algorithm> // algoritma STL (Sort,Find,...)
#include <string>
#include <chrono>

using namespace std;

struct Polemon
{
    string name;
    int hp;
    int attack;
    string type;
};

int random(int min, int max){
    // static random_device rd;
    // static mt19937_64 gen(rd());
    // uniform_int_distribution<int> distr(min, max);
    // return distr(gen);
    static mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distr(min,max);
    return distr(gen);
};

void displayPolemon(const vector<Polemon>& Pokedex)
{
    for (int i = 0; i < Pokedex.size(); i++)
    {
        cout<<i+1<<". ";
        cout<<"Name: "<<Pokedex[i].name<<endl;
        cout<<"HP: "<<Pokedex[i].hp<<endl;
        cout<<"Attack: "<<Pokedex[i].attack<<endl;
        cout<<"Type: "<<Pokedex[i].type<<endl;
    }
};
string randomType(){
    vector<string> types= {
    "Leafe","Toxic","FLame","Levetating","wet",
    "Battery","Dirt","Stone","Magic",
    "Cold","Lizard","VOID","Metal", "Spirit" };

    int opport= random(1,10);
    cout<<"Opportunity: "<<opport;

    if (opport>3){
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
void catchPolemon(vector<Polemon>& Pokedex)
{
    cout<<"Enter the number of your choice: ";
    cout<<"You Discovered a wild Polemon!"<<std::endl;
    cout<<"WHAT???? This pokemon Has not beed Discovered before"<<endl;
    cout<<"You have added this Polemon to your Pokedex!"<<endl;
    string tipe = randomType();
    cout<<"It has type: "<<tipe<<endl;
    cout<<"What will you name it??"<<endl;
    cout<<"Enter the name of your new Polemon: ";
    string newName;
    cin>>newName;
    int Hp= random(45,120);
    int Atack= random(50,130);
    Pokedex.push_back({newName, Hp, Atack, tipe});
    displayPolemon(Pokedex);
}
int main(){
    cout<<"Daftar Polemon:"<<std::endl;
    vector<Polemon> Pokedex;

    Pokedex.push_back({"Bulasout", 45, 49, "Grass/Poison"});
    Pokedex.push_back({"ivasout", 90, 55, "Grass/Poison"});
    Pokedex.push_back({"vebusout",100, 57, "Grass/Poison"});
    Pokedex.push_back({"chachachamander", 40, 50, "Fire"});
    Pokedex.push_back({"chachachameleron", 46, 59, "Fire"});
    Pokedex.push_back({"chachacharizz", 67, 70, "Fire/Flying"});
    cout<<"======================"<<endl;
    cout<<"Welcome to the Polemon World!"<<endl;
    cout<<"You are a Polemon Profesor who is looking for new Polemons"<<endl;
    cout<<"What will you do?"<<endl;
    cout<<"1. Catch a wild Polemon"<<endl;
    cout<<"2. See your Pokedex"<<endl;
    cout<<"3. Exit"<<endl;
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"You chose to Catch a wild Polemon!"<<endl;
            catchPolemon(Pokedex);
            break;
        case 2:
            cout<<"You chose to See your Pokedex!"<<endl;
            displayPolemon(Pokedex);
            cout<<"======================"<<endl;
            cout<<"1. edit Pokedex"<<endl;
            cout<<"2. Delete a Polemon From your Pokedex"<<endl;
            cout<<"3. Exit"<<endl;
            int choice2;
            cin>>choice2;
            switch(choice2){
                case 1:
                    cout<<"You chose to edit your Pokedex!"<<endl;
                    Pokedex[1].name="Jojo";
                    break;
                case 2:
                    cout<<"You chose to Delete a Polemon From your Pokedex!"<<endl;
                    cout<<"Enter the number of the Polemon you want to delete: ";
                    int i;
                    cin>>i;
                    Pokedex.erase(Pokedex.begin() + i);
                    break;
                case 3:
                    cout<<"You chose to Exit!"<<endl;
                    return 0;
                default:
                    cout<<"Invalid choice!"<<endl;
                    return 0;
            }
            break;
        case 3:
            cout<<"You chose to Exit!"<<endl;
            return 0;
        default:
            cout<<"Invalid choice!"<<endl;
            return 0;
    }


    return 0;
}