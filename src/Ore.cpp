#include "./Ore.h"
#include <string>
#include "./Resource.h"
Ore::Ore(int newId, std::string title) : Resource::Resource(newId, title) {
}

bool Ore::IsA(size_t type) {
    return typeid(Ore).hash_code() == type || Resource::IsA(type);
}

IObject* Ore::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Ore(newId, "Ore");
}