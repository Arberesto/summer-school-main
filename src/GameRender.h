#ifndef ROUGE_DEMO_GAMERENDER_H
#define ROUGE_DEMO_GAMERENDER_H
#include <map>
#include "./LevelManager.h"
#include "./ScoreBoard.h"
class GameRender {
 public:
    explicit GameRender();
    void redrawConsole(IoCContainer *container);
    void render(IoCContainer *container, ScoreBoard *scoreBoard, int mode);
    void drawScoreBoard(ScoreBoard *scoreBoard);
    void drawLosePicture(LevelManager *levelObject);
    void drawWinPicture(LevelManager *levelObject);
    void initWindow();
    void endWindow();
    void clearScreen();
    void refreshScreen();
    void RedrawBuildingTypes(IoCContainer *container);
    void AddTypeToTypeList(size_t type, IObject* exemplar);
    void RemoveTypeFromTypeList(size_t type);
 private:
    const int CONSOLEROW = 20;
    const int CONSOLECOL = 54;
    std::map<size_t, IObject*> typeList;
};
#endif  //  ROUGE_DEMO_GAMERENDER_H
