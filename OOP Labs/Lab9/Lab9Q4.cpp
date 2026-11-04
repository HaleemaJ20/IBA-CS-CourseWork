#include <iostream>
#include <vector>
using namespace std;

enum ModType { ADDITIVE, MULTIPLICATIVE, OVERRIDE };

struct Modifier {
    ModType type;
    float value;
};

float foldDamage(float base, vector<Modifier> mods) {
    float damage = base;

    for (const auto& mod : mods) {
        if (mod.type == ADDITIVE) {
            damage += mod.value;
        }
        else if (mod.type == MULTIPLICATIVE) {
            damage *= mod.value;
        }
        else if (mod.type == OVERRIDE) {
            damage = mod.value;
        }
    }

    return damage;
}

int main() {

    float base = 100;

    vector<Modifier> mods = {
        {ADDITIVE, 20},      
        {MULTIPLICATIVE, 1.5}, 
        {OVERRIDE, 999},     
        {MULTIPLICATIVE, 0.8}  
    };

    float result = foldDamage(base, mods);

    cout << "Final Damage: " << result << endl;

    return 0;
}