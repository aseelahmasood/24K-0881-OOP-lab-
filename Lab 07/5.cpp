#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id,string n,int lvl,int hp,string weapon = "")
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack() {
        cout<<name<< " attacks with " << weaponType << endl;
    }

    virtual void defend() {
        cout<<name<< " defends with default defense." << endl;
    }

    virtual void displayStats() const {
        cout << "ID: " << characterID << ", Name: " << name
             << ", Level: " << level << ", HP: " << healthPoints
             << ", Weapon: " << weaponType << endl;
    }
};

class Warrior : public Character {
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, string n, int lvl, int hp, string weapon, int armor, int damage)
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}

    void attack() override {
        cout << name << " performs melee attack with damage " << meleeDamage << endl;
    }
};

class Mage : public Character {
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string n, int lvl, int hp, string weapon, int mana, int power)
        : Character(id, n, lvl, hp, weapon), manaPoints(mana), spellPower(power) {}

    void defend() override {
        cout << name << " uses a magical barrier with power " << spellPower << endl;
    }
};

class Archer : public Character {
    int arrowCount;
    float rangedAccuracy;

public:
    Archer(int id, string n, int lvl, int hp, string weapon, int arrows, float accuracy)
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override {
        cout << name << " performs a ranged attack with " << arrowCount << " arrows and "
             << rangedAccuracy << "% accuracy" << endl;
    }
};

class Rogue : public Character {
    int stealthLevel;
    int agility;

public:
    Rogue(int id, string n, int lvl, int hp, string weapon, int stealth, int agi)
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agi) {}

    void displayStats() const override {
        Character::displayStats();
        cout << "Stealth: " << stealthLevel << ", Agility: " << agility << endl;
    }
};

int main() {
    Warrior w(1, "Thor", 10, 200, "Axe", 50, 75);
    Mage m(2, "Gandalf", 12, 150, "Staff", 100, 90);
    Archer a(3, "Legolas", 11, 170, "Bow", 30, 85.5);
    Rogue r(4, "Shadow", 9, 160, "Dagger", 70, 95);

    w.attack();
    m.defend();
    a.attack();
    r.displayStats();

    return 0;
}
