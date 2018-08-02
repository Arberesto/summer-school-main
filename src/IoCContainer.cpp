#include "./IoCContainer.h"
#include <map>
#include <utility>
#include "./IObject.h"
void IoCContainer::Register(int type, OBJECT_CREATE_FUNC createFunc) {
    objectTypes.insert(std::pair<int, OBJECT_CREATE_FUNC>(type, createFunc));
}

void IoCContainer::New(int type) {
    std::map<int, OBJECT_CREATE_FUNC>::const_iterator pos = objectTypes.find(type);
    if (pos == objectTypes.end()) {
        // raise exception
    }
    OBJECT_CREATE_FUNC func = pos->second;
    int newId = GetNextId(type);
    objectContainer.insert(std::pair<int, IObject*>(newId, func(type, this, newId)));
}

IObject* IoCContainer::Get(int index) {
    return objectContainer.find(index)->second;
}


int IoCContainer::GetNextId(int type) {
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
