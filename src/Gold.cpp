#include "./Gold.h"
#include "./Resource.h"
Gold::Gold(int newId, char symbol) {
    SetId(newId);
    SetSymbol(symbol);
}

bool Gold::IsA(size_t type) {
    return typeid(Gold).hash_code() == type || Resource::IsA(type);
}

IObject* Gold::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Gold(newId, 'G');
}