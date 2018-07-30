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

    void Game::gameEnd(LevelManager *levelManager, ScoreBoard *scoreBoard, bool WinNotLose) {  // Game
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

    void Game::changeMap(InputController *inputObject, LevelManager *levelManager,
                   ScoreBoard *scoreBoard) {
        int row = inputObject->getAxisY();
        int col = inputObject->getAxisX();
        if ((levelManager->getMapSymbol(levelManager->getPlayerRow() + row,
                                        levelManager->getPlayerCol() + col) == '.' )
            ||(levelManager->getMapSymbol(levelManager->getPlayerRow() + row,
                                          levelManager->getPlayerCol() + col) == '$')) {
            // levelManager->setStepsUsed(levelManager->getStepsUsed() + 1);
            // наступили на монетку или на пустое пространство
            if (levelManager->getMapSymbol(levelManager->getPlayerRow() + row,
                                           levelManager->getPlayerCol() + col) == '$') {
                levelManager->setCoinCount(levelManager->getCoinCount() + 1);
            }
            levelManager->setMapSymbol(levelManager->getPlayerRow(),
                                       levelManager->getPlayerCol(), '.');
            levelManager->setPlayerRow(levelManager->getPlayerRow()+row);
            levelManager->setPlayerCol(levelManager->getPlayerCol()+col);
            levelManager->setMapSymbol(levelManager->getPlayerRow(),
                                       levelManager->getPlayerCol(), levelManager->getPlayer()->getSymbol());
        } else if (levelManager->getMapSymbol(levelManager->getPlayerRow() + row,
                                              levelManager->getPlayerCol() + col)  == '>') {
            scoreBoard->addPlayer(inputObject->getPlayerName(getRowConsole(), getColConsole(), 10),
                                  static_cast<int>(levelManager->getSecondsUsed()));
            setGameMode(1);
            bool isNextLevelExist = levelManager->nextLevel();
            inputObject->setDirection(4);
            if (!isNextLevelExist) {
                gameEnd(levelManager,  scoreBoard, true);
            }
        } else if (levelManager->getMapSymbol(levelManager->getPlayerRow() + row,
                                              levelManager->getPlayerCol() + col)  == '<') {
            // secretLevel();
        }
    }

    void Game::update(InputController *inputObject, LevelManager *levelObject,
                      ScoreBoard *scoreBoard, double deltaTime) {
        if (getGameMode() == 0) {
            levelObject->setSecondsUsed(levelObject->getSecondsUsed() + deltaTime);
            levelObject->setTickCounter(levelObject->getTickCounter() + 1);
        }
        if (levelObject->getSecondsUsed() - levelObject->getCoinCount() *
                                            levelObject->getCoinValue()
            >= levelObject->getLevelSecondsLimit()) {
            levelObject->loadLevel(1);
            inputObject->setDirection(4);
            gameEnd(levelObject, scoreBoard, false);
            return;
        }
        if (inputObject->isInBuffer(113)) {  // выход из игры
            setLooping(false);
        } else {
            while (!inputObject->getKeyBuffer().empty()) {
                int firstKeyInBuffer = inputObject->getFirstKeyFromBuffer();
                if ((firstKeyInBuffer == 10) && (gameMode != 0)) {
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
            levelObject->DeclarePlayerMovement();
            if (levelObject->getPlayer()->getIsMoving()) {
                changeMap(inputObject, levelObject, scoreBoard);
            }
        }
    }

    void Game::gameLoop() {
        auto *renderObject = new GameRender();
        auto *inputObject = new InputController();
        auto *levelObject = new LevelManager(1);
        auto *scoreBoard = new ScoreBoard(1, 10, 13);
        auto previous = std::chrono::system_clock::now();
        double MS_PER_UPDATE = 0.03;  // 30 тиков в секунду
        double lag = 0.0;
        while (getLooping()) {
            auto current =  std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed = current - previous;
            previous = current;
            lag += elapsed.count();
            while (lag >= MS_PER_UPDATE) {
                inputObject->symbolInput();
                update(inputObject, levelObject, scoreBoard, MS_PER_UPDATE);
                lag -= MS_PER_UPDATE;
                renderObject->render(levelObject, scoreBoard, getGameMode());
            }
        }
        renderObject->endWindow();
    }
