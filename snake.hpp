#include <SFML/Graphics.hpp>

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

    private:
    sf::Texture snakeTexture; 
    sf::RectangleShape snakeSprite;
};