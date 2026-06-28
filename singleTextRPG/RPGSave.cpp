// Header file untuk library yang  di gunakan
#include <iostream>
#include <fstream>
#include <string>

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
// Hero* CreateCharacter();
void SaveGame(Hero* player, string filename);
Hero* LoadGame(string filename);

void Tavern(Hero*& player);
void Cave(Hero*& player);
void Home(Hero*& player);
void WorldMenu(Hero*& player);

Hero* CreateCharacter(){
    string name;
    cout << "Enter your character's name: ";
    cin.ignore();
    getline(cin, name);
    Hero* player = new Villager(); // Default job is Villager
    player->SetName(name);
    cout << "Character created successfully!" << endl;
    cout << "Class: " << player->GetJob() << endl;

    return player;
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
                cout << "Cave belum diimplementasikan." << endl;
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








//67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67 67