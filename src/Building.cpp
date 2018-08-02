#include "./Building.h"
Building::Building(int newId) {
    SetId(newId);
    SetSymbol('#');
    SetType(10);
}

int  Building::GetType() {
    return typeOf;
}

int Building::GetId() {
    return id;
}

void Building::Delete() {
}

void Building::SetId(int newId) {
    id = newId;
}

bool Building::IsA(int type) {
    return typeOf == type;
}

void Building::SetSymbol(char newSymbol) {
    symbol = newSymbol;
}

char Building::GetSymbol() {
    return  symbol;
}

void Building::SetType(int newType) {
    typeOf = newType;
}