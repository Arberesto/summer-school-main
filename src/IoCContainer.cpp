#include "./IoCContainer.h"
#include <map>
#include <utility>
#include "./IObject.h"
void IoCContainer::Register(int type, OBJECT_CREATE_FUNC createFunc) {
    objectTypes.insert(std::pair<int, OBJECT_CREATE_FUNC>(type, createFunc));
}

IObject* IoCContainer::Get(int type) {
    std::map<int, OBJECT_CREATE_FUNC>::const_iterator pos = objectTypes.find(type);
    if (pos == objectTypes.end()) {
        // raise exception
    }
    OBJECT_CREATE_FUNC func = pos->second;
    int newId = GetNextId(type);
    objectContainer.insert(std::pair<int, IObject*>(newId, func(type, this, newId)));
    return objectContainer.find(newId)->second;
}

int IoCContainer::GetNextId(int type) {
    return 0;
}

void IoCContainer::Delete(int index, int type) {
    std::map<int, IObject*>::const_iterator pos = objectContainer.find(index);
    if (pos == objectContainer.end()) {
        // raise exception
        return;
    }
    IObject *object = pos->second;
    if (object->GetType() == type) {
        delete object;
        delete pos->second;
    }
}