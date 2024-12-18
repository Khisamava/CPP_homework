#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

///В проекте реализуется финальная битва за Хогвартс. У нас есть две стороны: Орден Феникса и Пожиратели сметри. При чем в армии Ордена Феникса
/// находятся волшебники и кентавры, а в армии пожирателей смерти волшебники и великаны. 

#include "spellbook.h" 

// Абстрактный базовый класс для всех участников боя
class Character {
public:
    virtual ~Character() {}
    virtual int attack() const = 0;
    virtual void takeDamage(int damage) = 0;
    virtual bool isAlive() const = 0;
};

// Класс для мага
class Wizard : public Character {
private:
    int health;
    string spellBook; // Список заклинаний

public:
    Wizard(int hp, const vector<string>& spells) : health(hp), spellBook(spells) {
        if (health <= 0) throw invalid_argument("Wizard health must be greater than 0");
    }

    int attack() const override {
        if (spellBook.empty()) return 0;
        // Маг выбирает случайное заклинание для атаки
        int damage = rand() % spellBook.size() + 10;
        return damage;
    }

    void takeDamage(int damage) override {
        health -= damage;
        if (health < 0) health = 0;
    }

    bool isAlive() const override {
        return health > 0;
    }
};

// Класс для великана
class Giant : public Character {
private:
    int health;
    int strength;

public:
    Giant(int hp, int str) : health(hp), strength(str) {
        if (health <= 0 || strength <= 0) throw invalid_argument("Giant health and strength must be greater than 0");
    }

    int attack() const override {
        return strength;
    }

    void takeDamage(int damage) override {
        health -= damage;
        if (health < 0) health = 0;
    }

    bool isAlive() const override {
        return health > 0;
    }
};

// Класс для кентавра
class Centaur : public Character {
private:
    int health;
    int strength;

public:
    Centaur(int hp, int str) : health(hp), strength(str * 2) {
        if (health <= 0 || strength <= 0) throw invalid_argument("Centaur health and strength must be greater than 0");
    }

    int attack() const override {
        return strength;
    }

    void takeDamage(int damage) override {
        health -= damage;
        if (health < 0) health = 0;
    }

    bool isAlive() const override {
        return health > 0;
    }
};

// Функция дуэли между двумя персонажами
void duel(Character& c1, Character& c2) {
    while (c1.isAlive() && c2.isAlive()) {
        c2.takeDamage(c1.attack());
        if (c2.isAlive()) {
            c1.takeDamage(c2.attack());
        }
    }
}

// Функция битвы между двумя армиями
void battle(vector<Character*>& army1, vector<Character*>& army2) {
    size_t idx1 = 0, idx2 = 0;

    while (idx1 < army1.size() && idx2 < army2.size()) {
        duel(*army1[idx1], *army2[idx2]);
        if (!army1[idx1]->isAlive()) {
            delete army1[idx1];
            idx1++;
        }
        if (!army2[idx2]->isAlive()) {
            delete army2[idx2];
            idx2++;
        }
    }

    int survivors1 = 0, survivors2 = 0;
    for (size_t i = idx1; i < army1.size(); ++i) {
        if (army1[i]->isAlive()) survivors1++;
        delete army1[i];
    }
    for (size_t i = idx2; i < army2.size(); ++i) {
        if (army2[i]->isAlive()) survivors2++;
        delete army2[i];
    }

    cout << "Battle Result:\n";
    if (survivors1 > survivors2) {
        std::cout << "The Order of the Phoenix wins with " << survivors1 << " survivors.\n";
    } else if (survivors2 > survivors1) {
        std::cout << "Death Eaters win with " << survivors2 << " survivors.\n";
    } else {
        std::cout << "It's a draw!\n";
    }
}

// Чтение армии из файла
void loadArmy(const string& filename, vector<Character*>& army, const string& side) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    string type;
    while (file >> type) {
        if (type == "Wizard") {
            int health;
            int spellCount;
            file >> health >> spellCount;
            std::vector<std::string> spells(spellCount);
            for (int i = 0; i < spellCount; ++i) {
                file >> spells[i];
            }
            army.push_back(new Mage(health, spells));
        } else if (type == "Giant" && side == "DeathEaters") {
            int health, strength;
            file >> health >> strength;
            army.push_back(new Giant(health, strength));
        } else if (type == "Centaur" && side == "Phoenix") {
            int health, strength;
            file >> health >> strength;
            army.push_back(new Centaur(health, strength));
        } else {
            throw std::runtime_error("Invalid character type or army mismatch in file.");
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    vector<Character*> order_Of_Phoenix;
    vector<Character*> deathEaters;

    try {
        loadArmy("phoenix.txt", order_Of_Phoenix, "Phoenix");
        loadArmy("deathEaters.txt", deathEaters, "DeathEaters");
        
        battle(order_Of_Phoenix, deathEaters);
    } catch (const exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
