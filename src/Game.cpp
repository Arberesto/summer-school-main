#include "./Game.h"
#include <ncurses.h>
#include <cstdio>
#include <string>
#include <chrono>
#include "./Utility.h"
#include "./GameRender.h"
#include "./InputController.h"
#include "./LevelManager.h"
#include "./ScoreBoard.h"
#include "./GameCamera.h"
#include "./IncludeObjects.h"
Game::Game(int gameMode) {
    setGameMode(gameMode);
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
        if (container->Get<LevelManager>(1)->getLastSecond() % 10 == 0) {
            auto resourceIdList = container->GetIdList<Resource>();
            for (int i = 0; i < static_cast<int>(resourceIdList[0][0]); i++) {
                size_t typeTemp = resourceIdList[i][2];
                for (int j = 0; j < static_cast<int>(resourceIdList[i][1]); j++) {
                    int idTemp = static_cast<int>(resourceIdList[i][3 + j]);
                    auto objectTemp = static_cast<Resource *>(container->Get(idTemp, typeTemp));
                    objectTemp->SetValue(objectTemp->GetValue() + getProduced(container, typeTemp));
                }
            }
        }
        container->Get<LevelManager>(1)->SetIsNewSecondNow(false);
    }

    int Game::getProduced(IoCContainer *container, size_t type) {
        int result = 0;
        auto buildingList = container->GetIdList<ProducingBuilding>();
        for (int i = 0; i < static_cast<int>(buildingList[0][0]); i++) {
            size_t typeTemp = buildingList[i][2];
            for (int j = 0; j < static_cast<int>(buildingList[i][1]); j++) {
                int idTemp = static_cast<int>(buildingList[i][3 + j]);
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
            levelObject->setSecondsUsed(levelObject->getSecondsUsed() + deltaTime);
            levelObject->setTickCounter(levelObject->getTickCounter() + 1);
        }
        if (container->Get<LevelManager>(1)->GetIsNewSecondNow()) {
            eachSecondUpdate(container);
        }
//        if (levelObject->getSecondsUsed() - levelObject->getCoinCount() *
//                                            levelObject->getCoinValue()
//            >= levelObject->getLevelSecondsLimit()) {
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
                if ((firstKeyInBuffer == 6) && (gameMode != 0)) {
                    if (gameMode == 1) {
                        setGameMode(0);
                        scoreBoard->setScoreBoard(levelObject->getLevelNumber(), 10, 13);
                    } else {
                        setGameMode(1);
                        levelObject->setPrevSeconds(0);
                    }
                }
                inputObject->setDirection(firstKeyInBuffer);
            }
        }
    }

    void Game::gameLoop() {
        auto *renderObject = new GameRender();
        auto *inputObject = new InputController();
        auto *scoreBoard = new ScoreBoard(1, 10, 13);
        auto *container = new IoCContainer();
        auto gameCamera = new GameCamera();
        container->Register<House>(&House::Create);
        container->Register<LevelManager>(&LevelManager::Create);
        container->Register<MainBuilding>(&MainBuilding::Create);
        container->Register<Tower>(&Tower::Create);
        container->Register<Ore>(&Ore::Create);
        container->Register<Wood>(&Wood::Create);
        container->Register<Food>(&Food::Create);
        container->Register<People>(&People::Create);
        container->Register<Gold>(&Gold::Create);
        container->Register<Clay>(&Clay::Create);
        container->Register<Plane>(&Plane::Create);
        container->SetCoordinates<MainBuilding>(4, 4);
        container->SetCoordinates<House>(5, 8);
        container->SetCoordinates<Tower>(6, 6);
        container->New<Ore>();
        container->New<Wood>();
        container->New<Food>();
        container->New<People>();
        container->New<Gold>();
        container->New<Clay>();
        container->New<House>();
        container->New<MainBuilding>();
        container->New<Tower>();
        container->New<LevelManager>();
        auto previous = std::chrono::system_clock::now();
        double MS_PER_UPDATE = 0.03;  // 30 тиков в секунду
        double lag = 0.0;
//        auto tempText = container->Get<House>(1)->GetTextField();
//        container->Get<LevelManager>(1)->setMapSymbol(container->Get<House>(1)->GetRow(),
//                                                      container->Get<House>(1)->GetCol(),
//                                                      tempText[0]);
//        container->Get<LevelManager>(1)->setMapSymbol(container->Get<MainBuilding>(1)->GetRow(),
//                                                      container->Get<MainBuilding>(1)->GetCol(),
//                                                      container->Get<MainBuilding>(1)->GetTextField()[0]);
        while (getLooping()) {
            auto current =  std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed = current - previous;
            previous = current;
            lag += elapsed.count();
            while (lag >= MS_PER_UPDATE) {
                inputObject->symbolInput();
                update(inputObject, container, scoreBoard, MS_PER_UPDATE);
                lag -= MS_PER_UPDATE;
                renderObject->clearScreen();
                renderObject->render(container, scoreBoard, getGameMode());
                gameCamera->changePosition(inputObject->getAxisY(), inputObject->getAxisX(),
                                           container->Get<LevelManager>(1)->getSizeRow(),
                                           container->Get<LevelManager>(1)->getSizeCol());
                gameCamera->render(container);
                renderObject->refreshScreen();
            }
        }
        renderObject->endWindow();
    }
