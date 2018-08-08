#ifndef DMITRIJ_BAGAEV_MAIN_GAME_HOUSE_H
#define DMITRIJ_BAGAEV_MAIN_GAME_HOUSE_H
#include "./ProducingBuilding.h"
class House :public ProducingBuilding {
 public:
    explicit House(int row, int col, int newId, const char* symbol, int health,
                   int level, int maxLevel, double levelMultiplier);
    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type) override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
};
#endif  //  DMITRIJ_BAGAEV_MAIN_GAME_HOUSE_H
