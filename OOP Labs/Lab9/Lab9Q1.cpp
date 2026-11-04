#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class LootBox {
private:
    vector<T> items;

public:
    void (*onOpen)(LootBox<T>&);

    LootBox(void (*behavior)(LootBox<T>&)) {
        onOpen = behavior;
    }

    void add(T item) {
        items.push_back(item);
    }

    T remove() {
        if (items.empty()) {
            throw runtime_error("Box is empty!");
        }
        T temp = items.back();
        items.pop_back();
        return temp;
    }

    T peek() {
        if (items.empty()) {
            throw runtime_error("Box is empty!");
        }
        return items.back();
    }

    void open() {
        onOpen(*this);
    }

    vector<T>& getItems() {
        return items;
    }

    void clear() {
        items.clear();
    }
};

template <typename T>
void normalOpen(LootBox<T>& box) {
    cout << "You opened the chest! Loot inside:\n";
    for (auto& item : box.getItems()) {
        cout << "- " << item << endl;
    }
}

template <typename T>
void mimicAttack(LootBox<T>& box) {
    cout << "IT'S A MIMIC!!! \n";
    cout << "The chest attacks you violently!\n";
    cout << "All loot is lost...\n";
    box.clear();
}

template <typename T>
void swapBehaviour(LootBox<T>& box, void (*newBehavior)(LootBox<T>&)) {
    box.onOpen = newBehavior;
}

int main() {
    //normal chest
    LootBox<string> chest(normalOpen<string>);
    chest.add("Sword");
    chest.add("Shield");

    chest.open();

    //swapped to mimic

    cout << "\n--- Suddenly it transforms ---\n\n";

    swapBehaviour(chest, mimicAttack<string>);
    chest.open();

    cout << "\n";

    //another mimic

    LootBox<string> trap(mimicAttack<string>);
    trap.add("Gold");
    trap.add("Potion");

    trap.open();

    return 0;
}