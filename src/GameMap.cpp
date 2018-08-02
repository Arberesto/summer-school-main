#include "./GameMap.h"
#include <ncurses.h>
#include <string>
GameMap::GameMap() {
    setColSize(50);
    setRowSize(25);
    setConsoleLeftUpperCornerCol(2);
    setConsoleLeftUpperCornerRow(20);
    setLeftUpperCornerCol(0);
    setLeftUpperCornerRow(0);
}

void GameMap::changePosition(int rowShift, int colShift, int mapMaxRow, int mapMaxCol) {
    if ((isCorrectCoordinates(getLeftUpperCornerRow() + rowShift,
                             getLeftUpperCornerCol() + colShift , mapMaxRow + 1, mapMaxCol + 1))
        &&(isCorrectCoordinates(getLeftUpperCornerRow() + getRowSize() + rowShift,
                                getLeftUpperCornerCol() + getColSize() + colShift , mapMaxRow + 1, mapMaxCol + 1))) {
        setLeftUpperCornerRow(getLeftUpperCornerRow() + rowShift);
        setLeftUpperCornerCol(getLeftUpperCornerCol() + colShift);
    }
}

bool GameMap::isCorrectCoordinates(int cameraRow, int cameraCol, int levelSizeRow, int levelSizeCol) {
    return (cameraRow < levelSizeRow)
           && (cameraCol < levelSizeCol) && (cameraRow >= 0)&& (cameraCol >= 0);
}

void GameMap::render(LevelManager *levelObject) {
    int LUR = getLeftUpperCornerRow();
    int LUC = getLeftUpperCornerCol();
    int CLUR = getConsoleLeftUpperCornerRow();
    int CLUC = getConsoleLeftUpperCornerCol();
    int levelSizeRow = levelObject->getSizeRow();
    int levelSizeCol = levelObject->getSizeCol();
    for (int i = 0; i < getRowSize(); i++) {
        for (int j = 0; j < getColSize(); j++) {
            if (isCorrectCoordinates(i + LUR, j + LUC, levelSizeRow, levelSizeCol)) {
                mvaddch(CLUR + i, CLUC + j,
                        levelObject->getMapSymbol(i + LUR, j + LUC));
            } else {
                mvaddch(CLUR + i, CLUC + j, ' ');
            }
        }
    }
    // refresh();
}

void GameMap::refreshMap() {
}

int GameMap::getRowSize() {
    return rowSize;
}

void GameMap::setRowSize(int newRowSize) {
    rowSize = newRowSize;
}

int GameMap::getColSize() {
    return  colSize;
}

void GameMap::setColSize(int newColSize) {
    colSize = newColSize;
}

int GameMap::getConsoleLeftUpperCornerRow() {
    return  consoleLeftUpperCornerRow;
}

void GameMap::setConsoleLeftUpperCornerRow(int newRightBottomCornerRow) {
    consoleLeftUpperCornerRow = newRightBottomCornerRow;
}

int GameMap::getConsoleLeftUpperCornerCol() {
    return  consoleLeftUpperCornerCol;
}

void GameMap::setConsoleLeftUpperCornerCol(int newRightBottomCornerCol) {
    consoleLeftUpperCornerCol = newRightBottomCornerCol;
}

int GameMap::getLeftUpperCornerRow() {
    return  leftUpperCornerRow;
}

void GameMap::setLeftUpperCornerRow(int newLeftUpperCornerRow) {
    leftUpperCornerRow = newLeftUpperCornerRow;
}

int GameMap::getLeftUpperCornerCol() {
    return leftUpperCornerCol;
}

void GameMap::setLeftUpperCornerCol(int newLeftUpperCornerCol) {
    leftUpperCornerCol = newLeftUpperCornerCol;
}