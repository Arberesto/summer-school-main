#ifndef DMITRIJ_BAGAEV_MAIN_GAME_HOUSE_H
#define DMITRIJ_BAGAEV_MAIN_GAME_HOUSE_H
#include "./Building.h"
#include "./IoCContainer.h"
class House :Building{
 public:
    explicit House(int newId);
    int GetId() override;
    bool IsA(int type) override;
    void SetId(int newId) override;
    static IObject* Create(int type, IoCContainer *iocContainer, int newId);

 private:
};
#endif  //  DMITRIJ_BAGAEV_MAIN_GAME_HOUSE_H
