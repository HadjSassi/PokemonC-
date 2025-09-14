#ifndef RENCONTREPAGE_HPP
#define RENCONTREPAGE_HPP


#include "../BasePage.hpp"
#include "../common/CenteredActionPage.hpp"
#include <random>

class RencontrePage : public CenteredActionPage {
public:
    RencontrePage();

    unique_ptr<BasePage> next() override;

protected:
    void onButtonClicked() override { CenteredActionPage::onButtonClicked(); }

private:
    int pokemonId;
    sf::Texture pokemonTexture;
    sf::Sprite pokemonSprite;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //RENCONTREPAGE_HPP
