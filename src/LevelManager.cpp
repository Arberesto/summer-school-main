#include <string>
#include "./LevelManager.h"
#include "./Utility.h"
#include "./FileManager.h"
#include "./Player.h"
#include "./IObject.h"
#include "./TerrainList.h"
LevelManager::LevelManager(IoCContainer* container, int newId) {
    SetId(newId);
    loadLevel(container, START_LEVEL);
    SetType(typeid(LevelManager).hash_code());
}

IObject* LevelManager::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new LevelManager(iocContainer, newId);
}

//  bool LevelManager::nextLevel() {
//    setPrevSeconds(getPrevSeconds() + getSecondsUsed());
//    if (getLevelNumber() < 1) {
//        loadLevel(getLevelNumber() + 1);
//        return true;
//    } else {
//        loadLevel(1);
//        return false;
//    }
//  }

double LevelManager::getPrevSeconds() {
    return level.prevSeconds;
}

void LevelManager::setPrevSeconds(double newPrevSeconds) {
    level.prevSeconds = newPrevSeconds;
}

void LevelManager::setLastSecond(int newLastSecond) {
    lastSecond = newLastSecond;
}

int LevelManager::getLastSecond() {
    return lastSecond;
}

void LevelManager::setSecondsUsed(double newSecondsUsed) {
    level.secondsUsed = newSecondsUsed;
    if (static_cast<int>(getSecondsUsed()) - getLastSecond() > 0) {
        setLastSecond(static_cast<int>(getSecondsUsed()));
        SetIsNewSecondNow(true);
    }
}

double LevelManager::getSecondsUsed() {
    return level.secondsUsed;
}

int LevelManager::getLevelNumber() {
    return level.levelNumber;
}

void LevelManager::setLevelNumber(int newLevelNumber) {
    level.levelNumber = newLevelNumber;
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

void  LevelManager::SetIsNewSecondNow(bool newIsNewSecondNow) {
    isNewSecondNow = newIsNewSecondNow;
}

bool  LevelManager::GetIsNewSecondNow() {
    return  isNewSecondNow;
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
    setLastSecond(0);
    setSizeRow(variables[0]);
    setSizeCol(variables[1]);
    setLevelNumber(levelNumber);
}

void LevelManager::setTickCounter(int newTickCounter) {
    tickCounter = newTickCounter;
}

int LevelManager::getTickCounter() {
    return tickCounter;
}

void LevelManager::loadLevel(IoCContainer* container, int levelNumber) {
    std::string stringPath = "./src/maps/1-";
    std::string fullPath = stringPath + std::to_string(levelNumber);
    const char *path = fullPath.c_str();
    auto *fileObject = new FileManager(path);
    auto parametersAndMap = fileObject->readWithParameters(24, 3, 6);  // first line - parameters
    std::string stringTemp;
    stringTemp.assign(parametersAndMap[0]);
    const char *var = stringTemp.c_str();
    int *variables = convertStringToVariables(var, 6, 3);
    // delete parametersAndMap[0];
    // 6 variables(6 whitespace):sizeY(2),sizeX(2),stepLimit(2),coinValue(2),characterY(2),characterX(2),endline(1)
    setStructLevel(variables, levelNumber);
    // delete variables;
    for (int i = 0; i < getSizeRow(); i++) {
        for (int j = 0; j < getSizeCol(); j++) {
            size_t tileType = ConvertTileToObject(container, parametersAndMap[i+1][j]);
            container->SetCoordinates(i + 1, j , tileType);
            container->New(tileType);
        }
        // delete parametersAndMap[i+1];
    }
    // setMapSymbol(variables[4], variables[5], player->getSymbol());
    // delete parametersAndMap;
    // delete fileObject;
    delete fileObject;
}

size_t LevelManager::ConvertTileToObject(IoCContainer* container, char tile) {
    size_t result = typeid(Plane).hash_code();
    switch (tile) {
        case 35 :  {  // #
            result = typeid(Mountain).hash_code();
            break;
        }
        case 46 :  {  // .
            result = typeid(Plane).hash_code();
            break;
        }
        default:
            break;
    }
    return result;
}

int LevelManager::GetId() {
    return id;
}
void LevelManager::SetId(int newId) {
    id = newId;
}
bool LevelManager::IsA(size_t type) {
    return typeid(LevelManager).hash_code() == type;
}

void LevelManager::Delete() {
}

size_t LevelManager::GetType() {
    return type;
}

void LevelManager::SetType(size_t newType) {
    type = newType;
}
