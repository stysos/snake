#include "snake.hpp"
#include "structs.hpp"

constexpr int movementSpeed = 5;

Snake::Snake()
{
    const sf::Vector2f snakeSize{10.0, 10.0};
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

void Snake::snakeMove(movementDirection direction)
{
    // Todo: Add check for out of bounds - reset on other side.
    // Smart way to do this? Set bound on value? 
    // Check after evaluating then correct? Then don't have to repeat for each.

    switch (direction)
    {
    case up:
        this->snakeSprite.move(0, -movementSpeed);
        break;

    case down:
        this->snakeSprite.move(0, movementSpeed);
        break;

    case left:
        this->snakeSprite.move(-movementSpeed, 0);
        break;

    case right:
        this->snakeSprite.move(movementSpeed, 0);
        break;
    }
}

void Snake::correctOutOfBounds(GameSize gameSettings) {
    sf::Vector2f snakePosition = this->snakeSprite.getPosition();

    int snakeX = static_cast<int>(snakePosition.x);
    int snakeY = static_cast<int>(snakePosition.y);

    if (snakeX < 0) {
        this->snakeSprite.setPosition(gameSettings.x, snakeY);
    } else if (snakeX > gameSettings.x) {
        this->snakeSprite.setPosition(0, snakeY);
    }

    
    if (snakeY < 0) {
        this->snakeSprite.setPosition(snakeX, gameSettings.y);
    } else if (snakeY > gameSettings.y) {
        this->snakeSprite.setPosition(snakeX, 0);
    }
}