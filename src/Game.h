#ifndef REAL_TIME_DEMO_GAME_H
#define REAL_TIME_DEMO_GAME_H
#include "./InputController.h"
#include "./LevelManager.h"
#include "./ScoreBoard.h"
class Game {
 public:
    explicit Game(int gameMode);
    bool getLooping();
    void setLooping(bool newLooping);
    int getRowConsole();
    int getColConsole();
    int getGameMode();
    void setGameMode(int newGameMode);
    void gameEnd(LevelManager *levelManager, ScoreBoard *scoreBoard, bool WinNotLose);
    void changeMap(InputController *inputObject, LevelManager *levelManager,
                   ScoreBoard *scoreBoard);
    void update(InputController *inputObject, LevelManager *levelObject, ScoreBoard *scoreBoard, double deltaTime);
    void gameLoop();

 private:
    char symbol = '@';        // символ игрока
    int rowConsole = 20;      // координаты консоли
    int colConsole = 10;      //
    bool looping = true;  // переменная игровой петли
    int gameMode = 0;
};
#endif  // REAL_TIME_DEMO_GAME_H
