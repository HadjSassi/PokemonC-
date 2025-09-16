#ifndef HOMEPAGE_HPP
#define HOMEPAGE_HPP

#include "../../entities/headers/PokemonParty.hpp"
#include "../common/CenteredActionPage.hpp"

class HomePage : public CenteredActionPage {
public:
    HomePage();

    unique_ptr<BasePage> next() override;

    unique_ptr<BasePage> previous() override;

    void update() override;

    void setParty(PokemonParty &party);

    PokemonParty &getParty();

protected:
    void onButtonClicked() override { CenteredActionPage::onButtonClicked(); }
};
#endif // HOMEPAGE_HPP
