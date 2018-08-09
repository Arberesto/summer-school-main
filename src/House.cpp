#include "./House.h"
#include <string>
#include "./ProducingBuilding.h"
House::House(int row, int col, int newId, const char* symbol, int health, int level, int maxLevel,
             size_t produceType, int produceAmount, double levelMultiplier) :
        ProducingBuilding(row, col, newId, symbol, health, level, maxLevel,
                          produceType, produceAmount, levelMultiplier) {
    SetType(typeid(House).hash_code());
    SetBuildingSideSize(1);
    SetDrawField(GenerateDrawField('^'));
}

bool House::IsA(size_t type) {
    return typeid(House).hash_code() == type || ProducingBuilding::IsA(type);
}

IObject* House::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new House(iocContainer->GetY<House>(), iocContainer->GetX<House>(),
            newId, std::string("House").c_str(), 10 , 1, 3, iocContainer->Get<People>(1)->GetType(), 1, 1.0);
}
