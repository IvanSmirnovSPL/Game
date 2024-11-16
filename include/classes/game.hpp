#pragma once

namespace game
{

class Game
{
public:
    Game();
    ~Game();
    bool isActive();
    void doStep();
private:
    int step;
};

}