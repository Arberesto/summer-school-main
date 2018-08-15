#ifndef DMITRIJ_BAGAEV_MAIN_GAME_MAINBUILDING_H
#define DMITRIJ_BAGAEV_MAIN_GAME_MAINBUILDING_H
#include <string>
#include "./ProducingBuilding.h"
class MainBuilding :public ProducingBuilding {
 public:
    explicit MainBuilding(int row, int col, int newId, std::string symbol, int health,
                          int level, int maxLevel, size_t produceType, int produceAmount, double levelMultiplier);
    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type) override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_MAINBUILDING_H
