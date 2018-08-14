#include "./Mine.h"
#include <string>
#include "./ProducingBuilding.h"
Mine::Mine(int row, int col, int newId, const char* symbol, int health, int level, int maxLevel,
             size_t produceType, int produceAmount, double levelMultiplier) :
        ProducingBuilding(row, col, newId, symbol, health, level, maxLevel,
                          produceType, produceAmount, levelMultiplier) {
    SetType(typeid(Mine).hash_code());
    SetBuildingSideSize(2);
    auto ** mineField = new char*[3];
    for (int i = 1; i < 3; i++) {
        mineField[i] = new char[2];
        for (int j = 0; j < 2; j++) {
            mineField[i][j] = static_cast<char>(91 + 2 * j);
        }
    }
    mineField[0] = new char[2];
    mineField[0][0] = 2;
    mineField[0][1] = 2;
    SetDrawField(mineField);
}

bool Mine::IsA(size_t type) {
    return typeid(Mine).hash_code() == type || ProducingBuilding::IsA(type);
}

IObject* Mine::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Mine(iocContainer->GetY<Mine>(), iocContainer->GetX<Mine>(),
                     newId, std::string("Mine").c_str(), 10 , 1, 3, iocContainer->Get<Ore>(1)->GetType(), 1, 1.0);
}
