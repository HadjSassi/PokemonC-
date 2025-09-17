#include "FightPage.hpp"
#include "../HomePage/HomePage.hpp"
#include <random>
#include "../../entities/headers/Pokedex.hpp"
#include "../../entities/headers/PokemonAttack.hpp"
#include "../FightingPage/FightingPage.hpp"
#include "../../config.hpp"

FightPage::FightPage() : CenteredActionPage(),
                         selectBox_(font_, {SELECT_BOX_X_POSITION, SELECT_BOX_Y_POSITION}, {SELECT_BOX_WIDTH, SELECT_BOX_HEIGHT}) {
    text_.setString(FIGHT_BUTTON_TEXT);
    text_.setCharacterSize(CHARACTER_SIZE);
    text_.setFillColor(sf::Color::Red);

    setButtonSize({BUTTON_X_SIZE, BUTTON_Y_SIZE});
    setButtonColors(sf::Color(178, 34, 34), sf::Color::Black, 2.f);
    setButtonText(PROCEED_BUTTON_TEXT, CHARACTER_SIZE, sf::Color::White);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(FIRST_POKEMON_ID, LAST_POKEMON_ID);

    randomPokemons_.clear();
    valueTexts_.resize(MAX_POKEMON_IN_PARTY);
    pokeTextures_.resize(MAX_POKEMON_IN_PARTY);
    pokeSprites_.resize(MAX_POKEMON_IN_PARTY);
    int maxPokemons = PokemonParty::getInstance().getPokemonsCount() > 6
                          ? MAX_POKEMON_IN_PARTY
                          : PokemonParty::getInstance().getPokemonsCount();
    for (int i = FIRST_VALUE; i < maxPokemons; ++i) {
        auto ptr = Pokedex::getInstance()->getPokemonByIndex(dis(gen));
        if (ptr) {
            randomPokemons_.push_back(*ptr);
            valueTexts_[i].setFont(font_);
            valueTexts_[i].setString(randomPokemons_.back().getName());
            valueTexts_[i].setCharacterSize(CHARACTER_SIZE);
            valueTexts_[i].setFillColor(sf::Color::White);

            std::ostringstream oss;
            oss << IMAGES_PATH << ptr->getId() << "PNG";
            pokeTextures_[i].loadFromFile(oss.str());
            pokeSprites_[i].setTexture(pokeTextures_[i]);
            pokeSprites_[i].setScale(SPRITE_SCALE_FACTOR / pokeTextures_[i].getSize().x, SPRITE_SCALE_FACTOR / pokeTextures_[i].getSize().y);
        }
    }
    std::vector<std::pair<int, std::string> > items;
    for (const Pokemon &pokemonn: PokemonParty::getInstance().getPokemons()) {
        std::ostringstream oss;
        oss << pokemonn.getName();
        items.emplace_back(pokemonn.getId(), oss.str());
    }
    selectBox_.setItems(items);
}

void FightPage::onButtonClicked() {
    CenteredActionPage::onButtonClicked();
}

unique_ptr<BasePage> FightPage::next() {
    auto selected = selectBox_.getSelectedIds();
    PokemonParty::getInstance().attack->getMyPokemons().clear();
    PokemonParty::getInstance().attack->createSetFromParty(selected);
    if (selected.empty())
        return make_unique<class HomePage>();
    return make_unique<class FightingPage>(randomPokemons_);
}


unique_ptr<BasePage> FightPage::previous() {
    return make_unique<class HomePage>();
}

void FightPage::handleEvent(const sf::Event &event, sf::Vector2u window) {
    CenteredActionPage::handleEvent(event, window);
    selectBox_.handleEvent(event, window);
}

void FightPage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    CenteredActionPage::draw(target, states);
    target.draw(selectBox_, states);

    const sf::View &view = target.getView();
    const sf::Vector2f center = view.getCenter();
    const sf::Vector2f size = view.getSize();

    float margin = TEXT_MARGIN;
    float rowHeight = ROW_HEIGHT/2;
    float totalHeight = valueTexts_.size() * rowHeight + (valueTexts_.size() - 1) * margin;
    float startY = center.y - totalHeight / LINE_THICKNESS + BUTTON_PADDING;

    float imgSize = SPRITE_SCALE_FACTOR;
    float col1X = center.x + size.x / LINE_THICKNESS - COLUMN_OFFSET;
    float col2X = col1X + imgSize + MARGIN;

    for (size_t i = FIRST_VALUE; i < valueTexts_.size(); ++i) {
        float y = startY + i * (rowHeight + margin);

        pokeSprites_[i].setPosition(col1X, y);
        target.draw(pokeSprites_[i], states);

        auto &txt = valueTexts_[i];
        txt.setPosition(col2X, y + (imgSize - txt.getLocalBounds().height) / 2.f);
        target.draw(txt, states);
    }
}
