#include "./ClayPit.h"
#include <string>
#include "./ProducingBuilding.h"
ClayPit::ClayPit(int row, int col, int newId, const char* symbol, int health, int level, int maxLevel,
             size_t produceType, int produceAmount, double levelMultiplier) :
        ProducingBuilding(row, col, newId, symbol, health, level, maxLevel,
                          produceType, produceAmount, levelMultiplier) {
    SetType(typeid(ClayPit).hash_code());
    SetBuildingSideSize(1);
    SetDrawField(GenerateDrawField('@'));
}

bool ClayPit::IsA(size_t type) {
    return typeid(ClayPit).hash_code() == type || ProducingBuilding::IsA(type);
}

IObject* ClayPit::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new ClayPit(iocContainer->GetY<ClayPit>(), iocContainer->GetX<ClayPit>(),
                     newId, std::string("ClayPit").c_str(), 10 , 1, 3, iocContainer->Get<Clay>(1)->GetType(), 1, 1.0);
}
