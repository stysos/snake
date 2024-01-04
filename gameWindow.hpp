#include <SFML/Graphics.hpp>

#include "snake.hpp"
#include "structs.hpp"

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