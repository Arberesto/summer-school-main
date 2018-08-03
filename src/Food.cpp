#include "./Food.h"
#include "./Resource.h"

Food::Food(int newId, char symbol) {
    SetId(newId);
    SetSymbol(symbol);
}

bool Food::IsA(size_t type) {
    return typeid(Food).hash_code() == type || Resource::IsA(type);
}

IObject* Food::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Food(newId, 'F');
}