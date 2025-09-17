#include "SelectBox.hpp"
#include <algorithm>
#include <sstream>
#include <cmath>

SelectBox::SelectBox(const sf::Font &font, sf::Vector2f position, sf::Vector2f size)
    : font_(font),
      scrollOffset_(SCROLL_OFFSET),
      headerHeight_(HEADER_HEIGHT),
      itemHeight_(ITEM_HEIGHT),
      nextOrder_(SECOND_VALUE)
{
    box_.setPosition(position);
    box_.setSize(size);
    box_.setFillColor(sf::Color(40, 40, 40));
    box_.setOutlineColor(sf::Color::White);
    box_.setOutlineThickness(LINE_THICKNESS);

    searchText_.setFont(font_);
    searchText_.setCharacterSize(BUTTON_PADDING);
    searchText_.setFillColor(sf::Color::White);
    searchText_.setPosition(position.x + SEARCH_TEXT_X_MARGIN, position.y + SEARCH_TEXT_Y_MARGIN);

    updateVisibleCount();
    updateFilter();
}

void SelectBox::updateVisibleCount() {
    int available = std::max(FIRST_VALUE, int((box_.getSize().y - headerHeight_) / itemHeight_));
    visibleCount_ = std::max(SECOND_VALUE, available);
}

void SelectBox::setPosition(sf::Vector2f pos) {
    box_.setPosition(pos);
    searchText_.setPosition(pos.x + SEARCH_TEXT_X_MARGIN, pos.y + SEARCH_TEXT_Y_MARGIN);
    updateVisibleCount();
}

static float computeMaxScroll(int filteredSize, int visibleCount, float itemHeight) {
    int excess = std::max(FIRST_VALUE, filteredSize - visibleCount);
    return float(excess) * itemHeight;
}

void SelectBox::setItems(const std::vector<std::pair<int, std::string>>& items) {
    items_.clear();
    items_.reserve(items.size());
    for (const auto& p : items) items_.push_back({p.first, p.second, false});
    updateFilter();
    scrollOffset_ = SCROLL_OFFSET;
}

void SelectBox::handleEvent(const sf::Event &event, sf::Vector2u) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == BACKSPACE_KEY && !searchInput_.empty())
            searchInput_.pop_back();
        else if (event.text.unicode >= FIRST_KEY && event.text.unicode < LAST_KEY)
            searchInput_ += static_cast<char>(event.text.unicode);
        updateFilter();
        float maxScroll = computeMaxScroll(static_cast<int>(filteredIndices_.size()), visibleCount_, itemHeight_);
        scrollOffset_ = std::clamp(scrollOffset_, SCROLL_OFFSET, maxScroll);
    }

    if (event.type == sf::Event::MouseWheelScrolled) {
        scrollOffset_ -= event.mouseWheelScroll.delta * itemHeight_;
        float maxScroll = computeMaxScroll(static_cast<int>(filteredIndices_.size()), visibleCount_, itemHeight_);
        scrollOffset_ = std::clamp(scrollOffset_, SCROLL_OFFSET, maxScroll);
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button != sf::Mouse::Left) return;
        sf::Vector2f mouse(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

        float top = box_.getPosition().y + headerHeight_;
        int firstVisible = FIRST_VALUE;
        if (!filteredIndices_.empty()) firstVisible = static_cast<int>(std::floor(scrollOffset_ / itemHeight_));
        float innerOffset = std::fmod(scrollOffset_, itemHeight_);
        if (innerOffset < FIRST_VALUE) innerOffset = SCROLL_OFFSET;

        float y = top - innerOffset;
        for (int vi = FIRST_VALUE; vi < visibleCount_ && (firstVisible + vi) < static_cast<int>(filteredIndices_.size()); ++vi, y += itemHeight_) {
            sf::FloatRect rect(box_.getPosition().x + SEARCH_TEXT_X_MARGIN, y + (itemHeight_ - BUTTON_PADDING) / LINE_THICKNESS, BUTTON_PADDING, BUTTON_PADDING);
            if (rect.contains(mouse)) {
                int idx = filteredIndices_[firstVisible + vi];
                if (!items_[idx].checked) {
                    int selectedCount = FIRST_VALUE;
                    for (const auto& item : items_) {
                        if (item.checked) ++selectedCount;
                    }
                    if (selectedCount < MAX_POKEMON_IN_PARTY) {
                        items_[idx].checked = true;
                        items_[idx].selectedOrder = nextOrder_++;
                    }
                } else {
                    items_[idx].checked = false;
                    items_[idx].selectedOrder = FIRST_VALUE;
                    int order = SECOND_VALUE;
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
    for (int i = FIRST_VALUE; i < static_cast<int>(items_.size()); ++i) {
        const auto& label = items_[i].label;
        if (searchInput_.empty() || label.find(searchInput_) != std::string::npos)
            filteredIndices_.push_back(i);
    }
    float maxScroll = computeMaxScroll(static_cast<int>(filteredIndices_.size()), visibleCount_, itemHeight_);
    scrollOffset_ = std::clamp(scrollOffset_, SCROLL_OFFSET, maxScroll);
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
    searchBar.setString(SEARCH_BAR_TEXT + searchInput_);
    float searchLeft = box_.getPosition().x + SEARCH_TEXT_MARGIN;
    float searchRight = box_.getPosition().x + box_.getSize().x - SEARCH_TEXT_MARGIN;
    float searchAvail = std::max(2 * SEARCH_TEXT_MARGIN, searchRight - (searchLeft + SEARCH_TEXT_MARGIN));
    searchBar.setScale(SEARCH_BAR_SCALE, SEARCH_BAR_SCALE);
    float sbWidth = searchBar.getLocalBounds().width;
    float sbScale = SEARCH_BAR_SCALE;
    if (sbWidth > SCROLL_OFFSET) sbScale = std::min(SEARCH_BAR_SCALE, (searchAvail - 2*LINE_THICKNESS) / sbWidth);
    searchBar.setScale(sbScale, sbScale);
    sf::FloatRect sbBounds = searchBar.getGlobalBounds();
    searchBar.setPosition(searchLeft, box_.getPosition().y + (headerHeight_ - sbBounds.height) / LINE_THICKNESS - searchBar.getLocalBounds().top * sbScale);
    target.draw(searchBar, states);

    float top = box_.getPosition().y + headerHeight_;
    float bottom = box_.getPosition().y + box_.getSize().y;

    int firstVisible = FIRST_VALUE;
    if (!filteredIndices_.empty()) firstVisible = static_cast<int>(std::floor(scrollOffset_ / itemHeight_));
    float innerOffset = std::fmod(scrollOffset_, itemHeight_);
    if (innerOffset < FIRST_VALUE) innerOffset = SCROLL_OFFSET;

    float y = top - innerOffset;

    float checkboxX = box_.getPosition().x + SEARCH_TEXT_MARGIN;
    float labelX = box_.getPosition().x + LABEL_OFFSET;
    float labelRight = box_.getPosition().x + box_.getSize().x - SEARCH_TEXT_MARGIN;
    float labelAvail = std::max(SEARCH_TEXT_MARGIN, labelRight - labelX);

    for (int vi = FIRST_VALUE; vi < visibleCount_ && (firstVisible + vi) < static_cast<int>(filteredIndices_.size()); ++vi, y += itemHeight_) {
        if (y + itemHeight_ < top || y > bottom) continue;

        int idx = filteredIndices_[firstVisible + vi];
        sf::RectangleShape checkbox({BUTTON_PADDING, BUTTON_PADDING});
        checkbox.setPosition(checkboxX, y + (itemHeight_ - BUTTON_PADDING) / LINE_THICKNESS);
        checkbox.setFillColor(items_[idx].checked ? sf::Color::Green : sf::Color::White);
        target.draw(checkbox, states);

        sf::Text label;
        label.setFont(font_);
        label.setCharacterSize(LABEL_CHARACTER_SIZE);
        label.setFillColor(sf::Color::White);
        label.setString(items_[idx].label);

        label.setScale(SEARCH_BAR_SCALE, SEARCH_BAR_SCALE);
        float lblWidth = label.getLocalBounds().width;
        float scale = SEARCH_BAR_SCALE;
        if (lblWidth > SCROLL_OFFSET) scale = std::min(SEARCH_BAR_SCALE, (labelAvail - BUTTON_PADDING*2) / lblWidth);
        label.setScale(scale, scale);

        sf::FloatRect gb = label.getGlobalBounds();
        float labelY = y + (itemHeight_ - gb.height) / LINE_THICKNESS - label.getLocalBounds().top * scale;
        label.setPosition(labelX, labelY);
        if (items_[idx].checked) {
            sf::Text orderText;
            orderText.setFont(font_);
            orderText.setCharacterSize(LABEL_CHARACTER_SIZE);
            orderText.setFillColor(sf::Color::Yellow);
            orderText.setString(std::to_string(items_[idx].selectedOrder));
            orderText.setPosition(checkboxX + BUTTON_PADDING+2, y + (itemHeight_ - BUTTON_PADDING) / LINE_THICKNESS);
            target.draw(orderText, states);
        }
        target.draw(label, states);
    }
}