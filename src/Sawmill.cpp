#include "./Sawmill.h"
#include <string>
#include "./ProducingBuilding.h"
Sawmill::Sawmill(int row, int col, int newId, std::string symbol, int health, int level, int maxLevel,
                 size_t produceType, int produceAmount, double levelMultiplier) :
        ProducingBuilding(row, col, newId, symbol, health, level, maxLevel,
                          produceType, produceAmount, levelMultiplier) {
    SetType(typeid(Sawmill).hash_code());
    SetBuildingSideSize(2);
    SetDrawField(GenerateDrawField('/'));
}

bool Sawmill::IsA(size_t type) {
    return typeid(Sawmill).hash_code() == type || ProducingBuilding::IsA(type);
}

IObject* Sawmill::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Sawmill(iocContainer->GetY<Sawmill>(), iocContainer->GetX<Sawmill>(),
                       newId, "Sawmill", 10 , 1, 3, iocContainer->Get<Wood>(1)->GetType(), 1, 1.0);
}
