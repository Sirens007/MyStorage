#define _CRT_SECURE_NO_WARNINGS 1

#include <locale.h>
#include <ctime>
#include "snake.hpp"

// ��ɵ�����Ϸ�Ĳ����߼�
void test()
{
    int ch = 0;
    do
    {
        system("cls");
        // ����̰����
        SnakeGame::Snake snake;
        // ��ʼ����Ϸ
        snake.GameStart();

        // ������Ϸ
        snake.GameRun();
        // ������Ϸ - �ƺ���
        snake.GameEnd();
        snake.SetPos(20, 15);
        wprintf(L"����һ����?(Y/N):");
        ch = getchar();
        while (getchar() != '\n');

    } while (ch == 'Y' || ch == 'y');
    SnakeGame::Snake().SetPos(0, 27);
}

int main()
{
    // �������䱾�ػ���
    setlocale(LC_ALL, "");
    srand((unsigned int)time(NULL));
    test();

    return 0;
}