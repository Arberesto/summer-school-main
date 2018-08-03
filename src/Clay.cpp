#include "./Clay.h"
#include "./Resource.h"
Clay::Clay(int newId, char symbol) {
    SetId(newId);
    SetSymbol(symbol);
}

bool Clay::IsA(size_t type) {
    return typeid(Clay).hash_code() == type || Resource::IsA(type);
}

IObject* Clay::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Clay(newId, 'C');
}
