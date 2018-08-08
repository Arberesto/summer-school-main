#include "./Gold.h"
#include <string>
#include "./Resource.h"
Gold::Gold(int newId, std::string title) : Resource::Resource(newId, title) {
    SetType(typeid(Gold).hash_code());
}

bool Gold::IsA(size_t type) {
    return typeid(Gold).hash_code() == type || Resource::IsA(type);
}

IObject* Gold::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Gold(newId, "Gold");
}