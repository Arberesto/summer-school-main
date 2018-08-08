#ifndef DMITRIJ_BAGAEV_MAIN_GAME_PRODUCINGBUILDING_H
#define DMITRIJ_BAGAEV_MAIN_GAME_PRODUCINGBUILDING_H
#include "./Building.h"
class ProducingBuilding :public Building {
 protected:
    size_t producedType;
    int produceAmount;
 public:
    explicit ProducingBuilding(int row, int col, int newId, const char* symbol, int health,
                   int level, int maxLevel, double levelMultiplier);
    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type) override;
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_PRODUCINGBUILDING_H
