#include "./Wood.h"
#include <string>
#include "./Resource.h"
Wood::Wood(int newId, std::string title) : Resource::Resource(newId, title) {
    SetType(typeid(Wood).hash_code());
}

bool Wood::IsA(size_t type) {
    return typeid(Wood).hash_code() == type || Resource::IsA(type);
}

IObject* Wood::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Wood(newId, "Wood");
}
