#include "./Resource.h"
#include <string>
#include "./IoCContainer.h"
#include "./IObject.h"
Resource::Resource(int newId, std::string newTitle) {
    SetId(newId);
    SetTextField(newTitle.c_str());
    SetType(typeid(Resource).hash_code());
}

int Resource::GetId() {
    return id;
}

void Resource::Delete() {
}

void Resource::SetId(int newId) {
    id = newId;
}

void Resource::SetTextField(const char* newTitle) {
    title = std::string(newTitle);
}

const char* Resource::GetTextField() {
    return title.c_str();
}

bool Resource::IsA(size_t type) {
    return typeid(Resource).hash_code() == type;
}

void Resource::SetValue(int newValue) {
    value = newValue;
}


int Resource::GetValue() {
    return value;
}

void Resource::IncreaseValue(int addedValue) {
    SetValue(GetValue() + addedValue);
}

size_t Resource::GetType() {
    return type;
}

void Resource::SetType(size_t newType) {
    type = newType;
}
