#include "./Building.h"
#include <string>
#include <typeinfo>
#include "./IoCContainer.h"
#include "./IObject.h"

Building::Building(int row, int col, int newId, const char* symbol,
                   int health, int level, int maxLevel, double levelMultiplier) {
    SetId(newId);
    SetTextField(symbol);
    SetRow(row);
    SetCol(col);
    SetHealth(health);
    SetLevel(level);
    SetMaxLevel(maxLevel);
    SetLevelMultiplier(levelMultiplier);
    SetType(typeid(Building).hash_code());
}
Building::~Building() {
    int temp = drawField[0][0];
    for (int i = 0; i < temp + 1; i++) {
        delete drawField[i];
    }
    delete drawField;
}
int Building::GetId() {
    return id;
}

void Building::Delete() {
}

void Building::SetId(int newId) {
    id = newId;
}

size_t Building::GetType() {
    return type;
}

void Building::SetType(size_t newType) {
    type = newType;
}

int Building::GetRow() {
    return row;
}

void Building::SetRow(int newRow) {
    row = newRow;
}

int Building::GetCol() {
    return col;
}

void Building::SetCol(int newCol) {
    col = newCol;
}

bool Building::IsA(size_t type) {
    return typeid(Building).hash_code() == type;
}

const char* Building::GetTextField() {
    std::string result;
    result.insert(result.end(), symbol);
    return result.c_str();
}

void Building::SetBuildingSideSize(int newBuildingSideSize) {
    buildingSideSize = newBuildingSideSize;
}

int Building::GetBuildingSideSize() {
    return buildingSideSize;
}


void Building::SetTextField(const char* newTextField) {
    symbol = newTextField[0];
}

int Building::GetHealth() {
    return health;
}

void Building::SetHealth(int newHealth) {
    health = newHealth;
}

int Building::GetLevel() {
    return level;
}

void Building::SetLevel(int newLevel) {
    level = newLevel;
}

int Building::GetMaxLevel() {
    return maxLevel;
}

void Building::SetMaxLevel(int newMaxLevel) {
    maxLevel = newMaxLevel;
}

double Building::GetLevelMultiplier() {
    return levelMultiplier;
}

void Building::SetLevelMultiplier(double newLevelMultiplier) {
    levelMultiplier = newLevelMultiplier;
}

void Building::SetDrawField(char** newDrawField) {
    drawField = new char*[newDrawField[0][0] + 1];
    for (int i = 1; i < newDrawField[0][0] + 1; i++) {
        drawField[i] = new char[newDrawField[0][1]];
        for (int j = 0; j < newDrawField[0][1]; j++) {
            drawField[i][j] = newDrawField[i][j];
        }
    }
    drawField[0] = new char[2];
    drawField[0][0] = newDrawField[0][0];
    drawField[0][1] = newDrawField[0][1];
}

char** Building::GetDrawField() {
    return drawField;
}

char** Building::GenerateDrawField(char symbol) {
    auto newDrawField = new char*[GetBuildingSideSize() + 1];
    for (int i = 1; i < GetBuildingSideSize() + 1; i++) {
        newDrawField[i] = new char[GetBuildingSideSize()];
        for (int j = 0; j < GetBuildingSideSize(); j++) {
            newDrawField[i][j] = symbol;
        }
    }
    newDrawField[0] = new char[2];
    newDrawField[0][0] = static_cast<char>(GetBuildingSideSize());
    newDrawField[0][1] = static_cast<char>(GetBuildingSideSize());
    return newDrawField;
}