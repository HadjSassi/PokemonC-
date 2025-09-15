#ifndef POKEMON_FIGHTPAGE_HPP
#define POKEMON_FIGHTPAGE_HPP

#include "../../entities/headers/Pokemon.hpp"
#include "../common/CenteredActionPage.hpp"
#include "../components/selectbox/SelectBox.hpp"

class FightPage : public CenteredActionPage {
public:
    FightPage();

    unique_ptr<BasePage> next() override;

    void handleEvent(const sf::Event& event, sf::Vector2u window) override;

protected:
    void onButtonClicked() override ;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    std::vector<Pokemon> randomPokemons_;
    mutable std::vector<sf::Text> valueTexts_;
    std::vector<sf::Texture> pokeTextures_;
    mutable std::vector<sf::Sprite> pokeSprites_;
    SelectBox selectBox_;

};
#endif //POKEMON_FIGHTPAGE_HPP
