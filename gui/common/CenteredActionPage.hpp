#ifndef CENTERED_ACTION_PAGE_HPP
#define CENTERED_ACTION_PAGE_HPP

#include <optional>
#include "../../config.hpp"
#include "../BasePage.hpp"

class CenteredActionPage : public BasePage {
public:
    CenteredActionPage();

    void handleEvent(const sf::Event& event, sf::Vector2u winSize) override;

    bool isFinished() const override { return clicked_; }

    void setButtonSize(const sf::Vector2f &size);

    void setButtonColors(const sf::Color &fill, const sf::Color &outline, float outlineThickness = LINE_THICKNESS);

    void setButtonText(const sf::String &label, unsigned int charSize = CHARACTER_SIZE, const sf::Color &color = sf::Color::White);

    void setButtonPosition(const sf::Vector2f& pos);

    void setVerticalMargin(float margin);

    void update() override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    virtual void onButtonClicked() { clicked_ = true; }

private:
    sf::RectangleShape button_;
    sf::Text label_;
    optional<sf::Vector2f> buttonPosition_;
    float margin_ = MARGIN;

    mutable sf::FloatRect buttonBounds_{};
    bool clicked_ = false;

    void centerLabelInButton();
};

#endif // CENTERED_ACTION_PAGE_HPP
