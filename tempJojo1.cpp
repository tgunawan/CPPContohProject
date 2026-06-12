#include <iostream>
#include <string>

using namespace std;

string Menu[5]={"Rocket LPT 061","Rocket ShipfIk 003(Beta)","Bill Sitelilite mark 21","Paper Rocket","Black Hole"};

void clear(){
    cout<<"\033[2J\033[H";
}
void loading(){
    cout << "Loading";
    for (int i = 1; i <= 3; i++) {
        cout << ".";
        
    }
    cout << endl;
}
void Main_Menu(){
    cout << "Welcome to "<<endl<<"|\u001b[4mToko On\u001b[24m|" << endl << "|Lpt/ORg|" << endl;
    cout << "Please select a rocket to build:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << Menu[i] << endl;
    }
    cout << "Enter the number of your choice: ";
    
}
string Buiding_Rocket(int choice){
    if (choice >= 1 && choice <= 5) {
            cout << "You have selected: " << Menu[choice - 1] << endl;
            cout << "Building your rocket..." << endl;
            // Simulate building process
            cout << "Rocket built successfully!" << endl;
            return Menu[choice - 1];
        }
    else {
            cout << "Invalid choice. Please select a number between 1 and 5." << endl;
        return "";
        }
}
string Buiding_Rocket(string choice){
    if (choice == Menu[0] || choice == Menu[1] || choice == Menu[2] || choice == Menu[3] || choice == Menu[4]) {
            cout << "You have selected: " << choice << endl;
            cout << "Building your rocket..." << endl;
            // Simulate building process
            cout << "Rocket built successfully!" << endl;
            return choice;
        }
    else {
        cout << "Invalid choice. Please select a valid rocket name." << endl;
        return "";
    }
    }
void payment(){
    cout << "1. Credit Card" << endl;
    cout << "2. Roketbanking" << endl;
    cout << "3. qris" << endl;
    cout << "What Would Be your payment method?" << endl;

}
void Credit_Card(){
    string namecard,cardNumber, expiryDate, cvv;
    cout << "Enter the name on the card: ";
    cin >> namecard;
    cout << "Enter your credit card number: ";
    cin >> cardNumber;
    cout << "Enter the expiry date (MM/YY): ";
    cin >> expiryDate;
    cout << "Enter the CVV: ";
    cin >> cvv;
    cout << "Processing payment..." << endl;
    // Simulate payment processing
    cout << "Payment successful!" << endl;
}
void Roketbanking(){
    string username, password;
    cout << "Enter your Roketbanking username: ";
    cin >> username;
    cout << "Enter your Roketbanking password: ";
    cin >> password;
    cout << "Processing payment..." << endl;
    // Simulate payment processing
    cout << "Payment successful!" << endl;
}
void qris(){
    int ws;
    cout << "Please scan the QR code to complete the payment." << endl;
    cout << "███████████████████████████"<< endl;
    cout << "█      █  ██  █  █      █"<< endl;
    cout << "█ ████ █ ██  ███ █ ████ █"<< endl;
    cout << "█ ████ █  ██████ █ ████ █"<< endl;
    cout << "█      █ █ █ █ █ █      █"<< endl;
    cout << "███████████████████████████"<< endl;
    cout << "  █████  █ █  ██ ██  ███  "<< endl;
    cout << " ██ █ ████ █ █  █  █  █   "<< endl;
    cout << "  ███████ █  █   ██ █████ "<< endl;
    cout << "███████████████████████████"<< endl;
    cin >> ws;
    // Simulate QR code scanning and payment processing
    cout << "Payment successful!" << endl;
}


int main() {
    do{
        Main_Menu();
        int choice;
        cin >> choice;
        clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        Buiding_Rocket(choice);
        cin.get(); // Wait for user input before proceeding to payment
        clear();
        payment();
        int paymentChoice;
        cin >> paymentChoice;
        switch (paymentChoice) {
            case 1:
                Credit_Card();
                break;
            case 2:
                Roketbanking();
                break;
            case 3:
                qris();
                break;
            default:
                cout << "Invalid payment method. Please select a number between 1 and 3." << endl;
            cout << "Thank you for your purchase!" << endl;
        }
        
        
    }
    while (true);
    return 0;
}