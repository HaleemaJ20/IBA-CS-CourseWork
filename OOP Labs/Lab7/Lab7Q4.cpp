#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

class Animal {
protected:
    string name;
    int age;
public:
    Animal(string n, int a) {
        name = n;
        age = a;
    }

    virtual void makeSound() = 0;

    virtual void displayInfo() {
        cout << "Name: " << name << " Age: " << age << endl;
    }

    virtual ~Animal() {}
};

class Lion : public Animal {
    int maneLengthCm;
public:
    Lion(string n, int a, int m) : Animal(n,a) {
        maneLengthCm = m;
    }

    void makeSound() {
        cout << name << " roars!" << endl;
    }

    void performTrick() {
        cout << name << " jumps through a hoop!" << endl;
    }

    void displayInfo() {
        cout << "Name: " << name << " Age: " << age
             << " Mane Length: " << maneLengthCm << " cm" << endl;
    }
};

class Penguin : public Animal {
    double swimSpeedKmh;
public:
    Penguin(string n, int a, double s) : Animal(n,a) {
        swimSpeedKmh = s;
    }

    void makeSound() {
        cout << name << " squawks!" << endl;
    }

    void swim() {
        cout << name << " swims at " << swimSpeedKmh << " km/h!" << endl;
    }

    void displayInfo() {
        cout << "Name: " << name << " Age: " << age
             << " Swim Speed: " << swimSpeedKmh << " km/h" << endl;
    }
};

class Parrot : public Animal {
    int vocabulary;
public:
    Parrot(string n, int a, int v) : Animal(n,a) {
        vocabulary = v;
    }

    void makeSound() {
        cout << name << " talks!" << endl;
    }

    void speak(string phrase) {
        cout << name << " says: " << phrase << endl;
    }

    void displayInfo() {
        cout << "Name: " << name << " Age: " << age
             << " Vocabulary: " << vocabulary << endl;
    }
};

void trainAnimal(Animal* a) {
    Lion* l = dynamic_cast<Lion*>(a);

    if (l)
        l->performTrick();
    else
        cout << "This animal cannot be trained for tricks." << endl;
}

void makeAnimalSwim(Animal& a) {
    try {
        Penguin& p = dynamic_cast<Penguin&>(a);
        p.swim();
    }
    catch (bad_cast& e) {
        cout << "This animal cannot swim: " << e.what() << endl;
    }
}

void countByType(vector<Animal*>& zoo) {

    int lions = 0;
    int penguins = 0;
    int parrots = 0;

    for (int i = 0; i < zoo.size(); i++) {

        if (dynamic_cast<Lion*>(zoo[i]))
            lions++;
        else if (dynamic_cast<Penguin*>(zoo[i]))
            penguins++;
        else if (dynamic_cast<Parrot*>(zoo[i]))
            parrots++;
    }

    cout << "Lions: " << lions << endl;
    cout << "Penguins: " << penguins << endl;
    cout << "Parrots: " << parrots << endl;
}

int main() {

    vector<Animal*> zoo;

    zoo.push_back(new Lion("Simba",5,30));
    zoo.push_back(new Penguin("Pingo",3,12.5));
    zoo.push_back(new Parrot("Polly",2,100));
    zoo.push_back(new Lion("Leo",6,35));
    zoo.push_back(new Penguin("Skipper",4,15));
    zoo.push_back(new Parrot("Rio",3,80));

    for (int i = 0; i < zoo.size(); i++) {
        zoo[i]->makeSound();
        zoo[i]->displayInfo();
    }

    trainAnimal(zoo[0]);
    trainAnimal(zoo[2]);

    makeAnimalSwim(*zoo[1]);
    makeAnimalSwim(*zoo[0]);

    countByType(zoo);

    for (int i = 0; i < zoo.size(); i++) {
        delete zoo[i];
    }

    return 0;
}
