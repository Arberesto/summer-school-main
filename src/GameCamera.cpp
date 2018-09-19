#include "./GameCamera.h"
#include <ncurses.h>
#include <string>
#include <typeinfo>
#include <utility>
#include "./BuildingList.h"
#include "./UnitList.h"
#include "./TerrainList.h"
#include "./Cursor.h"
GameCamera::GameCamera(IoCContainer* container) {
    setColSize(50);
    setRowSize(25);
    setConsoleLeftUpperCornerCol(2);
    setConsoleLeftUpperCornerRow(20);
    setLeftUpperCornerCol(1);
    setLeftUpperCornerRow(1);
    changePosition(container, -1, -1);
    auto cursor = container->Get<Cursor>(1);
    Draw(container, cursor);
}

void GameCamera::changePosition(IoCContainer* container, int rowShift, int colShift) {
    if (rowShift + colShift != 0) {
//        auto objectTemp = container->Get<Cursor>(1);
//        auto localCursorRow = objectTemp->GetRow();
//        auto localCursorCol = objectTemp->GetCol();
//        auto localRowSize = getRowSize();
//        auto localColSize = getColSize();
//        if ( (std::abs(localCursorRow - localRowSize) < CAMERA_FOLLOW_CONSTANT) ||
//             (std::abs(localCursorCol -  localColSize) < CAMERA_FOLLOW_CONSTANT) ) {
            auto mapMaxRow = container->Get<LevelManager>(1)->getSizeRow();
            auto mapMaxCol = container->Get<LevelManager>(1)->getSizeCol();
            if (isCorrectCoordinates(getLeftUpperCornerRow() + rowShift, getLeftUpperCornerCol() + colShift,
                                     mapMaxRow + 1, mapMaxCol + 1)) {
                setLeftUpperCornerRow(getLeftUpperCornerRow() + rowShift);
                setLeftUpperCornerCol(getLeftUpperCornerCol() + colShift);
                ClearActiveField();
                UpdateTerrain(container);
                UpdateBuildings(container);
            }
//        }
    }
}

bool GameCamera::isCorrectCoordinates(int cameraRow, int cameraCol, int levelSizeRow, int levelSizeCol) {
    int localRowSize = getRowSize();
    int localColSize = getColSize();
    return ((cameraRow >= 0)&& (cameraCol >= 0) && (cameraRow + localRowSize <= levelSizeRow) &&
            (cameraCol +  localColSize <= levelSizeCol));
}

void GameCamera::render(IoCContainer* container) {
    for (auto it : activeField) {
        Draw(container, it.second);
    }
    auto cursor = container->Get<Cursor>(1);
    Draw(container, cursor);
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
    int CLUR = getConsoleLeftUpperCornerRow();
    int LUR = getLeftUpperCornerRow();
    int CLUC = getConsoleLeftUpperCornerCol();
    int LUC = getLeftUpperCornerCol();
    auto localDrawField = object->GetDrawField();
    for (int i = 0; i < localDrawField[0][0]; i++) {
        for (int j = 0; j < localDrawField[0][1]; j++) {
            mvaddch(CLUR - LUR + (localRow + i),
                    CLUC - LUC + (localCol + j),
                    localDrawField[i + 1][j]);
        }
    }
}

void GameCamera::Draw(IoCContainer* container, Cursor* object) {
    int localRow = object->GetRow();
    int localCol = object->GetCol();
    int CLUR = getConsoleLeftUpperCornerRow();
    int LUR = getLeftUpperCornerRow();
    int CLUC = getConsoleLeftUpperCornerCol();
    int LUC = getLeftUpperCornerCol();
    ChangeColorPair(1);
    //  very strange thing, sorry for that
    auto mainH = container->Get<House>(1);
    //
    if (isInCameraRadius(localRow, localCol, mainH->GenerateDrawField('C'))) {
        mvaddch(CLUR - LUR + localRow, CLUC - LUC + localCol, 'C');
    }
    //  auto localDrawField = object->GetDrawField();
//    for (int i = 0; i < localDrawField[0][0]; i++) {
//        for (int j = 0; j < localDrawField[0][1]; j++) {
//            mvaddch(CLUR - LUR + (localRow + i),
//                    CLUC - LUC + (localCol + j),
//                    localDrawField[i + 1][j]);
//        }
//    }
    ChangeColorPair(2);
}

void GameCamera::Draw(IoCContainer* container, Unit * object) {
}

void GameCamera::Draw(IoCContainer* container, IObject* object) {
    if (object->IsA(typeid(Building).hash_code())) {
        Draw(container, static_cast<Building*>(object));
    } else if (object->IsA(typeid(Terrain).hash_code())) {
        Draw(container, static_cast<Terrain*>(object));
    } else if (object->IsA(typeid(Unit).hash_code())) {
        //  Draw(container, static_cast<Unit*>(object));
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
    int localRowSize = drawField[0][0];
    int localColSize = drawField[0][1];
    int LUR = getLeftUpperCornerRow();
    int LUC = getLeftUpperCornerCol();
    int cameraRowSize = getRowSize();
    int cameraColSize = getColSize();
    return ((row >= LUR)&&(row + localRowSize <= LUR + cameraRowSize) &&
            (col >= LUC)&&(col + localColSize <= LUC + cameraColSize));
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
}

void GameCamera::UpdateBuildings(IoCContainer* container) {
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
}

void GameCamera::ClearActiveField() {
    activeField.clear();
}

void GameCamera::ChangeColorPair(int newPairNumber) {
    wattron(stdscr, COLOR_PAIR(newPairNumber));
}