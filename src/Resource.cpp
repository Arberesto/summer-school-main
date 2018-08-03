#include "./Resource.h"
#include "./IoCContainer.h"
#include "./IObject.h"
Resource::Resource(int newId, char symbol) {
    SetId(newId);
    SetSymbol(symbol);
}

int Resource::GetId() {
    return id;
}

void Resource::Delete() {
}

void Resource::SetId(int newId) {
    id = newId;
}

void Resource::SetSymbol(char newSymbol) {
    symbol = newSymbol;
}

char Resource::GetSymbol() {
    return symbol;
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