#ifndef DMITRIJ_BAGAEV_MAIN_GAME_WOOD_H
#define DMITRIJ_BAGAEV_MAIN_GAME_WOOD_H
#include "./Resource.h"
class Wood :public Resource{
 public:
    explicit Wood(int newId, char symbol);
    bool IsA(size_t type) override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_WOOD_H
