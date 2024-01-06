#include <iostream>

#include "snake.hpp"
#include "structs.hpp"
#include "food.hpp"

constexpr int movementSpeed = 5;

Snake::Snake()
{
    this->snakeSprite = this->createPart(sf::Color::Yellow);
}

Snake::~Snake()
{
}

void Snake::drawSnake(sf::RenderWindow* window)
{
    window->draw(this->snakeSprite);

    for (auto& part : this->snakeBody) {
        window->draw(part);
    }
}

sf::RectangleShape Snake::createPart(sf::Color color) {
    const sf::Vector2f snakeSize{ 10.0, 10.0 };
    sf::RectangleShape newPart;

    newPart.setFillColor(color);
    newPart.setSize(snakeSize);
    newPart.setPosition(10, 10);

    return newPart;
}



void Snake::checkCollisions(GameSize gameSettings, Food* food) {

    this->correctOutOfBounds(gameSettings);
    this->checkFood(food);

}

void Snake::checkFood(Food* food) {

    sf::Vector2f foodPosition = food->getPosition();
    // TODO: Add plus or minus size ( Maybe function to take sf::Vector2f and check if equal +- size of RectangleShape)
    sf::Vector2f snakePosition = this->snakeSprite.getPosition();

    if (snakePosition.x == foodPosition.x and snakePosition.y == foodPosition.y) {
        this->eatFood();
        food->createNew();
    }

}

void Snake::eatFood() {
    std::cout << "Add new part to snake!" << std::endl;
    sf::RectangleShape newPart;

    newPart = this->createPart(sf::Color::Green);

    if (this->snakeBody.size() == 0) {
        newPart.setPosition(this->snakeSprite.getPosition() + this->snakeSprite.getSize());
    }
    else {
        newPart.setPosition(this->snakeBody.back().getPosition() + this->snakeSprite.getSize());
    }


    this->snakeBody.push_back(newPart);
}


void Snake::snakeMove(movementDirection direction)
{
    // create Move function that takes x, y and moves all to simplify.

    switch (direction)
    {
    case up:
        this->snakeSprite.move(0, -movementSpeed);
        for (auto& part : this->snakeBody) {
            part.move(0, -movementSpeed);
        }
        break;

    case down:
        this->snakeSprite.move(0, movementSpeed);
        for (auto& part : this->snakeBody) {
            part.move(0, movementSpeed);
        }
        break;

    case left:
        this->snakeSprite.move(-movementSpeed, 0);
        for (auto& part : this->snakeBody) {
            part.move(-movementSpeed, 0);
        }
        break;

    case right:
        this->snakeSprite.move(movementSpeed, 0);
        for (auto& part : this->snakeBody) {
            part.move(movementSpeed, 0);
        }
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