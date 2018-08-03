#ifndef DMITRIJ_BAGAEV_MAIN_GAME_PEOPLE_H
#define DMITRIJ_BAGAEV_MAIN_GAME_PEOPLE_H
#include "./Resource.h"
class People : public Resource{
 public:
    explicit People(int newId, char symbol);
    bool IsA(size_t type) override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_PEOPLE_H
