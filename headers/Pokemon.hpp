#include <string>
using namespace std;


class Pokemon {

private :
    static int pokemonCount;

    int id;
    string name;
    double hitPoint;
    double attack;
    double defense;
    int generation;

public:
    Pokemon(int id, string name, double hitPoint, double attack, double defense, int generation);

    Pokemon(Pokemon &pokemon);

    int getId() const;

    string getName() const;

    double getHitPoint() const;

    double getAttack() const;

    double getDefense() const;

    int getGeneration() const;

    void strike(Pokemon &target) const;

    bool getDamage(int damage);

    static int getPokemonCount();

    ~Pokemon();

    void displayInfo() const;
};
