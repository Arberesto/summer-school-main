#include "./Game.h"
#include <ncurses.h>
#include <cstdio>
#include <string>
#include <chrono>
#include <utility>
#include "./Utility.h"
#include "./GameRender.h"
#include "./InputController.h"
#include "./LevelManager.h"
#include "./ScoreBoard.h"
#include "./GameCamera.h"
#include "./IncludeObjects.h"
Game::Game(int gameMode) {
    setGameMode(gameMode);
    canBuild = true;
}

    bool Game::getLooping() {
        return looping;
    }

    void Game::setLooping(bool newLooping) {
        looping = newLooping;
    }

    int Game::getRowConsole() {
        return rowConsole;
    }

    int Game::getColConsole() {
        return colConsole;
    }

    int Game::getGameMode() {
        return gameMode;
    }

    void Game::setGameMode(int newGameMode) {
        gameMode = newGameMode;
    }

    void Game::gameEnd(IoCContainer *container, ScoreBoard *scoreBoard, bool WinNotLose) {  // Game
        // показываем таблицу текущего
        // уровня,либо закрываем игру

        if (WinNotLose) {
            setGameMode(4);
            // levelManager->loadLevel(1);
//      addResultToWinTable(getCurrentLevel());
//      refresh();
//      drawScoreTable(getCurrentLevel());
//      refresh();
        } else {
            setGameMode(3);
//      clear();
//      drawLosePicture();
//      setCurrentLevel(1);
//      setPrevSteps(0);
//      loadMap(1);
        }
    }

    void Game::changeMap(InputController *inputObject, IoCContainer *container,
                   ScoreBoard *scoreBoard) {
    }

    void Game::eachSecondUpdate(IoCContainer *container) {
        auto levelManager = container->Get<LevelManager>(1);
        if ((levelManager->GetIsNewSecondNow())&&(levelManager->getLastSecond() % 10 == 0)) {
            auto resourceIdList = container->GetIdList<Resource>();
            for (int i = 0; i < static_cast<int>(resourceIdList[0][0]); i++) {
                size_t typeTemp = resourceIdList[i][2];
                for (int j = 0; j < static_cast<int>(resourceIdList[i][1]); j++) {
                    int idTemp = static_cast<int>(resourceIdList[i][3 + j]);
                    auto objectTemp = static_cast<Resource *>(container->Get(idTemp, typeTemp));
                    objectTemp->IncreaseValue(getProduced(container, typeTemp));
                }
            }
            levelManager->SetIsNewSecondNow(false);
        }
    }

    int Game::getProduced(IoCContainer *container, size_t type) {
        int result = 0;
        auto buildingList = container->GetIdList<ProducingBuilding>();
        for (int i = 0; i < static_cast<int>(buildingList[0][0]); i++) {
            size_t typeTemp = buildingList[i][2];
            for (int j = 0; j < static_cast<int>(buildingList[i][1]); j++) {
                auto idTemp = static_cast<int>(buildingList[i][3 + j]);
                auto objectTemp = static_cast<ProducingBuilding*>(container->Get(idTemp, typeTemp));
                if (objectTemp->GetProduceType() == type) {
                    result += objectTemp->GetRealProduceAmount();
                }
            }
        }
        return result;
    }

    void Game::update(InputController *inputObject, IoCContainer *container,
                      ScoreBoard *scoreBoard, double deltaTime) {
        auto levelObject = container->Get<LevelManager>(1);
        if (getGameMode() == 0) {
            levelObject->IncreaseSecondsUsed(deltaTime);
            levelObject->IncreaseTickCounter(1);
        }
        if (getGameMode() == 1) {
            inputObject->ShiftCurrentLine(inputObject->getAxisY(), static_cast<int>(typeList.size()));
        }
        eachSecondUpdate(container);
//        if (container->GetIdList<MainBuilding>[0][0] == 0) {
//            levelObject->loadLevel(1);
//            gameEnd(levelObject, scoreBoard, false);
//            return;
//        }
        if (inputObject->isInBuffer(0)) {  // выход из игры
            setLooping(false);
        } else {
            inputObject->setDirection(-1);
            while (!inputObject->getKeyBuffer().empty()) {
                int firstKeyInBuffer = inputObject->getFirstKeyFromBuffer();
                ChangeGameMode(container, firstKeyInBuffer);
                inputObject->setDirection(firstKeyInBuffer);
            }
        }
    }

    void Game::ChangeGameMode(IoCContainer* container, int keyCode) {
        int localGameMode = getGameMode();
        if (keyCode == 6) {
            if (localGameMode == 1) {
                setGameMode(0);
            } else if (localGameMode == 2) {
                setGameMode(1);
                container->Get<InputController>(1)->SetCurrentLine(0);
            } else {
                setGameMode(1);
                container->Get<InputController>(1)->SetCurrentLine(0);
            }
            return;
        }
        if (keyCode == 5) {
            if (localGameMode == 1) {
                setGameMode(2);
            } else if (localGameMode == 2) {
                if (canBuild) {
                    CreateNewBuilding(GetTypeOnIndex(container->Get<InputController>(1)->GetCurrentLine()), container);
                    setGameMode(0);
                } else {
                    setGameMode(3);
                }

            } else if (localGameMode == 3) {
                setGameMode(0);
            }
            return;
        }
    }

    void Game::CreateResources(IoCContainer *container, int startValue) {
        container->New<Ore>();
        container->Get<Ore>(1)->IncreaseValue(50);
        container->New<Wood>();
        container->Get<Wood>(1)->IncreaseValue(50);
        container->New<Food>();
        container->Get<Food>(1)->IncreaseValue(50);
        container->New<People>();
        container->Get<People>(1)->IncreaseValue(50);
        container->New<Gold>();
        container->Get<Gold>(1)->IncreaseValue(50);
        container->New<Clay>();
        container->Get<Clay>(1)->IncreaseValue(50);
}

    void Game::CreateStartBuildings(IoCContainer *container, int value) {
        container->SetCoordinates<MainBuilding>(value, value);
        container->New<MainBuilding>();
        container->SetCoordinates<House>(value  + 3, value + 3);
        container->New<House>();
    }

    void Game::CreateTypeList(IoCContainer *container) {
        AddTypeToTypeList(typeid(House).hash_code(),
                                      House::Create(typeid(House).hash_code(), container, -1));
        AddTypeToTypeList(typeid(Mine).hash_code(),
                                      Mine::Create(typeid(Mine).hash_code(), container, -1));
        AddTypeToTypeList(typeid(ClayPit).hash_code(),
                                      ClayPit::Create(typeid(ClayPit).hash_code(), container, -1));
        AddTypeToTypeList(typeid(Sawmill).hash_code(),
                                      Sawmill::Create(typeid(Sawmill).hash_code(), container, -1));
        AddTypeToTypeList(typeid(Tower).hash_code(),
                                      Tower::Create(typeid(Tower).hash_code(), container, -1));
        AddTypeToTypeList(typeid(Farm).hash_code(),
                                      Farm::Create(typeid(Farm).hash_code(), container, -1));
    }

    void Game::gameLoop() {
        auto *renderObject = new GameRender();
        auto *scoreBoard = new ScoreBoard(1, 10, 13);
        auto *container = new IoCContainer();
        container->Register<LevelManager>(&LevelManager::Create);
        container->Register<InputController>(&InputController::Create);
        container->Register<Tower>(&Tower::Create);
        container->Register<Ore>(&Ore::Create);
        container->Register<Mine>(&Mine::Create);
        container->Register<Wood>(&Wood::Create);
        container->Register<Sawmill>(&Sawmill::Create);
        container->Register<Food>(&Food::Create);
        container->Register<Farm>(&Farm::Create);
        container->Register<MainBuilding>(&MainBuilding::Create);
        container->Register<People>(&People::Create);
        container->Register<House>(&House::Create);
        container->Register<Gold>(&Gold::Create);
        container->Register<Clay>(&Clay::Create);
        container->Register<ClayPit>(&ClayPit::Create);
        container->Register<Plane>(&Plane::Create);
        container->Register<Mountain>(&Mountain::Create);
        //
        container->New<LevelManager>();
        container->New<InputController>();
        //
        CreateResources(container, 50);
        //
        CreateStartBuildings(container, 2);
        //
        auto *inputObject = container->Get<InputController>(1);
        auto *gameCamera = new GameCamera(container);
        CreateTypeList(container);
        auto previous = std::chrono::system_clock::now();
        double MS_PER_UPDATE = 0.03;  // 30 тиков в секунду
        double lag = 0.0;
        while (getLooping()) {
            auto current =  std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed = current - previous;
            previous = current;
            lag += elapsed.count();
            while ((lag >= MS_PER_UPDATE)&&(getLooping())) {
                inputObject->symbolInput();
                lag -= MS_PER_UPDATE;
                update(inputObject, container, scoreBoard, MS_PER_UPDATE);
                if (getGameMode() != 1) {
                    gameCamera->changePosition(container, inputObject->getAxisY(), inputObject->getAxisX());
                }
                renderObject->clearScreen();
                renderObject->render(container, scoreBoard, getGameMode(), this);
                gameCamera->render(container);
                renderObject->refreshScreen();
            }
        }
        renderObject->endWindow();
    }

    void Game::AddTypeToTypeList(size_t type, IObject* exemplar) {
        if (typeList.find(type)->first != type) {
            typeList.insert(std::pair<size_t, IObject *>(type, exemplar));
        }
    }

    void Game::RemoveTypeFromTypeList(size_t type) {
        if (typeList.find(type)->first != type) {
            typeList.erase(type);
        }
    }

    IObject** Game::GetTypeList() {
        IObject** result = new IObject*[typeList.size()];
        int i = 0;
        for (auto it : typeList) {
            result[i] = it.second;
            i++;
        }
        return  result;
    }

    int Game::GetTypeListSize() {
        return typeList.size();
    }

    size_t Game::GetTypeOnIndex(int index) {
        int i = 0;
        for (auto it : typeList) {
            if (i == index) {
                return it.first;
            }
            i++;
        }
        return static_cast<size_t>(-1);
    }
    void Game::CreateNewBuilding(size_t type, IoCContainer* container) {
        if (type != static_cast<size_t >(-1)) {
            container->SetCoordinates(HardcodedBuildingY, HardcodedBuildingX, type);
            container->New(type);
            if (HardcodedBuildingX + 3 < container->Get<LevelManager>(1)->getSizeCol()) {
                HardcodedBuildingX += 3;
            } else {
                canBuild = false;
            }
        }
    }