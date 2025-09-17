#include "FightingPage.hpp"

#include <iomanip>
#include <sstream>

#include "../HomePage/HomePage.hpp"

class PokemonAttack;

FightingPage::FightingPage(std::vector<Pokemon> &randomPokemons)
    : CenteredActionPage(), popup_(font_), randomPokemons_(std::move(randomPokemons)) {
    isWallpaper = false;
    setButtonSize({BUTTON_X_SIZE*3, BUTTON_Y_SIZE});
    setButtonColors(sf::Color(178, 34, 34), sf::Color::Black, 2.f);
    setButtonText(FIGHTING_BUTTON_TEXT, CHARACTER_SIZE, sf::Color::White);
    setButtonPosition({BUTTON_POSITION_X, BUTTON_POSITION_Y});
    popup_.setPosition({POP_UP_POSITION_X, POP_UP_POSITION_Y});
}

void FightingPage::onButtonClicked() {
    makeWar();
}

void FightingPage::makeWar() {
    //todo till now it's version 1!
    int win = FIRST_VALUE;
    int lose = FIRST_VALUE;
    vector<Pokemon> my_pokemons = PokemonParty::getInstance().attack->getMyPokemons();
    for (int i = FIRST_VALUE; i < my_pokemons.size(); i++) {
        Pokemon my_pokemon = my_pokemons[i];
        Pokemon enemy_pokemon = randomPokemons_[i];
        bool striking = true;
        while (my_pokemon.getHitPoint() > LIFE_HEALTH_VALUE && enemy_pokemon.getHitPoint() > LIFE_HEALTH_VALUE) {
            if (striking) {
                my_pokemon.strike(enemy_pokemon);
                striking = false;
            } else {
                enemy_pokemon.strike(my_pokemon);
                striking = true;
            }
        }
        if (my_pokemon.getHitPoint() > LIFE_HEALTH_VALUE) {
            win++;
            PokemonParty::getInstance().addPokemonToParty(enemy_pokemon);
            PokemonParty::getInstance().addPokemonToParty(my_pokemon);
        } else if (enemy_pokemon.getHitPoint() > LIFE_HEALTH_VALUE) {
            lose++;
        }
    }
    popup_.show(WON + to_string(win) + AND + LOST + to_string(lose) + POKEMONS);
}

void FightingPage::handleEvent(const sf::Event &event, sf::Vector2u winSize) {
    if (popup_.isVisible()) {
        if (popup_.handleEvent(event, winSize) && popup_.wasButtonClicked()) {
            CenteredActionPage::onButtonClicked();
            popup_.hide();
        }
    } else {
        CenteredActionPage::handleEvent(event, winSize);
    }
}

unique_ptr<BasePage> FightingPage::next() {
    return make_unique<class HomePage>();
}

unique_ptr<BasePage> FightingPage::previous() {
    return CenteredActionPage::previous();
}

void FightingPage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    CenteredActionPage::draw(target, states);

    const sf::View &view = target.getView();
    const sf::Vector2f center = view.getCenter();

    float startY = center.y - TABLE_OFFSET_Y;
    float rowHeight = ROW_HEIGHT;

    float colOurX = center.x - TABLE_OFFSET_Y;
    float colVsX = center.x;
    float colEnemyX = center.x + TABLE_OFFSET_Y;

    sf::Texture versusTexture;
    versusTexture.loadFromFile(VERSUS_IMAGE_PATH);
    sf::Vector2f versusSize(versusTexture.getSize().x, versusTexture.getSize().y);

    auto &myPokemons = PokemonParty::getInstance().attack->getMyPokemons();

    for (size_t i = FIRST_VALUE; i < myPokemons.size(); ++i) {
        float y = startY + i * rowHeight;

        const Pokemon &atk = myPokemons[i];
        sf::Texture atkTexture;
        atkTexture.loadFromFile(IMAGES_PATH + std::to_string(atk.getId()) + PNG);
        sf::Sprite atkSprite(atkTexture);
        float imgSize = IMAGE_SIZE;
        atkSprite.setScale(imgSize / atkTexture.getSize().x, imgSize / atkTexture.getSize().y);

        sf::Text atkText(atk.getName(), font_, CHARACTER_SIZE);
        sf::FloatRect textBounds = atkText.getLocalBounds();

        float totalHeight = imgSize + IMAGE_PADDING + textBounds.height;
        float blockY = y + (rowHeight - totalHeight) / LINE_THICKNESS;

        atkSprite.setPosition(colOurX, blockY);
        atkText.setPosition(colOurX, blockY + imgSize + IMAGE_PADDING);

        target.draw(atkSprite, states);
        target.draw(atkText, states);

        sf::Sprite versusSprite(versusTexture);
        float vsY = blockY + (totalHeight - versusSize.y) / LINE_THICKNESS;
        versusSprite.setPosition(colVsX, vsY);
        target.draw(versusSprite, states);

        if (i < randomPokemons_.size()) {
            const Pokemon &rnd = randomPokemons_[i];
            sf::Texture rndTexture;
            rndTexture.loadFromFile(IMAGES_PATH + std::to_string(rnd.getId()) + PNG);
            sf::Sprite rndSprite(rndTexture);
            rndSprite.setScale(imgSize / rndTexture.getSize().x, imgSize / rndTexture.getSize().y);

            sf::Text rndText(rnd.getName(), font_, CHARACTER_SIZE);
            sf::FloatRect rndTextBounds = rndText.getLocalBounds();

            float enemyTotalHeight = imgSize + IMAGE_PADDING + rndTextBounds.height;
            float enemyBlockY = y + (rowHeight - enemyTotalHeight) / LINE_THICKNESS;

            rndSprite.setPosition(colEnemyX, enemyBlockY);
            rndText.setPosition(colEnemyX, enemyBlockY + imgSize + IMAGE_PADDING);

            target.draw(rndSprite, states);
            target.draw(rndText, states);
            if (popup_.isVisible()) {
                popup_.draw(target);
            }
        }
    }
}
