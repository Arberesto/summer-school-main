#include "./GameCamera.h"
#include <ncurses.h>
#include <string>
#include <typeinfo>
#include <utility>
#include "./BuildingList.h"
#include "./UnitList.h"
#include "./TerrainList.h"
GameCamera::GameCamera(IoCContainer* container) {
    setColSize(50);
    setRowSize(25);
    setConsoleLeftUpperCornerCol(2);
    setConsoleLeftUpperCornerRow(20);
    setLeftUpperCornerCol(1);
    setLeftUpperCornerRow(1);
    changePosition(container, -1, -1);
}

void GameCamera::changePosition(IoCContainer* container, int rowShift, int colShift) {
    if (rowShift + colShift != 0) {
        auto levelObject = container->Get<LevelManager>(1);
        auto mapMaxRow = levelObject->getSizeRow();
        auto mapMaxCol = levelObject->getSizeCol();
        if (isCorrectCoordinates(getLeftUpperCornerRow() + rowShift, getLeftUpperCornerCol() + colShift,
                                 mapMaxRow + 1, mapMaxCol + 1)) {
            setLeftUpperCornerRow(getLeftUpperCornerRow() + rowShift);
            setLeftUpperCornerCol(getLeftUpperCornerCol() + colShift);
            //
            auto terrainList = container->GetIdList<Terrain>();
            for (int i = 0; i < static_cast<int>(terrainList[0][0]); i++) {
                if (terrainList[i][1] != 0) {
                    size_t typeTemp = terrainList[i][2];
                    for (int j = 0; j < static_cast<int>(terrainList[i][1]); j++) {
                        auto idTemp = static_cast<int>(terrainList[i][3 + j]);
                        auto objectTemp = static_cast<Terrain *>(container->Get(idTemp, typeTemp));
                        if (isInCameraRadius(objectTemp->GetRow(), objectTemp->GetCol(), objectTemp->GetDrawField())) {
                            addToActiveField(objectTemp->GetType() + objectTemp->GetId(), objectTemp);
                        }
                    }
                }
            }
            auto buildingList = container->GetIdList<Building>();
            for (int i = 0; i < static_cast<int>(buildingList[0][0]); i++) {
                if (buildingList[i][1] != 0) {
                    size_t typeTemp = buildingList[i][2];
                    for (int j = 0; j < static_cast<int>(buildingList[i][1]); j++) {
                        auto idTemp = static_cast<int>(buildingList[i][3 + j]);
                        auto objectTemp = static_cast<Building *>(container->Get(idTemp, typeTemp));
                        if (isInCameraRadius(objectTemp->GetRow(), objectTemp->GetCol(), objectTemp->GetDrawField())) {
                            addToActiveField(objectTemp->GetType() + objectTemp->GetId(), objectTemp);
                        }
                    }
                }
            }
            //
        }
    }
}

bool GameCamera::isCorrectCoordinates(int cameraRow, int cameraCol, int levelSizeRow, int levelSizeCol) {
    int localRowSize = getRowSize();
    int localColSize = getColSize();
    return (cameraRow < levelSizeRow)
           && (cameraCol < levelSizeCol) && (cameraRow >= 0)&& (cameraCol >= 0) &&
           (cameraRow + localRowSize < levelSizeRow) && (cameraCol +  localColSize < levelSizeCol)
           && (cameraRow + localRowSize >= 0) && (cameraCol +  localColSize >= 0);
}

void GameCamera::render(IoCContainer* container) {
    for (auto it : activeField) {
        Draw(container, it.second, it.second->GetType());
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
    int localRow = object->GetRow();
    int localCol = object->GetCol();
    auto localDrawField = object->GetDrawField();
    for (int i = 0; i < localDrawField[0][0]; i++) {
        for (int j = 0; j < localDrawField[0][1]; j++) {
            mvaddch(getConsoleLeftUpperCornerRow() - getLeftUpperCornerRow() + (localRow + i),
                    getConsoleLeftUpperCornerCol() - getLeftUpperCornerCol() + (localCol + j),
                    localDrawField[i + 1][j]);
        }
    }
}

void GameCamera::Draw(IoCContainer* container, Unit * object) {
}

void GameCamera::Draw(IoCContainer* container, IObject* object, size_t type) {
    if (type == typeid(Building).hash_code()) {
        Draw(container, static_cast<Building*>(object));
    } else if (type == typeid(Terrain).hash_code()) {
        Draw(container, static_cast<Terrain*>(object));
    }
}

void GameCamera::Draw(IoCContainer* container, Terrain * object) {
    int localRow = object->GetRow();
    int localCol = object->GetCol();
    int CLUR = getConsoleLeftUpperCornerRow();
    int LUR = getLeftUpperCornerRow();
    int CLUC = getConsoleLeftUpperCornerCol();
    int LUC = getLeftUpperCornerCol();
    auto localDrawField = object->GetDrawField();
    for (int i = 0; i < localDrawField[0][0]; i++) {
        for (int j = 0; j < localDrawField[0][1]; j++) {
            mvaddch(CLUR - LUR + (localRow + i), CLUC - LUC + (localCol + j), localDrawField[i + 1][j]);
        }
    }
}

bool GameCamera::isInCameraRadius(int row, int col, char** drawField) {
    int rowSize = drawField[0][0];
    int colSize = drawField[0][1];
    int LUR = getLeftUpperCornerRow();
    int LUC = getLeftUpperCornerCol();
    int cameraRowSize = getRowSize();
    int cameraColSize = getColSize();
    return ((row <= LUR)&&(row + rowSize >= LUR + cameraRowSize)&&(col >= LUC)&&(col + colSize <= LUC + cameraColSize));
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

void GameCamera::addToActiveField(size_t id, IObject* object) {
    activeField.insert(std::pair<size_t, IObject*>(id, object));
}

void GameCamera::UpdateTerrain(IoCContainer* container) {
}

void GameCamera::UpdateBuildings(IoCContainer* container) {
}