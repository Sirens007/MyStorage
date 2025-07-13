#define _CRT_SECURE_NO_WARNINGS 1

#include <locale.h>
#include <ctime>
#include "snake.hpp"

// 完成的是游戏的测试逻辑
void test()
{
    int ch = 0;
    do
    {
        system("cls");
        // 创建贪吃蛇
        SnakeGame::Snake snake;
        // 初始化游戏
        snake.GameStart();

        // 运行游戏
        snake.GameRun();
        // 结束游戏 - 善后工作
        snake.GameEnd();
        snake.SetPos(20, 15);
        wprintf(L"再来一局吗?(Y/N):");
        ch = getchar();
        while (getchar() != '\n');

    } while (ch == 'Y' || ch == 'y');
    SnakeGame::Snake().SetPos(0, 27);
}

int main()
{
    // 设置适配本地环境
    setlocale(LC_ALL, "");
    srand((unsigned int)time(NULL));
    test();

    return 0;
}