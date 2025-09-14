#ifndef HOMEPAGE_HPP
#define HOMEPAGE_HPP

#include "../common/CenteredActionPage.hpp"

class HomePage : public CenteredActionPage {
public:
    HomePage();

    unique_ptr<BasePage> next() override;

    void update() override;

protected:
    void onButtonClicked() override { CenteredActionPage::onButtonClicked(); }
};
#endif // HOMEPAGE_HPP
