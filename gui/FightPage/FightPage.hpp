#ifndef POKEMON_FIGHTPAGE_HPP
#define POKEMON_FIGHTPAGE_HPP

#include "../../entities/headers/Pokemon.hpp"
#include "../../entities/headers/PokemonAttack.hpp"
#include "../common/CenteredActionPage.hpp"
#include "../components/selectbox/SelectBox.hpp"
#include "../../entities/headers/PokemonParty.hpp"

class FightPage : public CenteredActionPage {
public:
    FightPage();

    unique_ptr<BasePage> next() override;

    unique_ptr<BasePage> previous() override;

    void handleEvent(const sf::Event &event, sf::Vector2u window) override;

protected:
    void onButtonClicked() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    std::vector<Pokemon> randomPokemons_;
    mutable std::vector<sf::Text> valueTexts_;
    std::vector<sf::Texture> pokeTextures_;
    mutable std::vector<sf::Sprite> pokeSprites_;
    SelectBox selectBox_;
};
#endif //POKEMON_FIGHTPAGE_HPP
