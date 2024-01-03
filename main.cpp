#include <iostream>

#include "gameWindow.hpp"

int main(int, char**){
    std::cout << "Hello, from snake!\n";

    GameWindow gameWindow(720, 480);


    gameWindow.runningLoop();

}
