#include "VideoPlayer.hpp"
#include <filesystem>
#include <iostream>
#include "../../../config.hpp"
namespace fs = filesystem;

VideoPlayer::VideoPlayer(const string &path, float fps) {
    frameDuration_ = FRAME_FREQUENCY / fps;

    std::vector<fs::path> files;
    for (const auto &entry : fs::directory_iterator(path)) {
        if (entry.path().extension() == JPG || entry.path().extension() == PNG)
            files.push_back(entry.path());
    }
    std::sort(files.begin(), files.end());

    frames_.reserve(files.size());
    sprites_.reserve(files.size());

    for (const auto &file : files) {
        frames_.emplace_back();
        frames_.back().loadFromFile(file.string());
        sprites_.emplace_back(frames_.back());
    }

    if (sprites_.empty()) {
        cerr << NO_FRAME_FOUND << path << endl;
        finished_ = true;
    } else {
        auto desktop = sf::VideoMode::getDesktopMode();
        setSize(sf::Vector2f(desktop.width, desktop.height));
    }
}

void VideoPlayer::update() {
    if (finished_ || sprites_.empty()) return;

    if (clock_.getElapsedTime().asSeconds() > frameDuration_) {
        clock_.restart();
        currentFrame_++;
        if (currentFrame_ >= sprites_.size()) {
            finished_ = true;
            currentFrame_ = sprites_.size() - 1;
        }
    }
}

bool VideoPlayer::isFinished() const {
    return finished_;
}

void VideoPlayer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (!sprites_.empty() && !finished_) {
        target.draw(sprites_[currentFrame_], states);
    }
}

void VideoPlayer::setSize(const sf::Vector2f& size) {
    for (size_t i = FIRST_VALUE; i < sprites_.size(); ++i) {
        auto texSize = frames_[i].getSize();
        float scaleX = size.x / texSize.x;
        float scaleY = size.y / texSize.y;
        sprites_[i].setScale(scaleX, scaleY);
    }
}