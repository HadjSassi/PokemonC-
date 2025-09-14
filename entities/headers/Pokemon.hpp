#pragma once
#include <string>
using namespace std;


class Pokemon {
public:
    Pokemon(int id, string name, double hitPoint, double attack, double defense, int generation, int maxLife);

    Pokemon(const Pokemon &pokemon);

    int getId() const;

    string getName() const;

    double getHitPoint() const;

    double getAttack() const;

    double getDefense() const;

    int getGeneration() const;

    int getMaxLife() const;

    void strike(Pokemon &target) const;

    bool getDamage(int damage);

    static int getPokemonCount();

    void heal(int amount);

    ~Pokemon();

    void displayInfo() const;

    std::string getInfoString() const;

private :
    static int pokemonCount;

    int id;
    string name;
    double hitPoint;
    double attack;
    double defense;
    int generation;
    int maxLife;
};
