#include <iostream>

#include "../headers/Pokemon.hpp"

int Pokemon::pokemonCount = 0;

Pokemon::Pokemon(int id, string name, double hitPoint, double attack, double defense, int generation, int maxLife) : id(id),
    name(name), hitPoint(hitPoint), attack(attack), defense(defense), generation(generation), maxLife(maxLife) {
    pokemonCount++;
}

Pokemon::Pokemon(const Pokemon &pokemon) : id(pokemon.id), name(pokemon.name), hitPoint(pokemon.hitPoint),
                                     attack(pokemon.attack), defense(pokemon.defense), generation(pokemon.generation), maxLife(pokemon.maxLife) {
    pokemonCount++;
}

Pokemon::~Pokemon() {
    pokemonCount--;
}

int Pokemon::getId() const {
    return id;
}

string Pokemon::getName() const {
    return name;
}

double Pokemon::getHitPoint() const {
    return hitPoint;
}

double Pokemon::getAttack() const {
    return attack;
}

double Pokemon::getDefense() const {
    return defense;
}

int Pokemon::getGeneration() const {
    return generation;
}

int Pokemon::getMaxLife() const {
    return maxLife;
}

void Pokemon::strike(Pokemon &target) const {
    if (target.getHitPoint() > 0)
        target.getDamage(this->attack - target.defense);
}

bool Pokemon::getDamage(int damage) {
    this->hitPoint -= damage;
    if (hitPoint <= 0)
        cout << "AHHHHHHH " << name << " is DEAD/!\\" << endl;
    return hitPoint > 0;
}

void Pokemon::heal(int amount){
    if (hitPoint<=0)
    hitPoint=amount;
    else
    hitPoint+=amount;
    if (hitPoint>maxLife)
    hitPoint=maxLife;
}

int Pokemon::getPokemonCount() {
    return pokemonCount;
}

void Pokemon::displayInfo() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Hit Points: " << hitPoint << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Generation: " << generation << endl;
}
