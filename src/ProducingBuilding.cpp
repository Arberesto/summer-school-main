#include "./ProducingBuilding.h"
#include <string>
#include "./Building.h"
ProducingBuilding::ProducingBuilding(int row, int col, int newId, const char* symbol, int health, int level,
                                     int maxLevel, double levelMultiplier) :
        Building(row, col, newId, symbol, health, level, maxLevel, levelMultiplier) {
}

bool ProducingBuilding::IsA(size_t type) {
    return typeid(ProducingBuilding).hash_code() == type || Building::IsA(type);
}

// IObject* ProducingBuilding::Create(size_t type, IoCContainer *iocContainer, int newId) {
//    return new ProducingBuilding(iocContainer->GetY<ProducingBuilding>(), iocContainer->GetX<ProducingBuilding>(),
//                     newId, std::string("Q").c_str(), 10 , 1, 3, 0.9);
// }
