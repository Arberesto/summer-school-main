#include "./GameCamera.h"
#include <ncurses.h>
#include <string>
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

void GameCamera::render(LevelManager *levelObject) {
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