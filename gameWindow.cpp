#include <SFML/Graphics.hpp>
#include "gameWindow.hpp"

GameWindow::GameWindow(int x, int y)
{   
    this->setSettings(x, y);
    this->window.create(sf::VideoMode(x, y), "Snake");
    this->window.setFramerateLimit(20);
}

void GameWindow::setSettings(int x, int y) {
    this->gameSettings.x = x;
    this->gameSettings.y = y;
}

GameWindow::~GameWindow() {}

void GameWindow::runningLoop()
{
    while (this->window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                this->window.close();
            }
        }

        this->window.clear(sf::Color::Black);

        snake.drawSnake(&this->window);

        this->window.display();
    }
}
