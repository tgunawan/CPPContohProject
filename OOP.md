Ide yang bagus adalah membuat 1 project yang berkembang bertahap:

Materi 9: Membuat Library System sederhana dengan Class, Object, Attribute, Method, Constructor, dan Destructor.
Materi 10: Meng-upgrade project yang sama menggunakan Encapsulation, Inheritance, Polymorphism, dan Abstraction.

Dengan begitu siswa bisa melihat evolusi program dari OOP dasar sampai OOP lanjutan.

Materi 9 - Intro OOP
Step 1: Memahami Class dan Object
Analogi

Class = Cetakan/Blueprint

Class Book
 ├─ title
 ├─ author
 └─ status


Object = Hasil cetakan

Book book1;
Book book2;
Book book3;

Step 2: Membuat Class Sederhana
#include <iostream>
using namespace std;

class Book {
public:
    string title;
    string author;
    bool isBorrowed;

    void displayInfo() {
        cout << "Title : " << title << endl;
        cout << "Author: " << author << endl;

        if(isBorrowed)
            cout << "Status: Borrowed\n";
        else
            cout << "Status: Available\n";
    }
};

int main() {

    Book book1;

    book1.title = "Harry Potter";
    book1.author = "J.K. Rowling";
    book1.isBorrowed = false;

    book1.displayInfo();

    return 0;
}

Step 3: Constructor

Constructor akan otomatis dipanggil saat object dibuat.

#include <iostream>
using namespace std;

class Book {
public:
    string title;
    string author;
    bool isBorrowed;

    Book(string t, string a) {
        title = t;
        author = a;
        isBorrowed = false;

        cout << title << " created.\n";
    }

    void displayInfo() {
        cout << "\nTitle  : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Status : "
             << (isBorrowed ? "Borrowed" : "Available")
             << endl;
    }
};

int main() {

    Book book1("Harry Potter", "J.K. Rowling");
    Book book2("Atomic Habits", "James Clear");

    book1.displayInfo();
    book2.displayInfo();

    return 0;
}

Step 4: Destructor

Destructor dipanggil ketika object dihancurkan.

#include <iostream>
using namespace std;

class Book {
public:
    string title;

    Book(string t) {
        title = t;
        cout << title << " created.\n";
    }

    ~Book() {
        cout << title << " destroyed.\n";
    }
};

int main() {

    Book book1("Harry Potter");

    return 0;
}


Output:

Harry Potter created.
Harry Potter destroyed.

Step 5: Project Materi 9
Simple Library System
#include <iostream>
using namespace std;

class Book {
public:
    string title;
    string author;
    bool isBorrowed;

    Book(string t, string a) {
        title = t;
        author = a;
        isBorrowed = false;
    }

    void borrowBook() {
        isBorrowed = true;
    }

    void returnBook() {
        isBorrowed = false;
    }

    void displayInfo() {

        cout << "\nTitle : " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Status: ";

        if(isBorrowed)
            cout << "Borrowed\n";
        else
            cout << "Available\n";
    }
};

int main() {

    Book book1("Harry Potter", "J.K. Rowling");

    book1.displayInfo();

    cout << "\nBorrowing book...\n";
    book1.borrowBook();

    book1.displayInfo();

    return 0;
}

Materi 10 - Konsep Lanjutan OOP

Sekarang upgrade Project Library System.

1. Encapsulation

Data dibuat private agar tidak bisa diubah sembarangan.

Sebelum
book1.title = "";


Bisa diubah siapa saja.

Sesudah
class Book {
private:
    string title;

public:
    void setTitle(string t) {
        title = t;
    }

    string getTitle() {
        return title;
    }
};

Contoh Lengkap
class Member {
private:
    string name;

public:
    Member(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setName(string n) {
        name = n;
    }
};

2. Inheritance

Buat parent class Item.

class Item {
protected:
    string title;

public:
    Item(string t) {
        title = t;
    }

    void displayTitle() {
        cout << title << endl;
    }
};


Turunkan menjadi Book dan Magazine.

class Book : public Item {
public:
    Book(string t) : Item(t) {}
};

class Magazine : public Item {
public:
    Magazine(string t) : Item(t) {}
};

3. Polymorphism

Method yang sama menghasilkan perilaku berbeda.

Parent:

class Item {
public:
    virtual void displayInfo() {
        cout << "General Item\n";
    }
};


Child:

class Book : public Item {
public:
    void displayInfo() override {
        cout << "Book Information\n";
    }
};

class Magazine : public Item {
public:
    void displayInfo() override {
        cout << "Magazine Information\n";
    }
};


Penggunaan:

Item* items[2];

items[0] = new Book();
items[1] = new Magazine();

for(int i=0;i<2;i++) {
    items[i]->displayInfo();
}


Output:

Book Information
Magazine Information

4. Abstraction

Membuat class yang tidak boleh dibuat object secara langsung.

class Item {
public:
    virtual void displayInfo() = 0;
};


Tidak boleh:

Item item; // ERROR


Harus diturunkan.

class Book : public Item {
public:
    void displayInfo() override {
        cout << "Book\n";
    }
};

Final Project Materi 9 + 10
Enhanced Library System

Project akhir ini menerapkan:

✅ Class & Object
 ✅ Constructor & Destructor
 ✅ Encapsulation
 ✅ Inheritance
 ✅ Polymorphism
 ✅ Abstraction

#include <iostream>
#include <vector>
using namespace std;

/*
    ABSTRACT CLASS
*/
class Item {
protected:
    string title;

public:
    Item(string t) {
        title = t;
    }

    virtual void displayInfo() = 0;

    virtual ~Item() {
        cout << title << " removed.\n";
    }
};

/*
    BOOK
*/
class Book : public Item {
private:
    string author;
    bool borrowed;

public:
    Book(string t, string a)
        : Item(t) {

        author = a;
        borrowed = false;
    }

    void borrowBook() {
        borrowed = true;
    }

    void returnBook() {
        borrowed = false;
    }

    string getTitle() {
        return title;
    }

    void displayInfo() override {

        cout << "\n[BOOK]\n";
        cout << "Title  : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Status : "
             << (borrowed ? "Borrowed" : "Available")
             << endl;
    }
};

/*
    MAGAZINE
*/
class Magazine : public Item {
private:
    int edition;

public:
    Magazine(string t, int e)
        : Item(t) {

        edition = e;
    }

    void displayInfo() override {

        cout << "\n[MAGAZINE]\n";
        cout << "Title   : " << title << endl;
        cout << "Edition : " << edition << endl;
    }
};

/*
    MEMBER
*/
class Member {
private:
    string name;

public:
    Member(string n) {
        name = n;
    }

    string getName() {
        return name;
    }
};

int main() {

    Member member1("Budi");

    vector<Item*> library;

    library.push_back(
        new Book(
            "Harry Potter",
            "J.K. Rowling"
        )
    );

    library.push_back(
        new Magazine(
            "National Geographic",
            2025
        )
    );

    cout << "Member: "
         << member1.getName()
         << endl;

    cout << "\n=== LIBRARY ITEMS ===\n";

    for(Item* item : library) {
        item->displayInfo();
    }

    for(Item* item : library) {
        delete item;
    }

    return 0;
}

Urutan Penyampaian di Kelas

Materi 9

Class & Object
Attribute & Method
Constructor
Destructor
Mini Project: Simple Library System

Materi 10

Encapsulation → Member
Inheritance → Item → Book/Magazine
Polymorphism → displayInfo()
Abstraction → abstract class Item
Final Project: Enhanced Library System

Dengan alur ini siswa akan merasa sedang mengembangkan project yang sama secara bertahap, bukan membuat project baru setiap materi. Ini biasanya jauh lebih mudah dipahami untuk pemula C++.