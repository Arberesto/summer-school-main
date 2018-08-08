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