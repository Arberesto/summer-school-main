#include "./Food.h"
#include <string>
#include "./Resource.h"
Food::Food(int newId, std::string title) : Resource::Resource(newId, title) {
    SetType(typeid(Food).hash_code());
}

bool Food::IsA(size_t type) {
    return typeid(Food).hash_code() == type || Resource::IsA(type);
}

IObject* Food::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Food(newId, "Food");
}