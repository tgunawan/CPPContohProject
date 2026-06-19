#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> user_list;

bool check_aphabet(string username) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < username.size(); i++) {
        for (int j = 0; j < alphabet.size(); j++) {
            if (username[i] == alphabet[j]) {
                return false;
            }
        }
    }
    return true;
}

bool check_capital(string username) {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < username.size(); i++) {
        for (int j = 0; j < alphabet.size(); j++) {
            if (username[i] == alphabet[j]) {
                return false;
            }
        }
    }
    return true;
}

bool check_symbol(string username) {
    string symbol = "~!@#$%^&*()_+{}[]|/;:.,><";

    for (int i = 0; i < username.size(); i++) {
        for (int j = 0; j < symbol.size(); j++) {
            if (username[i] == symbol[j]) {
                return false;
            }
        }
    }
    return true;
}

bool check_number(string username) {
    string number = "0123456789";

    for (int i = 0; i < username.size(); i++) {
        for (int j = 0; j < number.size(); j++) {
            if (username[i] == number[j]) {
                return false;
            }
        }
    }
    return true;
}

void sign_up() {
    string password, fullname, age, hobby, username;

    try {
        cout << "Enter the new username (no space allowed): ";
        cin >> username;

        if (username.size() < 6) {
            throw string("Sorry, your username to short!");
        }

        if (check_aphabet(username)) {
            throw string("username must contain both uppercase and lowercase letters");
        }

        if (check_capital(username)) {
            throw string("username must contain both uppercase and lowercase letters");
        }

        cout << "Enter the new password: ";
        cin >> password;
        cin.ignore();

        if (check_aphabet(password)) {
            throw string("password must contain both uppercase and lowercase letters");
        }

        if (check_capital(password)) {
            throw string("password must contain both uppercase and lowercase letters");
        }

        if (password.size() < 6) {
            throw string("Sorry, your password to short!");
        }

        if (check_number(password)) {
            throw string("Password must contain number!");
        }

        if (check_symbol(password)) {
            throw string("Password must contain special character (~!@#$%^&*()_+{}[]|/;:.,><)");
        }

        cout << "Enter your full name: ";
        getline(cin, fullname);

        cout << "How old are you now: ";
        cin >> age;
        cin.ignore();

        cout << "Tell us about your hobby: ";
        getline(cin, hobby);

        user_list.push_back({username, password, fullname, age, hobby});
        cout << "Successfully to create new account!\n";

    } catch (const string Err) {
        cout << "Error: " << Err << endl;
    }
}

void login() {
    string username, password;
    bool stats = true;
    bool avaib = true;
    try {
        cout << "Enter username: ";
        cin >> username;
        cin.ignore();

        cout << "Enter your password: ";
        getline(cin, password);

        for (vector<string> user: user_list) {
            if (username == user[0]) {
                avaib = false;
            }
        }

        if (avaib) {
            throw string("Username not found. Please register first!");
        }

        for (vector<string> user: user_list) {
            if ((username == user[0]) && (password == user[1])) {
                stats = false;
                cout << "Biodata" << endl << "Full name: " << user[2] << endl << "Age: " << user[3] << endl << "Hobby: " << user[4] << endl;
                break;
            }
        }

        if (stats) {
            throw string("Sorry username & password do not match!");
        }

    } catch (const string err) {
        cout << "Error: " << err << endl;
    }
}


int main() {
    int option;

    while (true)
    {
        cout << "Welcome to our media!\n1. Login\n2. Register\n3. Exit\n> ";
        cin >> option;
        cin.ignore();

        if (option == 1) {
            login();
        } else if (option == 2) {
            sign_up();
        } else {
            break;
        }

        cout << "Enter ..." << endl;
        cin.get();
    }
    
    return 0;
}