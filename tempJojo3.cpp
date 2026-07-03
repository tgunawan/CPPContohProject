// Header file untuk library yang  di gunakan
#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

// Struct dan class yang akan di pakai
// Struct
struct SaveData {
    string name;
    string job;
    int hp;
    int attack;
    int coin;
};
//Class
class Hero{
    protected:
        string name;
        string job;
        int hp;
        int attack;
        int coin;

    public:
        Hero()
        {
            name="";
            job="Hero";
            hp=100;
            attack=5;
            coin=0;
        }
        virtual ~Hero(){}
        
        virtual void SetStat(){}

        //setter
        void SetName(string n){
            name=n;
        }
        void SetCoin(int c){
            coin=c;

        }

        //getter
        string GetName(){
            return name;
        }
        string GetJob(){
            return job;
        }
        int GetHP(){
            return hp;
        }
        int GetAttack(){
            return attack;
        }
        int GetCoin(){
            return coin;
        }
        
        //function / method
        void Coinadd(int c){
            coin+=c;
        }
        virtual void showstatus(){
            cout << "======================" << endl;
            cout << "Name: " << name << endl;
            cout << "Job: " << job << endl;
            cout << "HP: " << hp << endl;
            cout << "Attack: " << attack << endl;
            cout << "Coin: " << coin << endl;
            cout << "======================" << endl;
        }

};


//==============
// child Class
//==============

class Villager : public Hero{
    public:
        Villager(){
            SetStat();
        }
        void SetStat() override{
            job="Villager";
            hp=80;
            attack=3;
        }
};

class Swordman : public Hero{
    public:
        Swordman(){
            SetStat();
        }
        void SetStat() override{
            job="Swordman";
            hp=120;
            attack=10;
        }
};

class Archer : public Hero{
    public:
        Archer(){
            SetStat();
        }
        void SetStat() override{
            job="Archer";
            hp=80;
            attack=15;
        }
};

class Priest : public Hero{
    public:
        Priest(){
            SetStat();
        }
        void SetStat() override{
            job="Priest";
            hp=100;
            attack=2;
        }
};

// Prototype function
Hero* CreateCharacter();
void SaveGame(Hero* player, string filename);
Hero* LoadGame(string filename);
void WorldMenu(Hero*& player);

void Tavern(Hero*& player);
//void Cave(Hero*& player);
void Home(Hero*& player);

int random(int min, int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(min, max);
    return distr(gen);
};
Hero* CreateCharacter(){
    string name;
    cout << "Enter your character's name: ";
    cin.ignore();
    getline(cin, name);
    Hero* player = new Villager(); // Default job is Villager
    player->SetName(name);
    cout << "Character created successfully!" << endl;
    cout << "Class: " << player->GetJob() << endl;

    SaveGame(player, "save1.txt"); // Save the game after character creation
    return player;
}
void displayCaveMenu(){
        cout<<"You see two paths in front of you."<<endl;
        cout <<"Would you like to go left or right?"<<endl;
        cout<<"1. Left"<<endl;
        cout<<"2. Right"<<endl;
        cout<<"Enter the number of your choice: ";
}
void Cave(Hero* player){
    int i=0;
    cout <<"You wake up in a Cave oF Unknown oRigin"<<endl;
    do{
        displayCaveMenu();
        int direction;
        cin>>direction;
        if (direction==1){
            cout<<"You decided to go Left."<<endl;
        }
        else if (direction==2){
            cout<<"You decided to go Right."<<endl;
            direction=1;
        }
        else {
            cout<<"Invalid choice!"<<endl;
            continue;
        }
            
            int opportunity = random(1, 100);
            cout<<"Your opportunity number is "<<opportunity<<endl;
            if (opportunity > 50){
                // cout<<"You encounter a monster!"<<endl;
                cout<<"What will you do?"<<endl;
                cout<<"1. Fight"<<endl;
                cout<<"2. Run"<<endl;
                cout<<"Enter the number of your choice: ";
                int action;
                cin>>action;
                if (action==1){
                    cout<<"You just won dont ask me how"<<endl;
                    break;
                    
                    }
                else {
                    continue;
                }
            }
            else if (opportunity >80){
                cout<<"You walked safely !"<<endl;

            }
            else{
                cout<<"You Found The Exit!"<<endl;
                i++;
            }
    }
    while (i==0);
}
void WorldMenu(Hero*& player) {
    if (player == nullptr) {
        return;
    }

    int pilihan;
    do {

        //opsi show status player
        
        cout << "=== World Menu ===" << endl;
        cout << "1. Tavern" << endl;
        cout << "2. Cave" << endl;
        cout << "3. Home" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "Tavern belum diimplementasikan." << endl;
                break;
            case 2:
                Cave(player);
                break;
            case 3:
                cout << "Home belum diimplementasikan." << endl;
                break;
            case 4:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (true);
}

void SaveGame(Hero* player, string filename){
    ofstream file(filename);
    if (!file){
        cout << "Failed to open file / File Corupt." << endl;
        return;
    }
    file << player->GetName() << endl;
    file << player->GetJob() << endl;
    file << player->GetHP() << endl;
    file << player->GetAttack() << endl;
    file << player->GetCoin() << endl;
    file.close();
    
    cout << "Game saved successfully to " << filename << endl;
};

Hero* LoadGame(string filename){
    SaveData data;
    ifstream file(filename);
    if (!file){
        cout << "Failed to open file / File Corupt." << endl;
        return nullptr;
    }

    getline(file, data.name);
    getline(file, data.job);
    file >> data.hp;
    file >> data.attack;
    file >> data.coin;
    file.close();

    Hero* player;
    if (data.job == "Villager") {
        player = new Villager();
    }
    else if (data.job == "Swordman") {
        player = new Swordman();
    }
    else if (data.job == "Archer") {
        player = new Archer();
    }
    else if (data.job == "Priest") {
        player = new Priest();
    }
    else {
        player = new Villager();
        cout << "Unknown job type in save file." << endl;

    }

    player->SetName(data.name);
    player->SetCoin(data.coin);
    return player;
};




// Main function


int main() {
    Hero* player = nullptr;// Pointer untuk menyimpan data player
    
    int pilih;
    do{
        cout << "=== Text RPG ===" << endl;
        cout << "=== Main Menu ===" << endl;
        cout << "1. Create Character" << endl;
        cout << "2. Load Game" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch(pilih){
            case 1:
                if (player != nullptr) {
                    delete player;
                    player = nullptr;
                }
                player = CreateCharacter();
                WorldMenu(player);
                break;
            case 2:
                if (player != nullptr) {
                    delete player;
                    player = nullptr;
                }
                player = LoadGame("save1.txt");
                WorldMenu(player);
                break;
            case 3:
                cout << "Exiting the game." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (pilih!=3);
    if (player != nullptr) {
        delete player; // Menghapus objek player jika sudah dibuat
        player = nullptr; // Mengatur pointer menjadi nullptr setelah dihapus
    }


    return 0;
}








