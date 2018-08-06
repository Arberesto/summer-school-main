#include "./House.h"
#include <string>
#include "./Building.h"
House::House(int row, int col, int newId, const char* symbol) : Building(row, col, newId, symbol) {
}

bool House::IsA(size_t type) {
return typeid(House).hash_code() == type || Building::IsA(type);
}

IObject* House::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new House(iocContainer->GetY<House>(), iocContainer->GetX<House>(), newId, std::string("^").c_str());
}
