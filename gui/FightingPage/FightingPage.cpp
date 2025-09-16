#include "FightingPage.hpp"

#include <iomanip>
#include <sstream>

#include "../HomePage/HomePage.hpp"

class PokemonAttack;

FightingPage::FightingPage(std::vector<Pokemon> &randomPokemons)
    : CenteredActionPage(), randomPokemons_(std::move(randomPokemons)) {
}

void FightingPage::onButtonClicked() {
    CenteredActionPage::onButtonClicked();
    makeWar();
}

void FightingPage::makeWar() {
    cout << "yaaaaaaaa" << endl;
}


void FightingPage::handleEvent(const sf::Event &event, sf::Vector2u window) {
    CenteredActionPage::handleEvent(event, window);
}

unique_ptr<BasePage> FightingPage::next() {
    return make_unique<class HomePage>();
}

unique_ptr<BasePage> FightingPage::previous() {
    return CenteredActionPage::previous();
}

void FightingPage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    const float rowHeight = 100.f;
    const float margin = 20.f;
    const sf::View &view = target.getView();
    const sf::Vector2f center = view.getCenter();

    float startY = center.y - ((PokemonParty::getInstance().attack->getMyPokemons().size() * rowHeight + (
                                    PokemonParty::getInstance().attack->getMyPokemons().size() - 1) * margin) / 2.f);

    float attackColX = center.x - 400.f;
    float vsColX = center.x;
    float randomColX = center.x + 100.f;

    // Utilisation de font_ hérité
    sf::Text attackHeader("My Pokemons", font_, 24);
    attackHeader.setPosition(attackColX, startY - 40.f);
    target.draw(attackHeader, states);

    sf::Text vsHeader("VS", font_, 24);
    vsHeader.setPosition(vsColX, startY - 40.f);
    target.draw(vsHeader, states);

    sf::Text randomHeader("The Ennemies", font_, 24);
    randomHeader.setPosition(randomColX, startY - 40.f);
    target.draw(randomHeader, states);

    for (size_t i = 0; i < PokemonParty::getInstance().attack->getMyPokemons().size(); ++i) {
        float y = startY + i * (rowHeight + margin);

        const Pokemon &atk = PokemonParty::getInstance().attack->getMyPokemons()[i];
        std::ostringstream defStream;
        defStream << std::fixed << std::setprecision(2) << atk.getDefense();
        sf::Text atkDef(defStream.str(), font_, 20);
        atkDef.setPosition(attackColX, y);
        target.draw(atkDef, states);

        std::ostringstream atkStream;
        atkStream << std::fixed << std::setprecision(2) << atk.getAttack();
        sf::Text atkAtk(atkStream.str(), font_, 20);
        atkAtk.setPosition(attackColX + 80.f, y);
        target.draw(atkAtk, states);

        sf::Text atkName(atk.getName(), font_, 20);
        atkName.setPosition(attackColX + 160.f, y);
        target.draw(atkName, states);

        sf::Texture atkTexture;
        std::ostringstream atkImgPath;
        atkImgPath << "../resources/img/pokemons/" << atk.getId() << ".png";
        atkTexture.loadFromFile(atkImgPath.str());
        sf::Sprite atkSprite(atkTexture);
        atkSprite.setPosition(attackColX + 300.f, y);
        atkSprite.setScale(60.f / atkTexture.getSize().x, 60.f / atkTexture.getSize().y);
        target.draw(atkSprite, states);

        sf::Text vsText("VS", font_, 20);
        vsText.setPosition(vsColX, y + 20.f);
        target.draw(vsText, states);

        if (i < randomPokemons_.size()) {
            const Pokemon &rnd = randomPokemons_[i];
            sf::Texture rndTexture;
            std::ostringstream rndImgPath;
            rndImgPath << "../resources/img/pokemons/" << rnd.getId() << ".png";
            rndTexture.loadFromFile(rndImgPath.str());
            sf::Sprite rndSprite(rndTexture);
            rndSprite.setPosition(randomColX, y);
            rndSprite.setScale(60.f / rndTexture.getSize().x, 60.f / rndTexture.getSize().y);
            target.draw(rndSprite, states);

            sf::Text rndName(rnd.getName(), font_, 20);
            rndName.setPosition(randomColX + 80.f, y);
            target.draw(rndName, states);


            std::ostringstream defRandStream;
            defRandStream << std::fixed << std::setprecision(2) << atk.getDefense();
            sf::Text rndAtk(defRandStream.str(), font_, 20);
            rndAtk.setPosition(randomColX + 200.f, y);
            target.draw(rndAtk, states);

            std::ostringstream atkRandStream;
            atkRandStream << std::fixed << std::setprecision(2) << atk.getAttack();
            sf::Text rndDef(atkRandStream.str(), font_, 20);
            rndDef.setPosition(randomColX + 280.f, y);
            target.draw(rndDef, states);
        }
    }
}
