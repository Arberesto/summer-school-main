#include "./IoCContainer.h"
#include <map>
#include <utility>
#include <vector>
#include <string>
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

int IoCContainer::GetY(size_t type) {
    return coordinatesContainer.find(type)->second / 200;
}

int IoCContainer::GetX(size_t type) {
    int temp = coordinatesContainer.find(type)->second;
    int temp1 = temp / 200;
    return temp - temp1 * 200;
}

void IoCContainer::SetCoordinates(int Y, int X, size_t type) {
    coordinatesContainer.insert(std::pair<size_t, int>(type, Y * 200 + X));
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

size_t** IoCContainer::GetIdList(size_t type) {
    std::vector<int> idVector;
    std::vector<size_t> typeVector;
    for (auto it : objectContainer) {
        if (it.second->IsA(type)) {
            idVector.insert(idVector.end(), it.second->GetId());
            typeVector.insert(typeVector.end(), it.first - it.second->GetId());
        }
    }
    auto result = new size_t*[2];
    result[0] = new size_t[idVector.size() + 1];
    result[1] = new size_t[typeVector.size() + 1];
    result[0][0] = idVector.size();
    result[1][0] = typeVector.size();
    for (int i = 0; i < static_cast<int>(result[0][0]); i++) {
        result[0][i + 1] = static_cast<size_t>(idVector[i]);
        result[1][i + 1] = typeVector[i];
    }
    return result;
}


IoCContainer::IoCContainer() {
}

IoCContainer::~IoCContainer() {
}
