#ifndef ROUGE_DEMO_GAMERENDER_H
#define ROUGE_DEMO_GAMERENDER_H
#include <map>
#include "./LevelManager.h"
#include "./ScoreBoard.h"
#include "./Game.h"

class GameRender {
 public:
    explicit GameRender();
    void redrawConsole(IoCContainer *container);
    void render(IoCContainer *container, ScoreBoard *scoreBoard, int mode, Game* gameObject);
    void drawScoreBoard(ScoreBoard *scoreBoard);
    void drawLosePicture(LevelManager *levelObject);
    void drawWinPicture(LevelManager *levelObject);
    void initWindow();
    void endWindow();
    void clearScreen();
    void refreshScreen();
    void ChangeColorPair(int newPairNumber);
    void RedrawBuildingTypes(IoCContainer *container, Game* gameObject);

 private:
    const int CONSOLEROW = 20;
    const int CONSOLECOL = 54;
};
#endif  //  ROUGE_DEMO_GAMERENDER_H
