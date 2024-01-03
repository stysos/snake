#include <SFML/Graphics.hpp>

#include "snake.hpp"

struct GameSize {
    int x;
    int y;
};

class GameWindow
{
public:
    GameWindow(int x, int y);
    ~GameWindow();

    GameSize gameSettings;
    void runningLoop();

private:
    sf::RenderWindow window;
    Snake snake;

    void setSettings(int x, int y);
};