#include<iostream>
#include<string>
#include<random>

using namespace std;

class Karakter;
Karakter* player = nullptr;

class MainCharacter{
    public:
        virtual void useSkill() = 0;
        virtual string getName()= 0;
        virtual ~MainCharacter(){};

        
};

int random(int min, int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(min, max);
    return distr(gen);
};
class Karakter : public MainCharacter{
    private:
        string Name;
        int Health_Point;

    public:
        // constructor
        Karakter(string inputName, int inputHealth_Point){
            Name=inputName;
            if (inputHealth_Point<5)Health_Point=10;
            else Health_Point=inputHealth_Point;
        };
        string getName() override {return Name;}
        int getHealthPoint(){return Health_Point;}

        //setter = jalur untuk ubah data private
        void receiveDamage(int damage){
            Health_Point-=damage;
            if (Health_Point<1) Health_Point=0;
            cout<<getName()<<"Menerima damage -"<<damage<<". Sisa darah "<<Health_Point<<endl;
        }
        void attack(){
            cout<<Name<<" melakukan serangan!"<<endl;
        }
        void heal(int healAmount){
            Health_Point+=healAmount;
            cout<<Name<<" menerima penyembuhan +"<<healAmount<<". Darah sekarang "<<Health_Point<<endl;
        }
        virtual void useSkill(){ // fungsi virtual yang bisa di modif oleh child class
            cout<<Name<<" menggunakan skill!"<<endl;
        }
        virtual void useUlti(){
            cout<<Name<<" menggunakan ulti!"<<endl;
        }
};
class Swordman: public Karakter{
    private:
        int Stamina;

    public:
        // memanggil constructor parent untuk baca (string inputNama, int inputDarah)
        Swordman(string inputName, int inputHealth_Point,int inputStamina):Karakter(inputName,inputHealth_Point),Stamina(inputStamina){}

        int getStamina(){return Stamina;}

        void useSkill() override{ 
            cout<<getName()<<" menggunakan skill = Sword Slash = "<<endl;
        }
        void useUlti() override{
            cout<<getName()<<" menggunakan ulti = 1000 Blade Slash = "<<endl;
        }
};
class Sword_Saint: public Swordman{
    private:
        int Mana;


    public:
        // memanggil constructor parent untuk baca (string inputNama, int inputDarah)
        Sword_Saint(string inputName, int inputHealth_Point,int inputStamina,int inputMana):Swordman(inputName,inputHealth_Point,inputStamina),Mana(inputMana){}

        int getMana(){return Mana;}

        void useSkill() override{ 
            cout<<getName()<<" menggunakan skill = Blade of Judgement = "<<endl;
        }
        void useUlti() override{
            cout<<getName()<<" menggunakan ulti =  Ulra Divine Exaltation = "<<endl;
        }
};

class Ranger: public Karakter{
    private:
        int Stamina;

    public:
        // memanggil constructor parent untuk baca (string inputNama, int inputDarah)
        Ranger(string inputName, int inputHealth_Point,int inputStamina):Karakter(inputName,inputHealth_Point),Stamina(inputStamina){}

        int getStamina(){return Stamina;}

        void useSkill() override{ 
            cout<<getName()<<" menggunakan skill = Piercing Arrow = "<<endl;
        }
        void useUlti() override{
            cout<<getName()<<" menggunakan ulti =  Rain of Arrows = "<<endl;
        }
};
class Wizard: public Karakter{
    private:
        int Mana;

    public:
        // memanggil constructor parent untuk baca (string inputNama, int inputDarah)
        Wizard(string inputName, int inputHealth_Point,int inputMana):Karakter(inputName,inputHealth_Point),Mana(inputMana){}

        int getMana(){return Mana;}

        void useSkill() override{ 
            cout<<getName()<<" menggunakan skill = Fireball = "<<endl;
        }
        void useUlti() override{
            cout<<getName()<<" menggunakan ulti =  Meteor Shower = "<<endl;
        }
};
class Priest: public Karakter{
    private:
        int HolyPower;

    public:
        // memanggil constructor parent untuk baca (string inputNama, int inputDarah)
        Priest(string inputName, int inputHealth_Point,int inputHolyPower):Karakter(inputName,inputHealth_Point),HolyPower(inputHolyPower){}

        int getHolyPower(){return HolyPower;}

        void useSkill() override{ 
            cout<<getName()<<" menggunakan skill = Holly Divine Interval Strike = "<<endl;
        }
        void useUlti() override{
            cout<<getName()<<" menggunakan ulti =  True Holy Light = "<<endl;
        }
};
class Wembu: public Karakter{
    private:
        int Stamina;

    public:
        // memanggil constructor parent untuk baca (string inputNama, int inputDarah)
        Wembu(string inputName, int inputHealth_Point,int inputStamina):Karakter(inputName,inputHealth_Point),Stamina(inputStamina){}

        int getStamina(){return Stamina;}

        void useSkill() override{ 
            cout<<getName()<<" menggunakan skill = Orbital Strike Cannnon = "<<endl;
        }
        void useUlti() override{
            cout<<getName()<<" menggunakan ulti =  Black Hole = "<<endl;
        }
};
void Run(){
    cout<<"You decided to Run."<<endl;
    int opportunity = random(1, 20);
    cout<<"Your opportunity number is "<<opportunity<<endl;
    if (opportunity > 15){
        cout<<"You successfully escaped!"<<endl;
    }
    else {
        cout<<"You failed to escape and got caught by the monster!"<<endl;
    }
}
void Fight(){
    if (!player) {
        cout<<"No player available to fight."<<endl;
        return;
    }
    cout<<"You decided to Fight."<<endl;
    cout<<"1. Attack"<<endl;
    cout<<"2. Use Skill"<<endl;
    cout<<"3. Use Ulti"<<endl;
    cout<<"4. Heal"<<endl;
    cout<<"Enter the number of your choice: ";
    int action;
    cin>>action;
    switch(action){
        case 1:
            cout<<"You chose to Attack!"<<endl;
            player->attack();
            break;
        case 2:
            cout<<"You chose to Use Skill!"<<endl;
            player->useSkill();
            break;
        case 3:
            cout<<"You chose to Use Ulti!"<<endl;
            player->useUlti();
            break;
        case 4:
            cout<<"You chose to Heal!"<<endl;
            player->heal(10);
            break;
        default:
            cout<<"Invalid choice!"<<endl;
            break;
    }    
}
void displayMenu(){
    cout<<"Pleash choose your character : "<<endl;
    cout<<"1. Swordman"<<endl;
    cout<<"2. Ranger"<<endl;
    cout<<"3. Wizard"<<endl;
    cout<<"4. Priest"<<endl;
    cout<<"Enter the number of your choice: ";
}
void characterSelection(){
cout<<"Enter Your Name : ";
    string Name;
    cin>>Name;
    displayMenu();
    int choice;
    cin>>choice;
    switch(choice){
        case 1:
            player = new Swordman(Name, 100, 100);
            cout <<"You have chosen Swordman!"<<endl;
            cout <<"Character Created:"<<endl;
            cout <<player->getName()<<endl;
            cout <<"Class: Swordman"<<endl;
            break;
        case 2:
            player = new Ranger(Name, 90, 110);
            cout <<"You have chosen Ranger!"<<endl;
            cout <<"Character Created:"<<endl;
            cout <<player->getName()<<endl;
            cout <<"Class: Ranger"<<endl;
            break;
        case 3:
            player = new Wizard(Name, 60, 140);
            cout <<"You have chosen Wizard!"<<endl;
            cout <<"Character Created:"<<endl;
            cout <<player->getName()<<endl;
            cout <<"Class: Wizard"<<endl;
            break;
        case 4:
            player = new Priest(Name, 70, 130);
            cout <<"You have chosen Priest!"<<endl;
            cout <<"Character Created:"<<endl;
            cout <<player->getName()<<endl;
            cout <<"Class: Priest"<<endl;
            break;
        case 999:
            player = new Wembu(Name, 200, 200);
            cout <<"You have chosen Wembu!"<<endl;
            cout <<"Character Created:"<<endl;
            cout <<player->getName()<<endl;
            cout <<"Class: Wembu"<<endl;
            break;
        default:
            cout<<"Invalid choice!"<<endl;
            break;
    }
}




void displayCaveMenu(){
        cout<<"You see two paths in front of you."<<endl;
        cout <<"Would you like to go left or right?"<<endl;
        cout<<"1. Left"<<endl;
        cout<<"2. Right"<<endl;
        cout<<"Enter the number of your choice: ";
}
void Cave(){
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
                    Fight();
                }
                else {
                    Run();
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
int main(){
    cout<<"=== Simulasi RPG Game ==="<<endl;
    characterSelection();
    cout<<"=== Simulasi Pertarungan ==="<<endl;
    Cave();
    cout<<"Out side U found a Vilage and a Forest"<<endl;
    cout<<"Where do you want to go?"<<endl;
    cout<<"1. Vilage"<<endl;
    cout<<"2. Forest"<<endl;
    cout<<"Enter the number of your choice: ";
    int choice;
    cin>>choice;
    if (choice==1){
        cout<<"You go to the Vilage"<<endl;

    }
    else if (choice==2){
        cout<<"You go to the Forest"<<endl;
    }
    else{
        cout<<"Invalid choice!"<<endl;
    

    }
    return 0;
}