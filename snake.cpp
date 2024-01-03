#include "snake.hpp"

Snake::Snake()
{   
    const sf::Vector2f snakeSize {10.0, 10.0};
    this->snakeSprite.setFillColor(sf::Color::Yellow);
    this->snakeSprite.setSize(snakeSize);
    this->snakeSprite.setPosition(10, 10);
}

Snake::~Snake()
{
}

void Snake::drawSnake(sf::RenderWindow *window)
{
    window->draw(this->snakeSprite);
}