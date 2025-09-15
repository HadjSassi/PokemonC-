#ifndef POKEMON_SELECTBOX_HPP
#define POKEMON_SELECTBOX_HPP


#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

struct Item {
    int id;
    std::string label;
    bool checked;
};

class SelectBox : public sf::Drawable {
public:
    SelectBox(const sf::Font &font, sf::Vector2f position, sf::Vector2f size);

    void handleEvent(const sf::Event &event, sf::Vector2u windowSize);

    std::vector<int> getSelectedIds() const;

    void setItems(const std::vector<std::pair<int, std::string>>& items);

    void setPosition(sf::Vector2f pos);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    void updateFilter();
    void updateVisibleCount();

    sf::RectangleShape box_;
    sf::Text searchText_;
    std::string searchInput_;
    std::vector<Item> items_;
    std::vector<int> filteredIndices_;
    sf::Font font_;
    float scrollOffset_;
    int visibleCount_;

    // config
    float headerHeight_;
    float itemHeight_;
};

#endif //POKEMON_SELECTBOX_HPP
