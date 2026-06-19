#include <iostream>
#include <vector>
#include <memory>

using namespace std;  

class Animal {
public:
    virtual ~Animal() = default;
    virtual void speak() const {
        std::cout << "Animal makes a sound\n";
    }
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Dog says: Woof!\n";
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Cat says: Meow!\n";
    }
};

// fungsi polymorphic yang menerima referensi ke base class
void makeSpeak(const Animal& animal) {
    animal.speak();
}

int main() {
    Dog dog;
    Cat cat;

    std::cout << "Direct calls (overriding):\n";
    dog.speak();
    cat.speak();

    std::cout << "\nPolymorphic calls through base reference: \n";
    makeSpeak(dog);
    makeSpeak(cat);

    // std::cout << "\nPolymorphism with pointers: \n";
    // std::vector<std::unique_ptr<Animal>> animals;
    // animals.push_back(std::make_unique<Dog>());
    // animals.push_back(std::make_unique<Cat>());

    // for (const auto& animalPtr : animals) {
    //     animalPtr->speak();
    // }

    return 0;
}
