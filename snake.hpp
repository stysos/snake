#include <SFML/Graphics.hpp>
#include "structs.hpp"

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
    void drawSnake(sf::RenderWindow *window);
    void correctOutOfBounds(GameSize gameSettings);

    private:
    sf::Texture snakeTexture; 
    sf::RectangleShape snakeSprite;

};