#ifndef DMITRIJ_BAGAEV_MAIN_GAME_SAWMILL_H
#define DMITRIJ_BAGAEV_MAIN_GAME_SAWMILL_H
#include <string>
#include "./ProducingBuilding.h"
class Sawmill : ProducingBuilding{
 public:
    explicit Sawmill(int row, int col, int newId, std::string symbol, int health,
                     int level, int maxLevel, size_t produceType, int produceAmount, double levelMultiplier);
    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type) override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_SAWMILL_H
