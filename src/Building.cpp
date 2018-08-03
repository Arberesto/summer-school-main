#include "./Building.h"
#include "./IoCContainer.h"
#include "./IObject.h"
Building::Building(int row, int col, int newId, char symbol) {
    SetId(newId);
    SetSymbol(symbol);
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

void Building::SetSymbol(char newSymbol) {
    symbol = newSymbol;
}

char Building::GetSymbol() {
    return  symbol;
}