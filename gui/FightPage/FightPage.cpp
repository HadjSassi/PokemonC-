#include "FightPage.hpp"
#include "../HomePage/HomePage.hpp"
#include <random>

#include "../../entities/headers/Pokedex.hpp"
#include "../../entities/headers/PokemonParty.hpp"

FightPage::FightPage() : CenteredActionPage(), selectBox_(font_, {50.f, 100.f}, {200.f, 400.f})
{
    text_.setString("Fight");
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::Red);

    setButtonSize({220.f, 64.f});
    setButtonColors(sf::Color(178, 34, 34), sf::Color::Black, 2.f);
    setButtonText("Continue", 32, sf::Color::White);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 799);

    randomPokemons_.clear();
    valueTexts_.resize(6);
    pokeTextures_.resize(6);
    pokeSprites_.resize(6);
    int maxPokemons = PokemonParty::getInstance()->getPokemonsCount() > 6 ? 6 : PokemonParty::getInstance()->getPokemonsCount();
    for (int i = 0; i < maxPokemons; ++i) {
        auto ptr = Pokedex::getInstance()->getPokemonByIndex(dis(gen));
        if (ptr) {
            randomPokemons_.push_back(*ptr);
            valueTexts_[i].setFont(font_);
            valueTexts_[i].setString(randomPokemons_.back().getName());
            valueTexts_[i].setCharacterSize(32);
            valueTexts_[i].setFillColor(sf::Color::White);

            std::ostringstream oss;
            oss << "../resources/img/pokemons/" << ptr->getId() << ".png";
            pokeTextures_[i].loadFromFile(oss.str());
            pokeSprites_[i].setTexture(pokeTextures_[i]);
            pokeSprites_[i].setScale(100.f / pokeTextures_[i].getSize().x, 100.f / pokeTextures_[i].getSize().y);
        }
    }
    std::vector<std::pair<int, std::string>> items;
    for (const Pokemon& pokemonn : PokemonParty::getInstance()->getPokemons()) {
        std::ostringstream oss;
        oss << pokemonn.getName() << " (ATT " << pokemonn.getAttack() << ", DEF " << pokemonn.getDefense() << ")";
        items.emplace_back(pokemonn.getId(), oss.str());
    }
    selectBox_.setItems(items);
}

void FightPage::onButtonClicked() {
    CenteredActionPage::onButtonClicked();
    auto selected = selectBox_.getSelectedIds();
}

unique_ptr<BasePage> FightPage::next() {
    return make_unique<class HomePage>();
}

void FightPage::handleEvent(const sf::Event& event, sf::Vector2u window) {
    CenteredActionPage::handleEvent(event, window);
    selectBox_.handleEvent(event, window);
}

void FightPage::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    CenteredActionPage::draw(target, states);
    target.draw(selectBox_, states);

    const sf::View& view = target.getView();
    const sf::Vector2f center = view.getCenter();
    const sf::Vector2f size = view.getSize();

    float margin = 30.f;
    float rowHeight = 56.f;
    float totalHeight = valueTexts_.size() * rowHeight + (valueTexts_.size() - 1) * margin;
    float startY = center.y - totalHeight / 2.f + 20.f;

    float imgSize = 100.f;
    float col1X = center.x + size.x / 2.f - 500.f;
    float col2X = col1X + imgSize + 24.f;

    for (size_t i = 0; i < valueTexts_.size(); ++i) {
        float y = startY + i * (rowHeight + margin);

        pokeSprites_[i].setPosition(col1X, y);
        target.draw(pokeSprites_[i], states);

        auto& txt = valueTexts_[i];
        txt.setPosition(col2X, y + (imgSize - txt.getLocalBounds().height) / 2.f);
        target.draw(txt, states);
    }
}