#ifndef DMITRIJ_BAGAEV_MAIN_GAME_PRODUCINGBUILDING_H
#define DMITRIJ_BAGAEV_MAIN_GAME_PRODUCINGBUILDING_H
#include "./Building.h"
#include "./ResourceList.h"
class ProducingBuilding :public Building {
 protected:
    size_t produceType;
    int produceAmount;
 public:
    explicit ProducingBuilding(int row, int col, int newId, const char* symbol, int health,
                   int level, int maxLevel, size_t produceType, int produceAmount, double levelMultiplier);
    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type) override;
    int GetProduceAmount();
    void SetProduceAmount(int newProduceAmount);
    size_t GetProduceType();
    void SetProduceType(size_t newProduceType);
    int GetRealProduceAmount();
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_PRODUCINGBUILDING_H
