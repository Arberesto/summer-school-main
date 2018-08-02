#include "./IoCContainer.h"
#include <map>
#include <utility>
#include "./IObject.h"
void IoCContainer::Register(size_t type, OBJECT_CREATE_FUNC createFunc) {
    objectTypes.insert(std::pair<size_t, OBJECT_CREATE_FUNC>(type, createFunc));
}

void IoCContainer::New(size_t type) {
    auto pos = objectTypes.find(type);
    if (pos == objectTypes.end()) {
        // raise exception
    }
    OBJECT_CREATE_FUNC func = pos->second;
    int newId = GetNextId(type);
    objectContainer.insert(std::pair<size_t, IObject*>(static_cast<size_t>(newId + type), func(type, this, newId)));
}

IObject* IoCContainer::Get(int id, size_t type) {
    return objectContainer.find(static_cast<size_t>(type + id))->second;
}


int IoCContainer::GetNextId(size_t type) {
    return 1;
}

void IoCContainer::Delete(IObject* object) {
    auto pos = objectContainer.find(object->GetId());
    if (pos == objectContainer.end()) {
        // raise exception
        return;
    }
    pos->second->Delete();
    pos->second = nullptr;
    objectContainer.erase(pos);
}

IoCContainer::IoCContainer() {
}

IoCContainer::~IoCContainer() {
}
