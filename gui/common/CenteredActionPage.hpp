#ifndef CENTERED_ACTION_PAGE_HPP
#define CENTERED_ACTION_PAGE_HPP

#include "../BasePage.hpp"

class CenteredActionPage : public BasePage {
public:
    CenteredActionPage();

    void handleEvent(const sf::Event &event) override;

    bool isFinished() const override { return clicked_; }

    void setButtonSize(const sf::Vector2f &size);

    void setButtonColors(const sf::Color &fill, const sf::Color &outline, float outlineThickness = 2.f);

    void setButtonText(const sf::String &label, unsigned int charSize = 32, const sf::Color &color = sf::Color::White);

    void setVerticalMargin(float margin);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    virtual void onButtonClicked() { clicked_ = true; }

private:
    sf::RectangleShape button_;
    sf::Text label_;
    float margin_ = 24.f;

    mutable sf::FloatRect buttonBounds_{};
    bool clicked_ = false;

    void centerLabelInButton();
};

#endif // CENTERED_ACTION_PAGE_HPP
