#include "draw_utils.h"

void drawPoint(sf::RenderWindow& window, float x, float y, sf::Color color) {
    sf::RectangleShape rect(sf::Vector2<float>(DOT_SIZE, DOT_SIZE));
    rect.setFillColor(color);
    rect.setPosition(x - DOT_SIZE/2, y - DOT_SIZE/2);
    window.draw(rect);
}