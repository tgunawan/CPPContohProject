
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ITEM
class Potion
{
public:
    string name;
    int heal;

    Potion(string n = "", int h = 0)
    {
        name = n;
        heal = h;
    }
};

class Weapon
{
public:
    string name;
    int damage;

    Weapon(string n = "", int d = 0)
    {
        name = n;
        damage = d;
    }
};

// FUNCTION TEMPLATE

template<typename T>
void PrintValue(T value)
{
    cout << value << endl;
}

template<typename T>
void SwapValue(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
int FindValue(vector<T> data, T target)
{
    for(int i=0;i<data.size();i++)
    {
        if(data[i]==target)
            return i;   
    }

    throw runtime_error("Data tidak ditemukan.");
}

// CLASS TEMPLATE

template<typename T>
class Inventory
{
private:
    vector<T> items;
    int maxSlot;

public:
    Inventory(int slot=5)
    {
        maxSlot = slot;
    }
    void AddItem(T item)
    {
        if(items.size()>=maxSlot)
            throw runtime_error("Inventory penuh!");
        items.push_back(item);
    }
    void RemoveItem(int index)
    {
        if(index<0 || index>=items.size())
            throw out_of_range("Index salah!");
        items.erase(items.begin()+index);
    }

    T GetItem(int index)
    {
        if(index<0 || index>=items.size())
            throw out_of_range("Index salah!");
        return items[index];
    }

    int Size()
    {
        return items.size();
    }

    vector<T>& GetAll()
    {
        return items;
    }
};

// SPECIALIZATION PRINT
void ShowPotion(Inventory<Potion>& inv)
{
    cout<<"===== Potion ====="<<endl;
    for(int i=0;i<inv.Size();i++)
    {
        Potion p = inv.GetItem(i);
        cout
        <<i+1<<". "<<p.name
        <<" Heal:"<<p.heal<<endl;
    }
}

void ShowWeapon(Inventory<Weapon>& inv)
{
    cout<<"===== Weapon ====="<<endl;
    for(int i=0;i<inv.Size();i++)
    {
        Weapon w = inv.GetItem(i);
        cout<<i+1<<". "<<w.name<<" Damage:"<<w.damage<<endl;
    }
}

int main()
{
    Inventory<Potion> potionBag(3);
    Inventory<Weapon> weaponBag(2);
    try
    {
        potionBag.AddItem(Potion("Small Potion",50));
        potionBag.AddItem(Potion("Medium Potion",100));
        potionBag.AddItem(Potion("Mega Potion",300));
        // sengaja error
        potionBag.AddItem(Potion("Ultra Potion",500));
    }
    catch(exception &e)
    {
        cout<<"ERROR : "<<e.what()<<endl;
    }
    cout<<endl;

    try
    {
        weaponBag.AddItem(Weapon("Wood Sword",10));
        weaponBag.AddItem(Weapon("Iron Sword",20));
        ShowWeapon(weaponBag);
        cout<<endl;
        weaponBag.RemoveItem(5);
    }
    catch(exception &e)
    {
        cout<<"ERROR : "<<e.what()<<endl;
    }
    cout<<endl;
    ShowPotion(potionBag);
    cout<<endl;
    cout<<"===== Function Template ====="<<endl;

    int gold1=100;
    int gold2=500;

    cout<<"Sebelum Swap"<<endl;
    cout<<gold1<<" "<<gold2<<endl;
    SwapValue(gold1,gold2);
    cout<<"Setelah Swap"<<endl;
    cout<<gold1<<" "<<gold2<<endl;
    cout<<endl;
    vector<int> level={1,2,3,4,5};

    try
    {
        int index=FindValue(level,4);
        cout<<"Level ditemukan di index "<<index<<endl;
        FindValue(level,10);

    }
    catch(exception &e)
    {
        cout<<"ERROR : "<<e.what()<<endl;
    }

    cout<<endl;
    PrintValue("Game Over");

    return 0;
}