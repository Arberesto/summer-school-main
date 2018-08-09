#include "./GameRender.h"
#include <ncurses.h>
#include <string>
#include <cmath>
#include "./Utility.h"
#include "./ObjectRender.h"
#include "./ResourceList.h"
    GameRender::GameRender() {
        initWindow();
    }

    void GameRender::clearScreen() {
        clear();
    }

    void GameRender::redrawConsole(IoCContainer *container) {  // Render
        // auto resourceTitleList = container->GetTextFieldList<Resource>();
        auto resourceIdList = container->GetIdList<Resource>();
        for (int i = 0; i < static_cast<int>(resourceIdList[0][0]); i++) {
            int idTemp = static_cast<int>(resourceIdList[i][3]);
            size_t typeTemp = resourceIdList[i][2];
            auto objectTemp = static_cast<Resource*>(container->Get(idTemp, typeTemp));
            auto temp = objectTemp->GetTextField();
            auto intTemp = objectTemp->GetValue();
            mvwprintw(stdscr, CONSOLEROW - 2 + i * 2,
                      CONSOLECOL, "|%s : ", temp);
            mvwprintw(stdscr, CONSOLEROW - 2 + i * 2,
                      CONSOLECOL + 10, "%i |", intTemp);
        }
    }

    void GameRender::redrawMap(int rowSize, int colSize, char **Map) {  // Render
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                mvaddch(i, j, Map[i][j]);
            }
        }
    }

    void GameRender::drawScoreBoard(ScoreBoard *scoreBoard) {
        mvwprintw(stdscr, 20 - 2, 10 + 2, "Level %i%", scoreBoard->getLevelNumber());
        for (int i = 0; i < scoreBoard->getScoreRow(); i++) {
            for (int j = 0; j < 10; j++) {
                mvaddch(20 + i * 2, 10 + 2 + j, scoreBoard->getScoreBoardSymbol(i, j));
            }
            mvaddch(20 + i * 2, 10 + 14, '|');
            for (int j = 0; j < 3; j++) {
                mvaddch(CONSOLEROW + i * 2, CONSOLECOL + 15 + j, scoreBoard->getScoreBoardSymbol(i, 10 + j));
            }
        }
        mvwprintw(stdscr, 20 - 6, 10,
                  "Press Enter to load next map(or finish)");
    }

    void GameRender::render(IoCContainer *container, ScoreBoard *scoreBoard, int mode) {
        // mode: 0 map/console ,1 - scoreBoard,  3 - losePicture, 4 - winPicture
        // auto levelObject = container->Get<LevelManager>(1);
        switch (mode) {
            case 0: {
                redrawConsole(container);
//                redrawMap(levelObject->getSizeRow(),
//                          levelObject->getSizeCol(),
//                          levelObject->getMap());
                break;
            }
            case 1: {
                //  drawScoreBoard(scoreBoard);
                break;
            }
            case 3: {
                //  drawLosePicture(levelObject);
                break;
            }
            case 4: {
                //  drawWinPicture(levelObject);
                break;
            }
            default:
                break;
        }
    }

    void GameRender::drawLosePicture(LevelManager *levelObject) {
        mvwprintw(stdscr, 20, 10,
                  "You've been dyed... in black color. Maybe you've been too greedy.");
        mvwprintw(stdscr, 20 + 2, 10, "Press Enter to continue");
    }

    void GameRender::drawWinPicture(LevelManager *levelObject) {
        mvwprintw(stdscr, 20, 10, "You use ");
        mvwprintw(stdscr, 20, 10 + 8,
                  "%i%", levelObject->getPrevSeconds() + levelObject->getSecondsUsed());
        mvwprintw(stdscr, 20, 10 + 11, " steps to complete the game!");
        mvwprintw(stdscr, 20 + 2, 10, "Press Enter to continue");
    }

    void GameRender::initWindow() {
        initscr();
        raw();
        clear();
        noecho();
        cbreak();
        keypad(stdscr, TRUE);
        curs_set(0);
        nodelay(stdscr, true);
    }

    void GameRender::endWindow() {
        endwin();
    }

    void GameRender::refreshScreen() {
    refresh();
    }