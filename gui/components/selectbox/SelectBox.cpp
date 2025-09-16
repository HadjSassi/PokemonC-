#include "SelectBox.hpp"
#include <algorithm>
#include <sstream>
#include <cmath>

SelectBox::SelectBox(const sf::Font &font, sf::Vector2f position, sf::Vector2f size)
    : font_(font),
      scrollOffset_(0),
      headerHeight_(36.f),
      itemHeight_(24.f),
      nextOrder_(1)
{
    box_.setPosition(position);
    box_.setSize(size);
    box_.setFillColor(sf::Color(40, 40, 40));
    box_.setOutlineColor(sf::Color::White);
    box_.setOutlineThickness(2);

    searchText_.setFont(font_);
    searchText_.setCharacterSize(20);
    searchText_.setFillColor(sf::Color::White);
    searchText_.setPosition(position.x + 8, position.y + 6);

    updateVisibleCount();
    updateFilter();
}

void SelectBox::updateVisibleCount() {
    int available = std::max(0, int((box_.getSize().y - headerHeight_) / itemHeight_));
    visibleCount_ = std::max(1, available);
}

void SelectBox::setPosition(sf::Vector2f pos) {
    box_.setPosition(pos);
    searchText_.setPosition(pos.x + 8, pos.y + 6);
    updateVisibleCount();
}

static float computeMaxScroll(int filteredSize, int visibleCount, float itemHeight) {
    int excess = std::max(0, filteredSize - visibleCount);
    return float(excess) * itemHeight;
}

void SelectBox::setItems(const std::vector<std::pair<int, std::string>>& items) {
    items_.clear();
    items_.reserve(items.size());
    for (const auto& p : items) items_.push_back({p.first, p.second, false});
    updateFilter();
    scrollOffset_ = 0.f;
}

void SelectBox::handleEvent(const sf::Event &event, sf::Vector2u /*windowSize*/) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == 8 && !searchInput_.empty()) // backspace
            searchInput_.pop_back();
        else if (event.text.unicode >= 32 && event.text.unicode < 128)
            searchInput_ += static_cast<char>(event.text.unicode);
        updateFilter();
        float maxScroll = computeMaxScroll(static_cast<int>(filteredIndices_.size()), visibleCount_, itemHeight_);
        scrollOffset_ = std::clamp(scrollOffset_, 0.f, maxScroll);
    }

    if (event.type == sf::Event::MouseWheelScrolled) {
        scrollOffset_ -= event.mouseWheelScroll.delta * itemHeight_;
        float maxScroll = computeMaxScroll(static_cast<int>(filteredIndices_.size()), visibleCount_, itemHeight_);
        scrollOffset_ = std::clamp(scrollOffset_, 0.f, maxScroll);
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button != sf::Mouse::Left) return;
        sf::Vector2f mouse(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

        float top = box_.getPosition().y + headerHeight_;
        int firstVisible = 0;
        if (!filteredIndices_.empty()) firstVisible = static_cast<int>(std::floor(scrollOffset_ / itemHeight_));
        float innerOffset = std::fmod(scrollOffset_, itemHeight_);
        if (innerOffset < 0) innerOffset = 0.f;

        float y = top - innerOffset;
        for (int vi = 0; vi < visibleCount_ && (firstVisible + vi) < static_cast<int>(filteredIndices_.size()); ++vi, y += itemHeight_) {
            sf::FloatRect rect(box_.getPosition().x + 8, y + (itemHeight_ - 20.f) / 2.f, 20.f, 20.f);
            if (rect.contains(mouse)) {
                int idx = filteredIndices_[firstVisible + vi];
                if (!items_[idx].checked) {
                    int selectedCount = 0;
                    for (const auto& item : items_) {
                        if (item.checked) ++selectedCount;
                    }
                    if (selectedCount < 6) {
                        items_[idx].checked = true;
                        items_[idx].selectedOrder = nextOrder_++;
                    }
                } else {
                    items_[idx].checked = false;
                    items_[idx].selectedOrder = 0;
                    int order = 1;
                    for (auto& item : items_) {
                        if (item.checked) item.selectedOrder = order++;
                    }
                    nextOrder_ = order;
                }
                break;
            }
        }
    }
}

void SelectBox::updateFilter() {
    filteredIndices_.clear();
    for (int i = 0; i < static_cast<int>(items_.size()); ++i) {
        const auto& label = items_[i].label;
        if (searchInput_.empty() || label.find(searchInput_) != std::string::npos)
            filteredIndices_.push_back(i);
    }
    float maxScroll = computeMaxScroll(static_cast<int>(filteredIndices_.size()), visibleCount_, itemHeight_);
    scrollOffset_ = std::clamp(scrollOffset_, 0.f, maxScroll);
}

std::vector<int> SelectBox::getSelectedIds() const {
    std::vector<std::pair<int, int>> ordered;
    for (const auto& item : items_)
        if (item.checked) ordered.emplace_back(item.selectedOrder, item.id);
    std::sort(ordered.begin(), ordered.end());
    std::vector<int> res;
    for (const auto& p : ordered) res.push_back(p.second);
    return res;
}

void SelectBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(box_, states);

    sf::Text searchBar = searchText_;
    searchBar.setString("Recherche: " + searchInput_);
    float searchLeft = box_.getPosition().x + 8.f;
    float searchRight = box_.getPosition().x + box_.getSize().x - 8.f;
    float searchAvail = std::max(16.f, searchRight - (searchLeft + 8.f));
    searchBar.setScale(1.f, 1.f);
    float sbWidth = searchBar.getLocalBounds().width;
    float sbScale = 1.f;
    if (sbWidth > 0.f) sbScale = std::min(1.f, (searchAvail - 4.f) / sbWidth);
    searchBar.setScale(sbScale, sbScale);
    sf::FloatRect sbBounds = searchBar.getGlobalBounds();
    searchBar.setPosition(searchLeft, box_.getPosition().y + (headerHeight_ - sbBounds.height) / 2.f - searchBar.getLocalBounds().top * sbScale);
    target.draw(searchBar, states);

    float top = box_.getPosition().y + headerHeight_;
    float bottom = box_.getPosition().y + box_.getSize().y;

    int firstVisible = 0;
    if (!filteredIndices_.empty()) firstVisible = static_cast<int>(std::floor(scrollOffset_ / itemHeight_));
    float innerOffset = std::fmod(scrollOffset_, itemHeight_);
    if (innerOffset < 0) innerOffset = 0.f;

    float y = top - innerOffset;

    float checkboxX = box_.getPosition().x + 8.f;
    float labelX = box_.getPosition().x + 36.f;
    float labelRight = box_.getPosition().x + box_.getSize().x - 8.f;
    float labelAvail = std::max(8.f, labelRight - labelX);

    for (int vi = 0; vi < visibleCount_ && (firstVisible + vi) < static_cast<int>(filteredIndices_.size()); ++vi, y += itemHeight_) {
        if (y + itemHeight_ < top || y > bottom) continue;

        int idx = filteredIndices_[firstVisible + vi];
        sf::RectangleShape checkbox({20.f, 20.f});
        checkbox.setPosition(checkboxX, y + (itemHeight_ - 20.f) / 2.f);
        checkbox.setFillColor(items_[idx].checked ? sf::Color::Green : sf::Color::White);
        target.draw(checkbox, states);

        sf::Text label;
        label.setFont(font_);
        label.setCharacterSize(18);
        label.setFillColor(sf::Color::White);
        label.setString(items_[idx].label);

        label.setScale(1.f, 1.f);
        float lblWidth = label.getLocalBounds().width;
        float scale = 1.f;
        if (lblWidth > 0.f) scale = std::min(1.f, (labelAvail - 4.f) / lblWidth);
        label.setScale(scale, scale);

        sf::FloatRect gb = label.getGlobalBounds();
        float labelY = y + (itemHeight_ - gb.height) / 2.f - label.getLocalBounds().top * scale;
        label.setPosition(labelX, labelY);
        if (items_[idx].checked) {
            sf::Text orderText;
            orderText.setFont(font_);
            orderText.setCharacterSize(16);
            orderText.setFillColor(sf::Color::Yellow);
            orderText.setString(std::to_string(items_[idx].selectedOrder));
            orderText.setPosition(checkboxX + 22.f, y + (itemHeight_ - 20.f) / 2.f);
            target.draw(orderText, states);
        }
        target.draw(label, states);
    }
}