#pragma once
#ifndef REAL_TIME_DEMO_GAME_H
#define REAL_TIME_DEMO_GAME_H
#include <map>
#include "./InputController.h"
#include "./LevelManager.h"
#include "./ScoreBoard.h"
#include "./GameCamera.h"
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
    void update(IoCContainer *container, ScoreBoard *scoreBoard, double deltaTime, GameCamera* gameCamera);
    void gameLoop();
    void ChangeGameMode(IoCContainer* container, int keyCode, GameCamera* camera);
    void CreateTypeList(IoCContainer *container);
    void AddTypeToTypeList(size_t type, IObject* exemplar);
    void RemoveTypeFromTypeList(size_t type);
    size_t GetTypeOnIndex(int index);
    IObject** GetTypeList();
    int GetTypeListSize();
    void CreateNewBuilding(size_t type, IoCContainer* container);
    bool GetCanBuild();
    void SetCanBuild(bool newCanBuild);

 private:
    char symbol = '@';        // символ игрока
    int rowConsole = 20;      // координаты консоли
    int colConsole = 10;      //
    bool looping = true;  // переменная игровой петли
    int gameMode = 0;  // 0 - игра, 1 - выбор здания для строительства, 2 - строительство на карте
    std::map<size_t, IObject*> typeList;
    int HardcodedBuildingY = 7;
    int HardcodedBuildingX = 4;
    bool canBuild = false;
};
#endif  // REAL_TIME_DEMO_GAME_H
