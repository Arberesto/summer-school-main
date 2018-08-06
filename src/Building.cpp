#include "./Building.h"
#include <string>
#include "./IoCContainer.h"
#include "./IObject.h"

Building::Building(int row, int col, int newId, const char* symbol) {
    SetId(newId);
    SetTextField(symbol);
    SetRow(row);
    SetCol(col);
}

int Building::GetId() {
    return id;
}

void Building::Delete() {
}

void Building::SetId(int newId) {
    id = newId;
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
    result.append(std::to_string(symbol));
    return result.c_str();
}

void Building::SetTextField(const char* newTextField) {
    symbol = newTextField[0];
}