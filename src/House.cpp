#include "./House.h"
#include <string>
#include "./ProducingBuilding.h"
House::House(int row, int col, int newId, const char* symbol, int health, int level, int maxLevel,
             double levelMultiplier) :
        ProducingBuilding(row, col, newId, symbol, health, level, maxLevel, levelMultiplier) {
}

bool House::IsA(size_t type) {
return typeid(House).hash_code() == type || ProducingBuilding::IsA(type);
}

IObject* House::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new House(iocContainer->GetY<House>(), iocContainer->GetX<House>(),
            newId, std::string("^").c_str(), 10 , 1, 3, 0.9);
}
