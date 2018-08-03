#include "./People.h"
#include "./Resource.h"
People::People(int newId, char symbol) {
    SetId(newId);
    SetSymbol(symbol);
}

bool People::IsA(size_t type) {
    return typeid(People).hash_code() == type || Resource::IsA(type);
}

IObject* People::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new People(newId, 'P');
}
