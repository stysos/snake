#include <SFML/Graphics.hpp>

#include "snake.hpp"
#include "structs.hpp"
#include "food.hpp"

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
    Food food;

    void setSettings(int x, int y);
};