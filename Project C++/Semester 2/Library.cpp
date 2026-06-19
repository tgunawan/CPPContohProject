#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
    public:
        string title, author;
        int quantity;

        Book(string title, string author, int quantity) {
            this->title = title;
            this->author = author;
            this->quantity = quantity;
        }
};

vector<Book> listBook;

void viewData() {
    cout << "List Book!" << endl;
    for (int i = 0; i < listBook.size();i++) {
        cout << i+1 << "\tJudul: " << listBook[i].title << endl << "\tAuthor: " << listBook[i].author << endl << "\tQuantity: " << listBook[i].quantity << endl;
    }
}

void addData() {
    string title, author;
    int quantity;

    cout << "Enter new title: ";
    getline(cin, title);

    cout << "Enter author: ";
    getline(cin, author);

    cout << "Book quantity: ";
    cin >> quantity;
    cin.ignore();

    Book new_book = Book(title, author, quantity);
    listBook.push_back(new_book);
    cout << "Success to add new book!" << endl;

}

void updateData() {}

void deleteUpdate() {}

int main() {
    int menu;

    while (true)
    {
        cout << "Menu!\n1. View\n2. Add\n> ";
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            viewData();
        } else if (menu == 2) {
            addData();
        }
    }
}