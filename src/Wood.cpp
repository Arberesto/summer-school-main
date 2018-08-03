#include "./Wood.h"
#include "./Resource.h"
Wood::Wood(int newId, char symbol) {
    SetId(newId);
    SetSymbol(symbol);
}

bool Wood::IsA(size_t type) {
    return typeid(Wood).hash_code() == type || Resource::IsA(type);
}

IObject* Wood::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Wood(newId, 'W');
}
