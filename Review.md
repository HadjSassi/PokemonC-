

L'organisation des fichiers est très propre et lisible c'est vraiment agréable.

## Pokemon 
ligne 54 get damage part :
si le pokemon est déjà mort pas la peine d'effectuer le reste donc il est mieux de renvoyer false directement
    ```
    if (hitPoint==0)      
       return false;
```
sinon mettre les hp à 0 lorsque le Pokemon est mort est peut être plus correct ?

ligne 49 Pokemon strike :
```
    target.getDamage((this->attack - target.defense>0) ? this->attack - target.defense : 0); //Modifié de façon à ce que si attack < defense, attack inflige 0
```


## Pokedex
la fonction displayAllPokemons a été override je ne sais pas si c'est obligatoire mais après dans la définition tu utilises ```Pokemonvector::displayAllPokemons()```; au lieu de ```Pokedex::displayAllPokemons()```;

## Main
Pas de test dans le main, impossible de constater ce qui fonctionne ou ne fonctionne pas


## PokemonParty
ta fonction addPokemonToParty fait exactement la même chose que la fonction addPokemon de PokemonVector dont la classe hérite

## PokemonAttack
Un peu comme dit dans ton Readme
PokemonAttack hérite des fonctions de PokemonParty donc tous les attack_team.push_back peuvent à la place utiliser le vecteur my_pokemons et les fonctions addPokemonToParty et extractPokemonFromParty



## Modifications apportées:
Une fonction de heal des pokemons + heal des pokemons quand ils réintègre PokemonParty (changé de const pokemon à pokemon dans reintegrateAllToParty)