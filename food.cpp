#include "food.hpp"

Food::Food() {
    this->createNew();
}

Food::~Food() {}

void Food::createNew() {
    int x = 50;
    int y = 50;

    const sf::Vector2f foodSize(10.0, 10.0);

    this->foodSprite.setPosition(x, y);
    this->foodSprite.setSize(foodSize);

    this->foodSprite.setFillColor(sf::Color::Red);
}

sf::Vector2f Food::getPosition() {
    sf::Vector2f position = this->foodSprite.getPosition(); 
    return position;
}

void Food::drawFood(sf::RenderWindow* window) {
    window->draw(this->foodSprite);
}
