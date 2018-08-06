#include "./People.h"
#include <string>
#include "./Resource.h"
People::People(int newId, std::string title) : Resource::Resource(newId, title) {
}

bool People::IsA(size_t type) {
    return typeid(People).hash_code() == type || Resource::IsA(type);
}

IObject* People::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new People(newId, "People");
}
