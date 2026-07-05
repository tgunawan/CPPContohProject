// todo list
//1 to do
//2 on progress
//3 done

//gatcha char 
// Header file untuk library yang  di gunakan
#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

// Struct dan class yang akan di pakai
// Struct
struct plAYER{
    string username;
    int pulls;
    int commonpets;
    int rarepets;
    int legendarypets;

};
int random(int min, int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(min, max);
    return distr(gen);
};
void clear(){
    cout<<"\033[2J\033[H";
}
void wait(){
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}
void SaveGame(const plAYER& data, const string& filename) {
    ofstream file(filename);
    if (!file){
        cout << "Failed to open file / File Corupt." << endl;
        return;
    }
    file << data.username << endl;
    file << data.pulls << endl;
    file << data.commonpets << endl;
    file << data.rarepets << endl;
    file << data.legendarypets << endl;
    file.close();
}
void LoadGame(plAYER& data, const string& filename) {
    ifstream file(filename);
    if (!file){
        cout << "Failed to open file / File Corupt." << endl;
        return;
    }
    getline(file, data.username);
    file >> data.pulls;
    file >> data.commonpets;
    file >> data.rarepets;
    file >> data.legendarypets;
    file.close();
}
void mainMenu(){
    cout << "=== Not Gatcha Game ===" << endl;
    cout << "Welcome to the game!" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "Enter your choice: ";
}
void Menu1(){
    cout << "=== Main Menu ===" << endl;
    cout<<"1. Pull" <<endl;
    cout<<"2. Show Stats" <<endl;
    cout<<"3. save/exit" <<endl;
}
void signup(plAYER& data){
    cout << "Enter your username: ";
    string username;

    cin >> username;
    data.username = username;
    data.pulls = 0;
    data.commonpets = 0;
    data.rarepets = 0;
    data.legendarypets = 0;
    SaveGame(data, "save1.txt");
}
void Pulls(plAYER& data){
    data.pulls++;
            cout << "Pulling..." << endl;
            int result = random(1, 100);
            if (result <= 70) {
                cout << "You got Nothing!" << endl;
            } else if (result <= 90) {
                cout << "You got a Common Pet!" << endl;
                data.commonpets++;
            } else if (result <= 99) {
                cout << "You got a Rare Pet!" << endl;
                data.rarepets++;
            } else {
                cout << "You got a legendary Pet!" << endl;
                data.legendarypets++;
            }
}
void ShowStats(const plAYER& data) {
    cout << "Username: " << data.username << endl;
    cout << "Total Pulls: " << data.pulls << endl;
    cout << "Common Pets: " << data.commonpets << endl;
    cout << "Rare Pets: " << data.rarepets << endl;
    cout << "Legendary Pets: " << data.legendarypets << endl;
}


//Main code fr short cus i smart like that bruh like cool dude

int main() {
    plAYER playerData;
    mainMenu();
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 2) {
        cout << "Loading game..." << endl;
        LoadGame(playerData, "save1.txt");
        cout << "Welcome back, " << playerData.username << "!" << endl;
    }
    else if (choice == 1) {
        cout << "Starting new game..." << endl;
        signup(playerData);
    }   
    else {
        cout << "Invalid choice. Exiting." << endl;
        return 0;
    }
    wait();
    clear();
    do {
        Menu1();
        cout<<"Enter the number of your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                Pulls(playerData);
                break;
            case 2:
                ShowStats(playerData);
                break;
            case 3:           
                cout << "Saving progress..." << endl;
                SaveGame(playerData, "save1.txt");
                cout << "Exiting the game." << endl;
                break;
            default:
                cout << "Invalid choice. Please select a number between 1 and 3." << endl;
                break;
            
        }
        wait();
        clear();
    }
    while (choice != 3);
    return 0;
}