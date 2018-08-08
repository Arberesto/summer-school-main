#include "./ProducingBuilding.h"
#include <string>
#include "./Building.h"
ProducingBuilding::ProducingBuilding(int row, int col, int newId, const char* symbol, int health, int level,
                                     int maxLevel, size_t produceType, int produceAmount, double levelMultiplier) :
        Building(row, col, newId, symbol, health, level, maxLevel, levelMultiplier) {
    SetType(typeid(ProducingBuilding).hash_code());
    SetProduceType(produceType);
    SetProduceAmount(produceAmount);
}

bool ProducingBuilding::IsA(size_t type) {
    return typeid(ProducingBuilding).hash_code() == type || Building::IsA(type);
}

int ProducingBuilding::GetProduceAmount() {
    return produceAmount;
}

void ProducingBuilding::SetProduceAmount(int newProduceAmount) {
    produceAmount = newProduceAmount;
}

size_t ProducingBuilding::GetProduceType() {
    return produceType;
}

void ProducingBuilding::SetProduceType(size_t newProduceType) {
    produceType = newProduceType;
}

int ProducingBuilding::GetRealProduceAmount() {
    return GetProduceAmount() * GetLevel() * GetLevelMultiplier();
}