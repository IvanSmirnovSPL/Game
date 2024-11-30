#pragma once
#include <string>

struct RoundResult
{
    std::string firstName = "A";
    std::string secondName = "B";
    float firstScore;
    float secondScore;
};

class Round
{
public:
    Round();
    ~Round();
    RoundResult getResult();
    void play();
    bool isRoundEnd();
    int calcResult();
private:
    RoundResult result;
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    // класс Drawing (создаём в конструкторе) с функцией draw(board)
};