// RPG
// Karakter Utama -> Karakter -> Penyihir
// main program

#include<iostream>
#include<string>
using namespace std;

//AbstractClass / Class induk
class KarakterUtama{
    public:
        virtual void gunakanSkill() = 0;
        virtual string getName() = 0; // Pure virtual Function -> Kunci dari abstraction di c++
        virtual ~KarakterUtama(){}
};

// Inheritance
class Karakter : public KarakterUtama{
    private:
        string nama;
        int darah;

    public:
        // constructor
        Karakter(string inputNama, int inputDarah){
            nama=inputNama;
            if (inputDarah<5)darah=10;
            else darah=inputDarah;
        }

        //Getter =jalur untuk mengambil data private
        string getName() override {return nama;}
        int getDarah(){return darah;}

        //setter = jalur untuk ubah data private
        void terimaDamage(int damage){
            darah-=damage;
            if (darah<1) darah=0;
            cout<<nama<<"Menerima damage -"<<damage<<". Sisa darah "<<darah<<endl;
        }

        virtual void serang(){ // fungsi virtual yang bisa di modif oleh child class
            cout<<nama<<" menyerang  dengan pukulan biasa!"<<endl;
        }
};

class Penyihir: public Karakter{
    private:
        int mana;

    public:
        // memanggil constructor parent untuk baca (string inputNama, int inputDarah)
        Penyihir(string inputNama, int inputDarah,int inputMana):Karakter(inputNama,inputDarah),mana(inputMana){}

        int getMana(){return mana;}

        void serang()override{ 
            cout<<getName()<<" menyerang  dengan bola api!(Mana tersisa:"<<mana<<")"<<endl;
        }

        void gunakanSkill() override{
            cout<<getName()<<" mengeluarkan skill =Bola api="<<endl;
        }
};

int main(){
    cout<<"=== Simulasi RPG Game ==="<<endl;
    Penyihir player1("Gandalf",100,100); // buat object
    // player1.darah=1000;

    player1.terimaDamage(20);

    Karakter* hero= &player1; // buat pointer bertipe parent atau induk tapi menunjuk objek anak (polymorph)

    hero->serang(); // memanggil fungsi milik penyihir 
    hero->gunakanSkill();
    return 0;
}

// Next buat text based RPG
// karakter : Wizard, Swordman, Archer, Assassin, KIng 
