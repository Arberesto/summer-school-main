#ifndef DMITRIJ_BAGAEV_MAIN_GAME_GAMECAMERA_H
#define DMITRIJ_BAGAEV_MAIN_GAME_GAMECAMERA_H
#include "./LevelManager.h"
class GameCamera {
 public:
    explicit GameCamera();
    void refreshCamera();
    void render(LevelManager *levelObject);
    int getRowSize();
    void setRowSize(int newRowSize);
    int getColSize();
    void setColSize(int newColSize);
    int getConsoleLeftUpperCornerRow();
    void setConsoleLeftUpperCornerRow(int newConsoleLeftUpperCornerRow);
    int getConsoleLeftUpperCornerCol();
    void setConsoleLeftUpperCornerCol(int newConsoleLeftUpperCornerCol);
    int getLeftUpperCornerRow();
    void setLeftUpperCornerRow(int newLeftUpperCornerRow);
    int getLeftUpperCornerCol();
    void setLeftUpperCornerCol(int newLeftUpperCornerCol);
    void changePosition(int rowShift, int colShift, int mapMaxRow, int mapMaxCol);
    bool isCorrectCoordinates(int cameraRow, int cameraCol, int levelSizeRow, int levelSizeCol);

 private:
    int rowSize;
    int colSize;
    int consoleLeftUpperCornerRow;
    int consoleLeftUpperCornerCol;
    int leftUpperCornerRow;
    int leftUpperCornerCol;
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_GAMECAMERA_H
