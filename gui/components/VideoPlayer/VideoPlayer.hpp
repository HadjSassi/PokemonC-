#ifndef POKEMON_VIDEOPLAYER_HPP
#define POKEMON_VIDEOPLAYER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../../../config.hpp"
#include <vector>
#include <string>

using namespace std;

class VideoPlayer : public sf::Drawable {
public:
    VideoPlayer(const string &path, float fps = FPS);

    void update();
    bool isFinished() const;

protected:
    void setSize(const sf::Vector2f &size);

private:
    vector<sf::Texture> frames_;
    vector<sf::Sprite> sprites_;
    size_t currentFrame_ = FIRST_VALUE;
    float frameDuration_;
    sf::Clock clock_;
    bool finished_ = false;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //POKEMON_VIDEOPLAYER_HPP