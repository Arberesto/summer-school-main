#include "./Farm.h"
#include <string>
#include "./ProducingBuilding.h"
Farm::Farm(int row, int col, int newId, std::string symbol, int health, int level, int maxLevel,
                 size_t produceType, int produceAmount, double levelMultiplier) :
        ProducingBuilding(row, col, newId, symbol, health, level, maxLevel,
                          produceType, produceAmount, levelMultiplier) {
    SetType(typeid(Farm).hash_code());
    SetBuildingSideSize(1);
    SetDrawField(GenerateDrawField('%'));
}

bool Farm::IsA(size_t type) {
    return typeid(Farm).hash_code() == type || ProducingBuilding::IsA(type);
}

IObject* Farm::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Farm(iocContainer->GetY<Farm>(), iocContainer->GetX<Farm>(),
                       newId, "Farm", 10 , 1, 3, iocContainer->Get<Food>(1)->GetType(), 1, 1.0);
}

