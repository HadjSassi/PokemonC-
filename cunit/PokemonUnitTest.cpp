#include <iostream>
#include <cassert>
#include "../entities/headers/Pokemon.hpp"

using namespace std;

void testCreation() {
    Pokemon p(1, "Pikachu", 100, 50, 30, 1, 100);
    assert(p.getId() == 1);
    assert(p.getName() == "Pikachu");
    assert(p.getHitPoint() == 100);
    assert(p.getAttack() == 50);
    assert(p.getDefense() == 30);
    assert(p.getGeneration() == 1);
    assert(p.getMaxLife() == 100);
}

void testStrikeAndDamage() {
    Pokemon attacker(2, "Bulbasaur", 100, 40, 20, 1, 100);
    Pokemon defender(3, "Charmander", 100, 30, 10, 1, 100);
    attacker.strike(defender);
    assert(defender.getHitPoint() == 100 - (40 - 10));
    defender.strike(attacker);
    assert(attacker.getHitPoint() == 100 - (30 - 20));
}

void testHeal() {
    Pokemon p(4, "Squirtle", 50, 20, 20, 1, 100);
    p.heal(30);
    assert(p.getHitPoint() == 80);
    p.heal(50);
    assert(p.getHitPoint() == 100); // ne dépasse pas maxLife
    p.getDamage(120);
    assert(p.getHitPoint() <= 0);
    p.heal(40);
    assert(p.getHitPoint() == 40);
}

void testPokemonCount() {
    int countBefore = Pokemon::getPokemonCount();
    Pokemon *p1 = new Pokemon(5, "Eevee", 60, 25, 15, 1, 60);
    Pokemon *p2 = new Pokemon(*p1);
    assert(Pokemon::getPokemonCount() == countBefore + 2);
    delete p1;
    delete p2;
    assert(Pokemon::getPokemonCount() == countBefore);
}

int main() {
    testCreation();
    testStrikeAndDamage();
    testHeal();
    testPokemonCount();
    cout << "Tous les tests unitaires sont passes." << endl;
    return 0;
}
