#include <SFML/Graphics.hpp>
#include "structs.hpp"

#include "food.hpp"

enum movementDirection {
    up,
    down,
    left,
    right
};

class Snake {
public:
    Snake();
    ~Snake();
    void snakeMove(movementDirection direction);
    void drawSnake(sf::RenderWindow* window);

    void checkCollisions(GameSize gameSettings, Food* food);

private:
    void correctOutOfBounds(GameSize gameSettings);
    void checkFood(Food* food);
    void eatFood();

    sf::Texture snakeTexture;
    sf::RectangleShape snakeSprite;


};