#pragma once

#include <SFML/Graphics.hpp>


class Food
{
public:
    Food();
    ~Food();



    void drawFood(sf::RenderWindow* window);
    void createNew();
    sf::Vector2f getPosition();

private:
    sf::RectangleShape foodSprite;
    sf::Texture foodTexture;
};