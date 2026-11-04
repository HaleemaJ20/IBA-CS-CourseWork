#include <iostream>
using namespace std;

class Character {
protected:
    string name;
    int health;
    int level;

public:
    Character(string n, int h, int l) {
        name = n;
        health = h;
        level = l;
    }

    virtual void attack() {
        cout << "Character " << name << " attacks!" << endl;
    }

    virtual void defend() {
        cout << "Character " << name << " defends!" << endl;
    }

    virtual void displayStats() {
        cout << "Name: " << name
             << ", Health: " << health
             << ", Level: " << level << endl;
    }

    // Non-virtual function (to demonstrate difference)
    void nonVirtualFunction() {
        cout << "Base class non-virtual function called." << endl;
    }

    virtual ~Character() {
        cout << "Character destructor called for " << name << endl;
    }
};

class Warrior : public Character {
private:
    string weaponType;

public:
    Warrior(string n, int h, int l, string w)
        : Character(n, h, l) {
        weaponType = w;
    }

    void attack() override {
        cout << "Warrior " << name
             << " swings " << weaponType
             << " dealing heavy damage!" << endl;
    }

    void defend() override {
        cout << "Warrior " << name
             << " raises shield to block!" << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Weapon: " << weaponType << endl;
    }
};

class Mage : public Character {
private:
    int manaPoints;

public:
    Mage(string n, int h, int l, int m)
        : Character(n, h, l) {
        manaPoints = m;
    }

    void attack() override {
        cout << "Mage " << name
             << " casts fireball using "
             << manaPoints << " mana!" << endl;
    }

    void defend() override {
        cout << "Mage " << name
             << " creates magical barrier!" << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Mana Points: " << manaPoints << endl;
    }
};

class Archer : public Character {
private:
    int arrowCount;

public:
    Archer(string n, int h, int l, int a)
        : Character(n, h, l) {
        arrowCount = a;
    }

    void attack() override {
        cout << "Archer " << name
             << " shoots arrow! "
             << arrowCount << " arrows remaining." << endl;
    }

    void defend() override {
        cout << "Archer " << name
             << " rolls to evade!" << endl;
    }

    void displayStats() override {
        Character::displayStats();
        cout << "Arrows: " << arrowCount << endl;
    }
};

int main() {

    Character* characters[5];

    characters[0] = new Warrior("Thor", 150, 5, "Axe");
    characters[1] = new Mage("Merlin", 100, 7, 200);
    characters[2] = new Archer("Robin", 120, 4, 30);
    characters[3] = new Warrior("Leon", 160, 6, "Sword");
    characters[4] = new Mage("Zara", 90, 8, 250);

    cout << "Display Stats" << endl;
    for (int i = 0; i < 5; i++) {
        characters[i]->displayStats();
        cout << endl;
    }

    cout << "Attack Phase" << endl;
    for (int i = 0; i < 5; i++) {
        characters[i]->attack();  
    }

    cout << endl << "Defense Phase" << endl;
    for (int i = 0; i < 5; i++) {
        characters[i]->defend();  
    }

    cout << endl << "===== Non-Virtual Function Demo =====" << endl;
    characters[0]->nonVirtualFunction();
    // This calls base class version because it is NOT virtual.
    // Non-virtual functions are resolved at compile time
    // (Static Binding), not runtime.

    cout << endl << "Deleting Objects" << endl;
    for (int i = 0; i < 5; i++) {
        delete characters[i];  
    }

    return 0;
}
