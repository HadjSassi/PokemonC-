#include "FightingPage.hpp"

#include <iomanip>
#include <sstream>

#include "../HomePage/HomePage.hpp"

class PokemonAttack;

FightingPage::FightingPage(std::vector<Pokemon> &randomPokemons)
    : CenteredActionPage(), popup_(font_), randomPokemons_(std::move(randomPokemons)) {
    isWallpaper = false;
    setButtonSize({720.f, 64.f});
    setButtonColors(sf::Color(178, 34, 34), sf::Color::Black, 2.f);
    setButtonText("Fight", 32, sf::Color::White);
    setButtonPosition({1000.f, 900.f});
    popup_.setPosition({600.f, 400.f});
}

void FightingPage::onButtonClicked() {
    makeWar();
}

void FightingPage::makeWar() {
    cout << "yaaaaaaaa" << endl;
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

    float startY = center.y - 200.f;
    float rowHeight = 120.f;

    float colOurX = center.x - 200.f;
    float colVsX = center.x;
    float colEnemyX = center.x + 200.f;

    sf::Texture versusTexture;
    versusTexture.loadFromFile("../resources/img/versusSmall.png");
    sf::Vector2f versusSize(versusTexture.getSize().x, versusTexture.getSize().y);

    auto &myPokemons = PokemonParty::getInstance().attack->getMyPokemons();

    for (size_t i = 0; i < myPokemons.size(); ++i) {
        float y = startY + i * rowHeight;

        // --- Notre Pokémon ---
        const Pokemon &atk = myPokemons[i];
        sf::Texture atkTexture;
        atkTexture.loadFromFile("../resources/img/pokemons/" + std::to_string(atk.getId()) + ".png");
        sf::Sprite atkSprite(atkTexture);
        float imgSize = 60.f;
        atkSprite.setScale(imgSize / atkTexture.getSize().x, imgSize / atkTexture.getSize().y);

        sf::Text atkText(atk.getName(), font_, 20);
        sf::FloatRect textBounds = atkText.getLocalBounds();

        float totalHeight = imgSize + 8.f + textBounds.height;
        float blockY = y + (rowHeight - totalHeight) / 2.f;

        atkSprite.setPosition(colOurX, blockY);
        atkText.setPosition(colOurX, blockY + imgSize + 8.f);

        target.draw(atkSprite, states);
        target.draw(atkText, states);

        sf::Sprite versusSprite(versusTexture);
        float vsY = blockY + (totalHeight - versusSize.y) / 2.f;
        versusSprite.setPosition(colVsX, vsY);
        target.draw(versusSprite, states);

        if (i < randomPokemons_.size()) {
            const Pokemon &rnd = randomPokemons_[i];
            sf::Texture rndTexture;
            rndTexture.loadFromFile("../resources/img/pokemons/" + std::to_string(rnd.getId()) + ".png");
            sf::Sprite rndSprite(rndTexture);
            rndSprite.setScale(imgSize / rndTexture.getSize().x, imgSize / rndTexture.getSize().y);

            sf::Text rndText(rnd.getName(), font_, 20);
            sf::FloatRect rndTextBounds = rndText.getLocalBounds();

            float enemyTotalHeight = imgSize + 8.f + rndTextBounds.height;
            float enemyBlockY = y + (rowHeight - enemyTotalHeight) / 2.f;

            rndSprite.setPosition(colEnemyX, enemyBlockY);
            rndText.setPosition(colEnemyX, enemyBlockY + imgSize + 8.f);

            target.draw(rndSprite, states);
            target.draw(rndText, states);
            if (popup_.isVisible()) {
                popup_.draw(target);
            }
        }
    }
}
