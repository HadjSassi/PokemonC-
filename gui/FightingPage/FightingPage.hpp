#ifndef POKEMON_FIGHTINGPAGE_HPP
#define POKEMON_FIGHTINGPAGE_HPP

#include "../../entities/headers/PokemonAttack.hpp"
#include "../common/CenteredActionPage.hpp"

class FightingPage : public CenteredActionPage {
public:
    FightingPage(std::vector<Pokemon> &randomPokemons);

    unique_ptr<BasePage> next() override;

    unique_ptr<BasePage> previous() override;

    void handleEvent(const sf::Event &event, sf::Vector2u window) override;

protected:
    void onButtonClicked() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    std::vector<Pokemon> randomPokemons_;

    void makeWar();
};


#endif //POKEMON_FIGHTINGPAGE_HPP
