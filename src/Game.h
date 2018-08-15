#pragma once
#ifndef REAL_TIME_DEMO_GAME_H
#define REAL_TIME_DEMO_GAME_H
#include "./InputController.h"
#include "./LevelManager.h"
#include "./ScoreBoard.h"
#include "./GameRender.h"
class Game {
 public:
    explicit Game(int gameMode);
    template<class T>
    int getProduced(IoCContainer *container) {
        return getProduced(container, typeid(T).hash_code());
    }
    int getProduced(IoCContainer *container, size_t type);
    bool getLooping();
    void setLooping(bool newLooping);
    int getRowConsole();
    int getColConsole();
    int getGameMode();
    void setGameMode(int newGameMode);
    void gameEnd(IoCContainer *container, ScoreBoard *scoreBoard, bool WinNotLose);
    void changeMap(InputController *inputObject, IoCContainer *container,
                   ScoreBoard *scoreBoard);
    void CreateResources(IoCContainer *container, int startValue);
    void CreateStartBuildings(IoCContainer *container, int value);
    void eachSecondUpdate(IoCContainer *container);
    void update(InputController *inputObject, IoCContainer *container, ScoreBoard *scoreBoard, double deltaTime);
    void gameLoop();
    void ChangeGameMode(IoCContainer* container, int keyCode);
    void CreateTypeList(IoCContainer *container, GameRender* gameRender);


 private:
    char symbol = '@';        // символ игрока
    int rowConsole = 20;      // координаты консоли
    int colConsole = 10;      //
    bool looping = true;  // переменная игровой петли
    int gameMode = 0;  // 0 - игра, 1 - выбор здания для строительства, 2 - строительство на карте
};
#endif  // REAL_TIME_DEMO_GAME_H
