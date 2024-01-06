#include <iostream>

#include "snake.hpp"
#include "structs.hpp"
#include "food.hpp"

constexpr int movementSpeed = 5;

Snake::Snake()
{
    const sf::Vector2f snakeSize{ 10.0, 10.0 };
    this->snakeSprite.setFillColor(sf::Color::Yellow);
    this->snakeSprite.setSize(snakeSize);
    this->snakeSprite.setPosition(10, 10);
}

Snake::~Snake()
{
}

void Snake::drawSnake(sf::RenderWindow* window)
{
    window->draw(this->snakeSprite);
}



void Snake::checkCollisions(GameSize gameSettings, Food* food) {

    this->correctOutOfBounds(gameSettings);
    this->checkFood(food);

}

void Snake::checkFood(Food* food) {

    sf::Vector2f foodPosition = food->getPosition();
    sf::Vector2f snakePosition = this->snakeSprite.getPosition();

    if (snakePosition.x == foodPosition.x and snakePosition.y == foodPosition.y) {
        this->eatFood();
        food->createNew();
    }

}

void Snake::eatFood() {
    std::cout << "Add new part to snake!" << std::endl;
}


void Snake::snakeMove(movementDirection direction)
{

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
    }
    else if (snakeX > gameSettings.x) {
        this->snakeSprite.setPosition(0, snakeY);
    }


    if (snakeY < 0) {
        this->snakeSprite.setPosition(snakeX, gameSettings.y);
    }
    else if (snakeY > gameSettings.y) {
        this->snakeSprite.setPosition(snakeX, 0);
    }
}