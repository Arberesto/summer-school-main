#ifndef DMITRIJ_BAGAEV_MAIN_GAME_GOLD_H
#define DMITRIJ_BAGAEV_MAIN_GAME_GOLD_H
#include "./Resource.h"
class Gold : public Resource {
 public:
    explicit Gold(int newId, char symbol);
    bool IsA(size_t type) override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_GOLD_H
