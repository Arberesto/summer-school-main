#include "./Ore.h"
#include "./Resource.h"
Ore::Ore(int newId, char symbol) {
    SetId(newId);
    SetSymbol(symbol);
}

bool Ore::IsA(size_t type) {
    return typeid(Ore).hash_code() == type || Resource::IsA(type);
}

IObject* Ore::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Ore(newId, 'O');
}