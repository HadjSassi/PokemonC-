//
// Created by mahdihadjsassi on 14/09/2025.
//

#ifndef POKEMON_VIDEOPLAYER_HPP
#define POKEMON_VIDEOPLAYER_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using namespace std;

class VideoPlayer : public sf::Drawable {
public:
    VideoPlayer(const string &path, float fps = 24.0f);

    void update();
    bool isFinished() const;

private:
    vector<sf::Texture> frames_;
    vector<sf::Sprite> sprites_;
    size_t currentFrame_ = 0;
    float frameDuration_;
    sf::Clock clock_;
    bool finished_ = false;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //POKEMON_VIDEOPLAYER_HPP