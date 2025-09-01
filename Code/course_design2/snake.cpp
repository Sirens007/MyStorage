#include "snake.hpp"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

using namespace SnakeGame;
using std::wcout;
using std::endl;

void Snake::SetPos(short x, short y) {
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x, y };
    SetConsoleCursorPosition(hOutput, pos);
}

Snake::Snake()
    : head(nullptr), food(nullptr), dir(Direction::RIGHT), status(GameStatus::OK),
      foodWeight(10), score(0), sleepTime(200) {}

void Snake::WelcomeToGame() {
    SetPos(40, 14);
    wcout << L"欢迎来到贪吃蛇小游戏" << endl;
    SetPos(42, 20);
    system("pause");
    system("cls");
    SetPos(25, 14);
    wcout << L"用 ↑. ↓ . ← . → 来控制蛇的移动，按F3加速，F4减速" << endl;
    SetPos(25, 15);
    wcout << L"加速能够得到更高的分数" << endl;
    SetPos(42, 20);
    system("pause");
    system("cls");
}

void Snake::CreateMap() {
    for (int i = 0; i < 29; i++) {
        wcout << WALL <<" ";
    }
    SetPos(0, 26);
    for (int i = 0; i < 29; i++) {
        wcout << WALL << " ";
    }
    for (int i = 1; i <= 25; i++) {
        SetPos(0, i);
        wcout << WALL;
    }
    for (int i = 1; i <= 25; i++) {
        SetPos(56, i);
        wcout << WALL;
    }
}

void Snake::InitSnake() {
    head = nullptr;
    for (int i = 0; i < 5; ++i) {
        auto node = std::make_shared<SnakeNode>(POS_X + 2 * i, POS_Y);
        node->next = head;
        head = node;
    }
    for (auto cur = head; cur; cur = cur->next) {
        SetPos(cur->x, cur->y);
        wcout << BODY;
    }
    dir = Direction::RIGHT;
    score = 0;
    foodWeight = 10;
    sleepTime = 200;
    status = GameStatus::OK;
}

void Snake::CreateFood() {
    int x, y;
again:
    do {
        x = rand() % 53 + 2;
        y = rand() % 25 + 1;
    } while (x % 2 != 0);
    for (auto cur = head; cur; cur = cur->next) {
        if (x == cur->x && y == cur->y)
            goto again;
    }
    food = std::make_shared<SnakeNode>(x, y);
    SetPos(x, y);
    wcout << FOOD;
}

void Snake::PrintHelpInfo() {
    SetPos(64, 14); wcout << L"不能穿墙，不能咬到自己";
    SetPos(64, 15); wcout << L"用 ↑. ↓ . ← . → 来控制蛇的移动";
    SetPos(64, 16); wcout << L"按F3加速，F4减速";
    SetPos(64, 17); wcout << L"按ESC退出游戏，按空格暂停游戏";
    SetPos(64, 18); wcout << L"比特就业课制作";
}

void Snake::Pause() {
    while (true) {
        Sleep(200);
        if (GetAsyncKeyState(VK_SPACE) & 1)
            break;
    }
}

bool Snake::NextIsFood(const std::shared_ptr<SnakeNode>& node) {
    return food && node->x == food->x && node->y == food->y;
}

void Snake::EatFood(const std::shared_ptr<SnakeNode>& node) {
    food->next = head;
    head = food;
    for (auto cur = head; cur; cur = cur->next) {
        SetPos(cur->x, cur->y);
        wcout << BODY;
    }
    score += foodWeight;
    CreateFood();
}

void Snake::NoFood(const std::shared_ptr<SnakeNode>& node) {
    node->next = head;
    head = node;
    auto cur = head;
    while (cur->next->next) {
        SetPos(cur->x, cur->y);
        wcout << BODY;
        cur = cur->next;
    }
    SetPos(cur->next->x, cur->next->y);
    wcout << L"  ";
    cur->next.reset();
}

void Snake::KillByWall() {
    if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)
        status = GameStatus::KILL_BY_WALL;
}

void Snake::KillBySelf() {
    for (auto cur = head->next; cur; cur = cur->next) {
        if (cur->x == head->x && cur->y == head->y) {
            status = GameStatus::KILL_BY_SELF;
            break;
        }
    }
}

void Snake::SnakeMove() {
    auto next = std::make_shared<SnakeNode>(0, 0);
    switch (dir) {
    case Direction::UP: next->x = head->x; next->y = head->y - 1; break;
    case Direction::DOWN: next->x = head->x; next->y = head->y + 1; break;
    case Direction::LEFT: next->x = head->x - 2; next->y = head->y; break;
    case Direction::RIGHT: next->x = head->x + 2; next->y = head->y; break;
    }
    if (NextIsFood(next)) EatFood(next);
    else NoFood(next);
    KillByWall();
    KillBySelf();
}

void Snake::GameStart() {
    system("mode con cols=100 lines=30");
    system("title 贪吃蛇");
    HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hOutput, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hOutput, &cursorInfo);
    WelcomeToGame();
    CreateMap();
    InitSnake();
    CreateFood();
}

void Snake::GameRun() {
    PrintHelpInfo();
    do {
        SetPos(64, 10); std::wcout << L"总分数: " << score << L"\n";
        SetPos(64, 11); std::wcout << L"当前食物分数: " << foodWeight << L"\n";

        if ((GetAsyncKeyState(VK_UP) & 1) && dir != Direction::DOWN) dir = Direction::UP;
        else if ((GetAsyncKeyState(VK_DOWN) & 1) && dir != Direction::UP) dir = Direction::DOWN;
        else if ((GetAsyncKeyState(VK_LEFT) & 1) && dir != Direction::RIGHT) dir = Direction::LEFT;
        else if ((GetAsyncKeyState(VK_RIGHT) & 1) && dir != Direction::LEFT) dir = Direction::RIGHT;
        else if (GetAsyncKeyState(VK_SPACE) & 1) Pause();
        else if (GetAsyncKeyState(VK_ESCAPE) & 1) status = GameStatus::END_NORMAL;
        else if (GetAsyncKeyState(VK_F3) & 1 && sleepTime > 80) { sleepTime -= 30; foodWeight += 2; }
        else if (GetAsyncKeyState(VK_F4) & 1 && foodWeight > 2) { sleepTime += 30; foodWeight -= 2; }

        SnakeMove();
        Sleep(sleepTime);
    } while (status == GameStatus::OK);
}

void Snake::GameEnd() {
    SetPos(24, 12);
    switch (status) {
    case GameStatus::END_NORMAL:
        wcout << L"您主动结束游戏" << endl; break;
    case GameStatus::KILL_BY_WALL:
        wcout << L"您撞到墙上，游戏结束" << endl; break;
    case GameStatus::KILL_BY_SELF:
        wcout << L"您撞到了自己，游戏结束" << endl; break;
    }
}