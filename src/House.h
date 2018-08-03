#ifndef DMITRIJ_BAGAEV_MAIN_GAME_HOUSE_H
#define DMITRIJ_BAGAEV_MAIN_GAME_HOUSE_H
#include "./Building.h"
class House :public Building {
 public:
    explicit House(int row, int col, int newId, char symbol);
    int GetId() override;
    bool IsA(size_t type) override;
    void SetId(int newId) override;
    char GetSymbol() override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
};
#endif  //  DMITRIJ_BAGAEV_MAIN_GAME_HOUSE_H
