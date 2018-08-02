#include "./House.h"
#include "./Building.h"
House::House(int newId, char symbol, int type) : Building(newId, symbol, type) {
}

bool House::IsA(int type) {
return typeOf == type || Building::IsA(type);
}

int House::GetId() {
return id;
}

int House::GetType() {
    return typeOf;
}

void House::SetId(int newId) {
id = newId;
}

char House::GetSymbol() {
    return symbol;
}

IObject* House::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new House(newId, '^' , 11);
}
