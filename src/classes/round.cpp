#include "classes/round.hpp"
#include <iostream>

    Round::Round()
    {
        std::cout<<"First Player name: ";
        std::cin >> result.firstName;
        std::cout<<"Second Player name: ";
        std::cin >> result.secondName;
    }
    Round::~Round(){ std::cout << "End Round" << std::endl;}
    RoundResult Round::getResult(){ return result; }
    bool Round::isRoundEnd()
    {
        bool isBoardFull = true;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[i][j] == 0)
                    isBoardFull = false;
            }
        }
        if (isBoardFull)
            return true;

        for (int i = 0; i < 3; ++i)
        {        
            if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][0] == board[i][2])
                return true;
            if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true;
        }
        if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;
        if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true;
    }

    int Round::calcResult()
    {
        for (int i = 0; i < 3; ++i)
        {        
            if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            {
                if (board[i][0] == 1)
                    return 1;
                return 2;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            {
                if (board[i][0] == 1)
                    return 1;
                return 2;
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            if (board[0][0] == 1)
                return 1;
            return 2;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            if (board[0][0] == 1)
                return 1;
            return 2;
        }
        return 0;
    }
    void Round::play()
    {
        while (true)
        {
            int x;
            int y;
            std::cout<<result.firstName << " step: "<<std::endl;
            std::cin >> x >> y;
            // Проверка x, y на корректность и возможность совершить данный ход
            // иначе - предложить ввести заново
            board[x][y] = 1;
            if (isRoundEnd())
            {
                int res = calcResult();
                if (res == 0)
                {
                    result.firstScore = 0.5;
                    result.secondScore = 0.5;
                }
                if (res == 1)
                {
                    result.firstScore = 1;
                    result.secondScore = 0;
                }
                if (res == 2)
                {
                    result.firstScore = 0;
                    result.secondScore = 1;
                }
                break;
            }
            std::cout<< result.secondName << " step: ";
            std::cin >> x >> y;
            board[x][y] = 2;
            if (isRoundEnd())
            {
                int res = calcResult();
                if (res == 0)
                {
                    result.firstScore = 0.5;
                    result.secondScore = 0.5;
                }
                if (res == 1)
                {
                    result.firstScore = 1;
                    result.secondScore = 0;
                }
                if (res == 2)
                {
                    result.firstScore = 0;
                    result.secondScore = 1;
                }
                break;
            }
        }
    }