#include "./House.h"
#include "./Building.h"
House::House(int newId, char symbol) : Building(newId, symbol) {
}

bool House::IsA(size_t type) {
return typeid(House).hash_code() == type || Building::IsA(type);
}

int House::GetId() {
return id;
}

void House::SetId(int newId) {
id = newId;
}

char House::GetSymbol() {
    return symbol;
}

IObject* House::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new House(newId, '^');
}
