#include <iostream>

#include "../headers/Pokemon.hpp"
#include "../../config.hpp"

#include <sstream>

int Pokemon::pokemonCount = FIRST_VALUE;

Pokemon::Pokemon(int id, string name, double hitPoint, double attack, double defense, int generation,
                 int maxLife) : id(id),
                                name(name), hitPoint(hitPoint), attack(attack), defense(defense),
                                generation(generation), maxLife(maxLife) {
    pokemonCount++;
}

Pokemon::Pokemon(const Pokemon &pokemon) : id(pokemon.id), name(pokemon.name), hitPoint(pokemon.hitPoint),
                                           attack(pokemon.attack), defense(pokemon.defense),
                                           generation(pokemon.generation), maxLife(pokemon.maxLife) {
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
    if (target.getHitPoint() > LIFE_HEALTH_VALUE)
        target.getDamage((this->attack - target.defense > LIFE_HEALTH_VALUE) ? this->attack - target.defense : LIFE_HEALTH_VALUE);
}

bool Pokemon::getDamage(int damage) {
    this->hitPoint -= damage;
    return hitPoint > LIFE_HEALTH_VALUE;
}

void Pokemon::heal(int amount) {
    if (hitPoint <= LIFE_HEALTH_VALUE)
        hitPoint = amount;
    else
        hitPoint += amount;
    if (hitPoint > maxLife)
        hitPoint = maxLife;
}

int Pokemon::getPokemonCount() {
    return pokemonCount;
}

void Pokemon::displayInfo() const {
    cout << getInfoString() << endl;
}

std::string Pokemon::getInfoString() const {
    std::ostringstream oss;
    oss << ID << id << "\n";
    oss << NAME << name << "\n";
    oss << HIT_POINTS << hitPoint << "\n";
    oss << ATTACK << attack << "\n";
    oss << DEFENSE<< defense << "\n";
    oss << GENERATION << generation;
    return oss.str();
}