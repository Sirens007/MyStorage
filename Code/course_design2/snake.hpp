#pragma once

#include <windows.h>
#include <vector>
#include <memory>
#include <cstdlib>
#include <cstdio>
#include <ctime>

namespace SnakeGame {
    constexpr short POS_X = 24;
    constexpr short POS_Y = 5;

    constexpr wchar_t WALL = L'□';
    constexpr wchar_t BODY = L'●';
    constexpr wchar_t FOOD = L'★';

    // 蛇的方向
    enum class Direction {
        UP = 1,
        DOWN,
        LEFT,
        RIGHT
    };

    // 蛇的状态
    enum class GameStatus {
        OK,
        KILL_BY_WALL,
        KILL_BY_SELF,
        END_NORMAL
    };

    // 蛇身节点类型
    class SnakeNode {
    public:
        int x;
        int y;
        std::shared_ptr<SnakeNode> next;

        SnakeNode(int x, int y) : x(x), y(y), next(nullptr) {}
    };

    // 贪吃蛇
    class Snake {
    private:
        std::shared_ptr<SnakeNode> head;
        std::shared_ptr<SnakeNode> food;
        Direction dir;
        GameStatus status;
        int foodWeight;
        int score;
        int sleepTime;

    public:
        Snake();

        void SetPos(short x, short y);
        void WelcomeToGame();
        void CreateMap();
        void InitSnake();
        void CreateFood();
        void PrintHelpInfo();
        void Pause(); // Ensure Pause is declared here
        bool NextIsFood(const std::shared_ptr<SnakeNode>& node);
        void EatFood(const std::shared_ptr<SnakeNode>& node);
        void NoFood(const std::shared_ptr<SnakeNode>& node);
        void KillByWall();
        void KillBySelf();
        void SnakeMove();
        void GameStart();
        void GameRun();
        void GameEnd();
    };
}
