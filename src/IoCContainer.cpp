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
        return;
    }
    OBJECT_CREATE_FUNC func = pos->second;
    int newId = GetNextId(type);
    objectContainer.insert(std::pair<size_t, IObject*>(static_cast<size_t>(newId + type), func(type, this, newId)));
}

IObject* IoCContainer::Get(int id, size_t type) {
    return objectContainer.find(static_cast<size_t>(type + id))->second;
}

int IoCContainer::GetY(size_t type) {
    return coordinatesContainer.find(type)->second / TYPE_MULTIPLIER;
}

int IoCContainer::GetX(size_t type) {
    int temp = coordinatesContainer.find(type)->second;
    int temp1 = temp / TYPE_MULTIPLIER;
    return temp - temp1 * TYPE_MULTIPLIER;
}

void IoCContainer::SetCoordinates(int Y, int X, size_t type) {
    auto temp = coordinatesContainer.find(type);
    if (temp->first == type) {
        coordinatesContainer.erase(type);
    }
    coordinatesContainer.insert(std::pair<size_t, int>(type, (Y * TYPE_MULTIPLIER) + X));
}

void IoCContainer::SetNextId(size_t type, int nextId) {
    auto temp = nextIdContainer.find(type);
    if (temp->first == type) {
        nextIdContainer.erase(type);
    }
    nextIdContainer.insert(std::pair<size_t, int>(type, nextId));
}

int IoCContainer::GetNextId(size_t type) {
    auto result = nextIdContainer.find(type);
    if (result->first != type) {
        SetNextId(type, 2);
        return 1;
    }
    int lastId = result->second;
    SetNextId(type, lastId + 1);
    return lastId;
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

size_t** IoCContainer::GetIdList(size_t type) {  // [0][0]-number of types;[i][1]-number of elements in row;[i][2]-type
    std::vector<int> idVector;
    std::vector<size_t> typeVector;
    std::map<size_t, int> typeCounterMap;
    for (auto it : objectContainer) {
        if (it.second->IsA(type)) {
            idVector.insert(idVector.end(), it.second->GetId());
            typeVector.insert(typeVector.end(), it.second->GetType());
            if (typeCounterMap.find(it.second->GetType())->first != it.second->GetType()) {
                typeCounterMap.insert(std::pair<size_t, int>(it.second->GetType(), 1));
            } else {
                int previous = typeCounterMap.find(it.second->GetType())->second;
                typeCounterMap.erase(it.second->GetType());
                typeCounterMap.insert(std::pair<size_t, int>(it.second->GetType(),
                                                             previous + 1));
            }
        }
    }
    auto result = new size_t*[typeCounterMap.size()];
    int i = 0;
    for (auto it : typeCounterMap) {
        result[i] = new size_t[it.second + 3];
        result[i][0] = 0;
        result[i][1] = static_cast<size_t>(it.second);
        result[i][2] = it.first;
        i++;
    }
    result[0][0] = typeCounterMap.size();
    i = 0;
    for (auto it1 : typeCounterMap) {
        int j = 3;
        for (int k = 0; k < static_cast<int>(typeVector.size()); k++) {
            if (typeVector[k] == it1.first) {
                result[i][j] = static_cast<size_t>(idVector[k]);
                j++;
            }
        }
        i++;
    }
    return result;
}


IoCContainer::IoCContainer() {
}

IoCContainer::~IoCContainer() {
}
