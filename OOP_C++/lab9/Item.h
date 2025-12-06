#pragma once
#include <iostream>
#include <string>

// INTERN NOTE: Base class for all things in the game
class Item {
protected:
    std::string name;

public:
    Item(std::string n) : name(n) {
        std::cout << "Item constructor: " << name << "\n";
    }

    // TODO: Boss said something about virtual here?
    // But it works fine without it on my machine.
     virtual ~Item() {
        std::cout << "Item destructor: " << name << "\n";
    }

    std::string getName() const { return name; }

    // This should be overridden, right?
    virtual void use() {
        std::cout << "Using a generic item: " << name << "\n";
    }

    virtual Item* clone() = 0;

};

class Sword : public Item {
private:
    int damage;

public:
    Sword(std::string n, int dmg) : Item(n), damage(dmg) {
        std::cout << "Sword constructor\n";
    }

    ~Sword() {
        std::cout << "Sword destructor (Cleaning up blade oil...)\n";
    }

    void use() override {
        std::cout << "Swinging sword " << name << " for " << damage << " damage!\n";
    }

    Item* clone() override {
        return new Sword(*this);
    }
};

class Potion : public Item {
private:
    std::string type; // e.g., "Health", "Mana"

public:
    Potion(std::string n, std::string t) : Item(n), type(t) {
        std::cout << "Potion constructor\n";
    }

    ~Potion() {
        std::cout << "Potion destructor (Glass shattered)\n";
    }

    void use() override {
        std::cout << "Drinking " << type << " potion: " << name << "\n";
    }

    Item* clone() override {
        return new Potion(*this);
    }
};

class MagicBook : public Item {
private:
    std::string *spells;
    int spellCount;
public:
    MagicBook(std::string n, std::string *s, int count) : Item(n), spellCount(count) {
        spells = new std::string[spellCount];
        for (int i = 0; i < spellCount; i++) {
            spells[i] = s[i];
        }

        std::cout << "MagicBook constructor\n";
    }

    //Deep copy constructor
    MagicBook(const MagicBook& m) : Item(m.name) {
        spells = new std::string[spellCount];
        for (int i = 0; i < spellCount; i++) {
            spells[i] = m.spells[i];
        }
    }

    MagicBook& operator=(const MagicBook& m) {
        if (this == &m) {
            return *this;
        }

        spellCount = m.spellCount;

        spells = new std::string[spellCount];

        for (int i = 0; i < spellCount; i++) {
            spells[i] = m.spells[i];
        }

        return *this;

    }

    ~MagicBook() {
        delete [] spells;
        std::cout << "MagicBook destructor\n";
    }

    void use() override {
        std::cout << "Reading magic book: " << name <<"using spells: "<<spells<< "\n";
    }

    Item* clone() override {
        return new MagicBook(*this);
    }

};