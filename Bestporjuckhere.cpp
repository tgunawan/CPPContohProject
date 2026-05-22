#include <iostream>
#include <random>
using namespace std;
int username(int a){
    return a;
}
string username(string a){
    return a;
}
void clear(){
    cout<<"\033[2J\033[H";
}
void wait(){
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}
int random( int a = 0, int b = 10 ) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> distr(a,b);
    return distr(gen);
}
void login(int &username) {
    cout << "Would u like to use 1.username or 2.id?" << endl;
    cin>>username;
    switch (username)
    {
        case 1:
            cout << "Enter your username: ";
                string name;
                cin >> name;
            break;
        case 2:
            cout << "Enter your ID: ";
                int name;
                cin >> name;
            break;
        
        default:
            break;
    }
}
void Soalplus(int &score) {
    int a = random();
    int b = random();
    int c;
    int aswer = a + b;
    cout << a<< "+" << b <<"=";
    cin >> c;
    if (c == aswer) {
        cout << "Correct!" << endl;
        score++;
        wait();
    } 
    else if (c == aswer + 1 || c == aswer - 1) {
        cout << "Almost! The correct answer is " << aswer << "." << endl;
        wait();
    }
    else {
        cout << "Wrong! The correct answer is " << aswer << "." << endl;
        wait();
    }


}
int main() {  
    int score = 0;
    int username;
    cout << "Welcome to the Math Quiz!" << endl;

    for (int i = 0; i < 10; i++) {

        clear();
        cout << "Score: " << score << endl;
        Soalplus(score);
    }
    clear();
    cout <<"Congratulations! "<< name << "Your final score is: " << score << endl;
    return 0;
}