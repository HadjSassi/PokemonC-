#ifndef RENCONTREPAGE_HPP
#define RENCONTREPAGE_HPP


#include "../BasePage.hpp"
#include "../common/CenteredActionPage.hpp"
#include "../components/popup/Popup.hpp"
#include "../../entities/headers/Pokemon.hpp"
#include "../../entities/headers/PokemonParty.hpp"
#include <random>


class RencontrePage : public CenteredActionPage {
public:
    RencontrePage(PokemonParty &partie);
    void selectRandomPokemon();
    unique_ptr<BasePage> next() override;

protected:
    void onButtonClicked() override ;
    void handleEvent(const sf::Event& event, sf::Vector2u winSize) override;
private:
    int pokemonId{};
    sf::Texture pokemonTexture;
    sf::Sprite pokemonSprite;
    Popup popup;
    Pokemon *pokemon{};
    PokemonParty& party ;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //RENCONTREPAGE_HPP
