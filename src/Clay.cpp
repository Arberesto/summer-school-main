#include "./Clay.h"
#include <string>
#include "./Resource.h"
Clay::Clay(int newId, std::string title) : Resource::Resource(newId, title) {
    SetType(typeid(Clay).hash_code());
}

bool Clay::IsA(size_t type) {
    return typeid(Clay).hash_code() == type || Resource::IsA(type);
}

IObject* Clay::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Clay(newId, "Clay");
}
