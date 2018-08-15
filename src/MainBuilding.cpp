#include "./MainBuilding.h"
#include <string>
#include "./ProducingBuilding.h"
MainBuilding::MainBuilding(int row, int col, int newId, std::string symbol, int health, int level, int maxLevel,
                           size_t produceType, int produceAmount, double levelMultiplier) :
        ProducingBuilding(row, col, newId, symbol, health, level, maxLevel,
                          produceType, produceAmount, levelMultiplier) {
    SetType(typeid(MainBuilding).hash_code());
    SetBuildingSideSize(2);
    SetDrawField(GenerateDrawField('H'));
}

bool MainBuilding::IsA(size_t type) {
    return typeid(MainBuilding).hash_code() == type || ProducingBuilding::IsA(type);
}

IObject* MainBuilding::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new MainBuilding(iocContainer->GetY<MainBuilding>(),
            iocContainer->GetX<MainBuilding>(), newId, "Main Building", 50 , 1, 1,
                            iocContainer->Get<Food>(1)->GetType(), 1, 2.0);
}

