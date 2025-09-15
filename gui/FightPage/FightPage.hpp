#ifndef POKEMON_FIGHTPAGE_HPP
#define POKEMON_FIGHTPAGE_HPP

#include "../../entities/headers/Pokemon.hpp"
#include "../common/CenteredActionPage.hpp"

class FightPage : public CenteredActionPage {
public:
    FightPage();

    unique_ptr<BasePage> next() override;

protected:
    void onButtonClicked() override { CenteredActionPage::onButtonClicked(); }
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    std::vector<Pokemon> randomPokemons_;
    mutable std::vector<sf::Text> valueTexts_;
    std::vector<sf::Texture> pokeTextures_;
    mutable std::vector<sf::Sprite> pokeSprites_;
};
#endif //POKEMON_FIGHTPAGE_HPP
