#ifndef DMITRIJ_BAGAEV_MAIN_GAME_CLAY_H
#define DMITRIJ_BAGAEV_MAIN_GAME_CLAY_H
#include "./Resource.h"
class Clay : public Resource {
 public:
    explicit Clay(int newId, char symbol);
    bool IsA(size_t type) override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_CLAY_H
