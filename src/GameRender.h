#ifndef ROUGE_DEMO_GAMERENDER_H
#define ROUGE_DEMO_GAMERENDER_H
#include "./LevelManager.h"
#include "./ScoreBoard.h"
class GameRender {
 public:
    explicit GameRender();
    void redrawConsole(LevelManager *levelManager, int rowConsole, int colConsole);
    void redrawMap(int rowSize, int colSize, char** Map);
    void render(IoCContainer *container, ScoreBoard *scoreBoard, int mode);
    void drawScoreBoard(ScoreBoard *scoreBoard);
    void drawLosePicture(LevelManager *levelObject);
    void drawWinPicture(LevelManager *levelObject);
    void initWindow();
    void endWindow();
    void clearScreen();
    void refreshScreen();

 private:
    const int CONSOLEROW = 20;
    const int CONSOLECOL = 10;
};
#endif  //  ROUGE_DEMO_GAMERENDER_H
