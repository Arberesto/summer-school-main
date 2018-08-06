#include "./MainBuilding.h"
#include <string>
#include "./Building.h"
MainBuilding::MainBuilding(int row, int col, int newId, const char* symbol) : Building(row, col, newId, symbol) {
}

bool MainBuilding::IsA(size_t type) {
    return typeid(MainBuilding).hash_code() == type || Building::IsA(type);
}

IObject* MainBuilding::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new MainBuilding(iocContainer->GetY<MainBuilding>(),
            iocContainer->GetX<MainBuilding>(), newId, std::string("H").c_str());
}

