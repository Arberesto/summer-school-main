#ifndef DMITRIJ_BAGAEV_MAIN_GAME_GAMECAMERA_H
#define DMITRIJ_BAGAEV_MAIN_GAME_GAMECAMERA_H
#include <map>
#include "./LevelManager.h"
#include "./BuildingList.h"
#include "./UnitList.h"
#include "./TerrainList.h"
class GameCamera {
 public:
    explicit GameCamera(IoCContainer* container);
    void refreshCamera();
    void render(IoCContainer* container);
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
    void changePosition(IoCContainer* container, int rowShift, int colShift);
    bool isCorrectCoordinates(int cameraRow, int cameraCol, int levelSizeRow, int levelSizeCol);
    void Draw(IoCContainer* container, Building * object);
    void Draw(IoCContainer* container, Unit * object);
    void Draw(IoCContainer* container, Terrain * object);
    void Draw(IoCContainer* container, IObject* object, size_t type);
    bool isInCameraRadius(int row, int col, char** drawField);
    void addToActiveField(size_t id, IObject* object);
    void UpdateTerrain(IoCContainer* container);
    void UpdateBuildings(IoCContainer* container);

 private:
    int rowSize;
    int colSize;
    int consoleLeftUpperCornerRow;
    int consoleLeftUpperCornerCol;
    int leftUpperCornerRow;
    int leftUpperCornerCol;
    std::map<size_t, IObject*> activeField;  // id and IObject
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_GAMECAMERA_H
