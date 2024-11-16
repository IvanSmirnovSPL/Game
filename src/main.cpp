#include "main.hpp"
#include "classes/game.hpp"
#include <iostream>

int main()
{
    game::Game game{};
    while (game.isActive())
    {
        game.doStep();
    }
    std::cout << "The END" << std::endl;
    return 0;
}