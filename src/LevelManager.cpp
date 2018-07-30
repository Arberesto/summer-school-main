#include <string>
#include "./LevelManager.h"
#include "./Utility.h"
#include "./FileManager.h"
#include "./Player.h"
LevelManager::LevelManager(int levelNumber) {
    loadLevel(levelNumber);
}

bool LevelManager::nextLevel() {
    setPrevSeconds(getPrevSeconds() + getSecondsUsed());
    if (getLevelNumber() < 1) {
        loadLevel(getLevelNumber() + 1);
        return true;
    } else {
        loadLevel(1);
        return false;
    }
}

double LevelManager::getPrevSeconds() {
    return level.prevSeconds;
}

void LevelManager::setPrevSeconds(double newPrevSeconds) {
    level.prevSeconds = newPrevSeconds;
}

char ** LevelManager::getMap() {
    return level.Map;
}

void LevelManager::setSecondsUsed(double newSecondsUsed) {
    level.secondsUsed = newSecondsUsed;
}

double LevelManager::getSecondsUsed() {
    return level.secondsUsed;
}

void LevelManager::setCoinCount(int newCoinCount) {
    level.coinCount = newCoinCount;
}

int LevelManager::getCoinCount() {
    return level.coinCount;
}

int LevelManager::getLevelNumber() {
    return level.levelNumber;
}

void LevelManager::setLevelNumber(int newLevelNumber) {
    level.levelNumber = newLevelNumber;
}

double LevelManager::getLevelSecondsLimit() {
    return level.levelSecondsLimit;
}

void  LevelManager::setLevelSecondsLimit(double newLevelSecondsLimit) {
    level.levelSecondsLimit = newLevelSecondsLimit;
}

int LevelManager::getCoinValue() {
    return level.coinValue;
}

void LevelManager::setCoinValue(int newCoinValue) {
    level.coinValue = newCoinValue;
}

int LevelManager::getPlayerRow() {
    return level.current_row;
}

void LevelManager::setPlayerRow(int newPlayerRow) {
    level.current_row = newPlayerRow;
}

int LevelManager::getPlayerCol() {
    return level.current_col;
}

void LevelManager::setPlayerCol(int newPlayerCol) {
    level.current_col = newPlayerCol;
}

int LevelManager::getSizeRow() {
    return level.row_size;
}

void LevelManager::setSizeRow(int newSizeRow) {
    level.row_size = newSizeRow;
}

int LevelManager:: getSizeCol() {
    return level.col_size;
}

void LevelManager::setSizeCol(int newSizeCol) {
    level.col_size = newSizeCol;
}

char LevelManager::getMapSymbol(int row, int col) {
    return level.Map[row][col];
}

void LevelManager::setMapSymbol(int row, int col, char symbol) {
    this->level.Map[row][col] = symbol;
}

Level LevelManager::getStructLevel() {
    return level;
}

void LevelManager::setStructLevel(int *variables, int levelNumber) {
    // 0-sizeRow
    // 1-sizeCol
    // 2-levelStepsLimit
    // 3-coinValue
    // 4-playerRow
    // 5-playerCol
    setTickCounter(0);
    setSecondsUsed(0);
    setCoinCount(0);
    setSizeRow(variables[0]);
    setSizeCol(variables[1]);
    setLevelSecondsLimit(static_cast<double>(variables[2]));
    setCoinValue(variables[3]);
    setPlayerRow(variables[4]);
    setPlayerCol(variables[5]);
    setLevelNumber(levelNumber);
    level.Map = new char *[variables[0]];
    for (int i = 0; i < variables[0]; i++) {
        this->level.Map[i] = new char[variables[1]];
    }
}

void LevelManager::setTickCounter(int newTickCounter) {
    tickCounter = newTickCounter;
}

int LevelManager::getTickCounter() {
    return tickCounter;
}

void LevelManager::DeclarePlayerMovement() {
    if (getTickCounter() < player->getPlayerSpeed()) {
        player->setIsMoving(false);
    } else {
        player->setIsMoving(true);
        setTickCounter(0);
    }
}

Player* LevelManager::getPlayer() {
    return player;
}

void LevelManager::loadLevel(int levelNumber) {
    std::string stringPath = "./src/maps/1-";
    std::string fullPath = stringPath + std::to_string(levelNumber);
    const char *path = fullPath.c_str();
    auto *fileObject = new FileManager(path);
    auto parametersAndMap = fileObject->readWithParameters(24, 2, 6);  // first line - parameters
    std::string stringTemp;
    stringTemp.assign(parametersAndMap[0]);
    const char *var = stringTemp.c_str();
    int *variables = convertStringToVariables(var, 6, 2);
    // delete parametersAndMap[0];
    // 6 variables(6 whitespace):sizeY(2),sizeX(2),stepLimit(2),coinValue(2),characterY(2),characterX(2),endline(1)
    setStructLevel(variables, levelNumber);
    player = new Player(variables[4], variables[5], 10, '@');
    // delete variables;
    for (int i = 0; i < getSizeRow(); i++) {
        for (int j = 0; j < getSizeCol(); j++) {
            setMapSymbol(i, j, parametersAndMap[i+1][j]);
        }
        // delete parametersAndMap[i+1];
    }
    setMapSymbol(variables[4], variables[5], player->getSymbol());
    // delete parametersAndMap;
    // delete fileObject;
}
