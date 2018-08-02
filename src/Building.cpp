#include "./Building.h"
#include "./IoCContainer.h"
#include "./IObject.h"
Building::Building(int newId, char symbol) {
    SetId(newId);
    SetSymbol(symbol);
}

int Building::GetId() {
    return id;
}

void Building::Delete() {
}

void Building::SetId(int newId) {
    id = newId;
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