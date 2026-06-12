#include<iostream>
#include<string>
#include<random>

using namespace std;

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

        virtual void useSkill(){ // fungsi virtual yang bisa di modif oleh child class
            cout<<Name<<" menggunakan skill!"<<endl;
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
};
void displayMenu(){
    cout<<"Pleash choose your character : "<<endl;
    cout<<"1. Swordman"<<endl;
    cout<<"2. Ranger"<<endl;
    cout<<"3. Wizard"<<endl;
    cout<<"4. Priest"<<endl;
    cout<<"Enter the number of your choice: ";
}
int main(){
    cout<<"=== Simulasi RPG Game ==="<<endl;
    cout<<"Enter Your Name : ";
    string Name;
    cin>>Name;
    displayMenu();
    int choice;
    cin>>choice;
    MainCharacter* player;
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
    cout<<"=== Simulasi Pertarungan ==="<<endl;
    cout <<"You wake up in a Cave oF Unknown oRigin"<<endl;
    int i=0;
    do{
        cout<<"You see two paths in front of you."<<endl;
        cout <<"Would you like to go left or right?"<<endl;
        cout<<"1. Left"<<endl;
        cout<<"2. Right"<<endl;
        cout<<"Enter the number of your choice: ";
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
            cout<<"You encounter a monster!"<<endl;
        } else if (opportunity >80){
            cout<<"You walked safely !"<<endl;

        }
        else{
            cout<<"You Found The Exit!"<<endl;
            i++;
        }
        }
    while (i==0);
    cout<<"Out side U found a Vilage and a Forest"<<endl;
    cout<<"Where do you want to go?"<<endl;
    cout<<"1. Vilage"<<endl;
    cout<<"2. Forest"<<endl;
    cout<<"Enter the number of your choice: ";
    int choice2;
    cin>>choice2;
    if (choice2==1){
        cout<<"You go to the Vilage"<<endl;
    }
    else if (choice2==2){
        cout<<"You go to the Forest"<<endl;
    }
    else{
        cout<<"Invalid choice!"<<endl;
    

    }
    return 0;
}