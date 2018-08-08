#pragma once
#ifndef REAL_TIME_DEMO_GAME_H
#define REAL_TIME_DEMO_GAME_H
#include "./InputController.h"
#include "./LevelManager.h"
#include "./ScoreBoard.h"
#include "./House.h"
class Game {
 public:
    explicit Game(int gameMode);
    template<class T>
    int getProduced() {
        return getProduced(typeid(T).hash_code());
    }
    int getProduced(size_t type);
    bool getLooping();
    void setLooping(bool newLooping);
    int getRowConsole();
    int getColConsole();
    int getGameMode();
    void setGameMode(int newGameMode);
    void gameEnd(IoCContainer *container, ScoreBoard *scoreBoard, bool WinNotLose);
    void changeMap(InputController *inputObject, IoCContainer *container,
                   ScoreBoard *scoreBoard);
    void eachSecondUpdate(IoCContainer *container);
    void update(InputController *inputObject, IoCContainer *container, ScoreBoard *scoreBoard, double deltaTime);
    void gameLoop();
//    void eachSecondUpdate(InputController *inputObject, LevelManager *levelObject,
//                           ScoreBoard *scoreBoard);

 private:
    char symbol = '@';        // символ игрока
    int rowConsole = 20;      // координаты консоли
    int colConsole = 10;      //
    bool looping = true;  // переменная игровой петли
    int gameMode = 0;
};
#endif  // REAL_TIME_DEMO_GAME_H
