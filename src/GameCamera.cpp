#include "./GameCamera.h"
#include <ncurses.h>
#include <string>
#include "./BuildingList.h"
#include "./UnitList.h"
#include "./TerrainList.h"
GameCamera::GameCamera() {
    setColSize(50);
    setRowSize(25);
    setConsoleLeftUpperCornerCol(2);
    setConsoleLeftUpperCornerRow(20);
    setLeftUpperCornerCol(0);
    setLeftUpperCornerRow(0);
}

void GameCamera::changePosition(int rowShift, int colShift, int mapMaxRow, int mapMaxCol) {
    if ((isCorrectCoordinates(getLeftUpperCornerRow() + rowShift,
                             getLeftUpperCornerCol() + colShift , mapMaxRow + 1, mapMaxCol + 1))
        &&(isCorrectCoordinates(getLeftUpperCornerRow() + getRowSize() + rowShift,
                                getLeftUpperCornerCol() + getColSize() + colShift , mapMaxRow + 1, mapMaxCol + 1))) {
        setLeftUpperCornerRow(getLeftUpperCornerRow() + rowShift);
        setLeftUpperCornerCol(getLeftUpperCornerCol() + colShift);
    }
}

bool GameCamera::isCorrectCoordinates(int cameraRow, int cameraCol, int levelSizeRow, int levelSizeCol) {
    return (cameraRow < levelSizeRow)
           && (cameraCol < levelSizeCol) && (cameraRow >= 0)&& (cameraCol >= 0);
}

void GameCamera::render(IoCContainer* container) {
    auto terrainList = container->GetIdList<Terrain>();
    if (terrainList[0][0] != 0) {
        for (int i = 0; i < static_cast<int>(terrainList[0][0]); i++) {
            if (terrainList[i][1] != 0) {
                size_t typeTemp = terrainList[i][2];
                for (int j = 0; j < static_cast<int>(terrainList[i][1]); j++) {
                    auto idTemp = static_cast<int>(terrainList[i][3 + j]);
                    auto objectTemp = static_cast<Terrain *>(container->Get(idTemp, typeTemp));
                    Draw(container, objectTemp);
                }
            }
        }
    }
    auto buildingList = container->GetIdList<Building>();
    if (buildingList[0][0] != 0) {
        for (int i = 0; i < static_cast<int>(buildingList[0][0]); i++) {
            if (buildingList[i][1] != 0) {
                size_t typeTemp = buildingList[i][2];
                for (int j = 0; j < static_cast<int>(buildingList[i][1]); j++) {
                    auto idTemp = static_cast<int>(buildingList[i][3 + j]);
                    auto objectTemp = static_cast<Building *>(container->Get(idTemp, typeTemp));
                    Draw(container, objectTemp);
                }
            }
        }
    }
//    auto unitList = container->GetIdList<Unit>();
//    if (unitList[0][0] != 0) {
//        for (int i = 0; i < static_cast<int>(unitList[0][0]); i++) {
//            if (unitList[i][1] != 0) {
//                size_t typeTemp = unitList[i][2];
//                for (int j = 0; j < static_cast<int>(unitList[i][1]); j++) {
//                    auto idTemp = static_cast<int>(unitList[i][3 + j]);
//                    auto objectTemp = static_cast<Unit *>(container->Get(idTemp, typeTemp));
//                    Draw(container, objectTemp);
//                }
//            }
//        }
//    }
}

void GameCamera::Draw(IoCContainer* container, Building* object) {
    int LUR = getLeftUpperCornerRow();
    int LUC = getLeftUpperCornerCol();
    int CLUR = getConsoleLeftUpperCornerRow();
    int CLUC = getConsoleLeftUpperCornerCol();
    int localRow = object->GetRow();
    int localCol = object->GetCol();
    auto localDrawField = object->GetDrawField();
    for (int i = 0; i < localDrawField[0][0]; i++) {
        for (int j = 0; j < localDrawField[0][1]; j++) {
            if (isInCameraRadius(container, i + localRow, j + localCol)) {
                mvaddch(CLUR - LUR + (localRow + i), CLUC - LUC + (localCol + j), localDrawField[i + 1][j]);
            } else {
                mvaddch(CLUR - LUR + (localRow + i), CLUC - LUC + (localCol + j), ' ');
            }
        }
    }
}

void GameCamera::Draw(IoCContainer* container, Unit * object) {
}

void GameCamera::Draw(IoCContainer* container, Terrain * object) {
    int LUR = getLeftUpperCornerRow();
    int LUC = getLeftUpperCornerCol();
    int CLUR = getConsoleLeftUpperCornerRow();
    int CLUC = getConsoleLeftUpperCornerCol();
    int localRow = object->GetRow();
    int localCol = object->GetCol();
    auto localDrawField = object->GetDrawField();
    for (int i = 0; i < localDrawField[0][0]; i++) {
        for (int j = 0; j < localDrawField[0][1]; j++) {
            if (isInCameraRadius(container, i + localRow, j + localCol)) {
                mvaddch(CLUR - LUR + (localRow + i), CLUC - LUC + (localCol + j), localDrawField[i + 1][j]);
            } else {
                mvaddch(CLUR - LUR + (localRow + i), CLUC - LUC + (localCol + j), ' ');
            }
        }
    }
}

bool GameCamera::isInCameraRadius(IoCContainer* container, int coordinateY, int coordinateX) {
    int LUR = getLeftUpperCornerRow();
    int LUC = getLeftUpperCornerCol();
    int RS = getRowSize();
    int CS = getColSize();
    return !((coordinateY < LUR) || (coordinateY > LUR + RS) || (coordinateX < LUC) || (coordinateX > LUC + CS));
}

void GameCamera::refreshCamera() {
}

int GameCamera::getRowSize() {
    return rowSize;
}

void GameCamera::setRowSize(int newRowSize) {
    rowSize = newRowSize;
}

int GameCamera::getColSize() {
    return  colSize;
}

void GameCamera::setColSize(int newColSize) {
    colSize = newColSize;
}

int GameCamera::getConsoleLeftUpperCornerRow() {
    return  consoleLeftUpperCornerRow;
}

void GameCamera::setConsoleLeftUpperCornerRow(int newRightBottomCornerRow) {
    consoleLeftUpperCornerRow = newRightBottomCornerRow;
}

int GameCamera::getConsoleLeftUpperCornerCol() {
    return  consoleLeftUpperCornerCol;
}

void GameCamera::setConsoleLeftUpperCornerCol(int newRightBottomCornerCol) {
    consoleLeftUpperCornerCol = newRightBottomCornerCol;
}

int GameCamera::getLeftUpperCornerRow() {
    return  leftUpperCornerRow;
}

void GameCamera::setLeftUpperCornerRow(int newLeftUpperCornerRow) {
    leftUpperCornerRow = newLeftUpperCornerRow;
}

int GameCamera::getLeftUpperCornerCol() {
    return leftUpperCornerCol;
}

void GameCamera::setLeftUpperCornerCol(int newLeftUpperCornerCol) {
    leftUpperCornerCol = newLeftUpperCornerCol;
}