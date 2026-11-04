#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Weapon
{
public:
    string name;
    double weight;
    int totalAttackPower;
    string rarity;

    Weapon(string n, double w, int atk, string r)
        : name(n), weight(w), totalAttackPower(atk), rarity(r) {}
};

class Inventory
{
private:
    vector<Weapon> weapons;

public:
    void addWeapon(const Weapon &w)
    {
        weapons.push_back(w);
    }

    void display() const
    {
        for (const auto &w : weapons)
        {
            cout << "[" << w.name << "] "
                 << "Weight: " << w.weight << "kg | "
                 << "ATK: " << w.totalAttackPower << " | "
                 << "Rarity: " << w.rarity << endl;
        }
    }

    /*
    Template comparator avoids overhead of std::function.
    It allows compile-time binding (faster) and works with lambdas,
    function objects, and function pointers without type erasure.
    */
    template <typename Comparator>
    void sortBy(Comparator comp)
    {
        sort(weapons.begin(), weapons.end(), comp);
        cout << "Inventory sorted.\n";
    }

    template <typename Predicate>
    vector<Weapon> filter(Predicate pred) const
    {
        vector<Weapon> result;
        copy_if(weapons.begin(), weapons.end(), back_inserter(result), pred);
        return result;
    }
};

struct ByWeightAscending
{
    bool operator()(const Weapon &a, const Weapon &b) const
    {
        return a.weight < b.weight;
    }
};

struct ByAttackDescending
{
    bool operator()(const Weapon &a, const Weapon &b) const
    {
        return a.totalAttackPower > b.totalAttackPower;
    }
};

int rarityRank(const string &r)
{
    if (r == "Common")
        return 0;
    if (r == "Uncommon")
        return 1;
    if (r == "Rare")
        return 2;
    if (r == "Legendary")
        return 3;
    return -1;
}

int main()
{
    Inventory inv;

    inv.addWeapon({"Sword", 3.5, 50, "Common"});
    inv.addWeapon({"Axe", 5.0, 70, "Rare"});
    inv.addWeapon({"Bow", 2.0, 40, "Uncommon"});
    inv.addWeapon({"Dagger", 1.2, 30, "Common"});
    inv.addWeapon({"Hammer", 6.5, 90, "Legendary"});
    inv.addWeapon({"Staff", 4.0, 60, "Rare"});
    inv.addWeapon({"Spear", 3.0, 55, "Uncommon"});
    inv.addWeapon({"Crossbow", 3.8, 65, "Rare"});
    inv.addWeapon({"Katana", 2.5, 80, "Legendary"});
    inv.addWeapon({"Mace", 5.5, 75, "Uncommon"});

    cout << "\nOriginal:\n";
    inv.display();

    cout << "\nSort by Weight:\n";
    inv.sortBy(ByWeightAscending());
    inv.display();

    cout << "\nSort by Attack:\n";
    inv.sortBy(ByAttackDescending());
    inv.display();

    cout << "\nSort by Rarity:\n";
    inv.sortBy([](const Weapon &a, const Weapon &b)
               {
        if (rarityRank(a.rarity) != rarityRank(b.rarity))
            return rarityRank(a.rarity) > rarityRank(b.rarity);
        return a.weight < b.weight; });
    inv.display();

    auto strong = inv.filter([](const Weapon &w)
                             { return w.totalAttackPower > 60; });

    cout << "\nStrong weapons count: " << strong.size() << endl;

    auto light = inv.filter([](const Weapon &w)
                            { return w.weight < 5.0; });

    cout << "Lightweight weapons:\n";
    for (auto &w : light)
        cout << w.name << endl;

    return 0;
}