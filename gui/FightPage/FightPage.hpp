#ifndef POKEMON_FIGHTPAGE_HPP
#define POKEMON_FIGHTPAGE_HPP

#include "../common/CenteredActionPage.hpp"

class FightPage : public CenteredActionPage {
public:
    FightPage();

    unique_ptr<BasePage> next() override;

protected:
    void onButtonClicked() override { CenteredActionPage::onButtonClicked(); }
};

#endif //POKEMON_FIGHTPAGE_HPP
