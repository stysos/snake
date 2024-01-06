#include <SFML/Graphics.hpp>
#include "gameWindow.hpp"

GameWindow::GameWindow(int x, int y)
{
    this->setSettings(x, y);
    this->window.create(sf::VideoMode(x, y), "Snake");
    this->window.setFramerateLimit(20);
}

void GameWindow::setSettings(int x, int y)
{
    this->gameSettings.x = x;
    this->gameSettings.y = y;
}

GameWindow::~GameWindow() {}

void GameWindow::runningLoop()
{

    movementDirection direction = right;

    while (this->window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                direction = up;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                direction = down;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                direction = right;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                direction = left;
            }
        }

        this->window.clear(sf::Color::Black);

        snake.snakeMove(direction);

        snake.checkCollisions(this->gameSettings, &this->food);

        food.drawFood(&this->window);

        snake.drawSnake(&this->window);

        this->window.display();
    }
}
