#ifndef RENCONTREPAGE_HPP
#define RENCONTREPAGE_HPP


#include "../BasePage.hpp"


#include "../common/CenteredActionPage.hpp"

class RencontrePage : public CenteredActionPage {
public:
    RencontrePage();

    unique_ptr<BasePage> next() override;

protected:
    void onButtonClicked() override { CenteredActionPage::onButtonClicked(); }
};

#endif //RENCONTREPAGE_HPP
