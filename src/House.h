#ifndef DMITRIJ_BAGAEV_MAIN_GAME_HOUSE_H
#define DMITRIJ_BAGAEV_MAIN_GAME_HOUSE_H
#include "./Building.h"

class House :public Building {
 public:
    static const int typeOf = 11;
    explicit House(int newId, char symbol, int type);
    int GetId() override;
    bool IsA(int type) override;
    void SetId(int newId) override;
    int GetType() override;
    char GetSymbol() override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
 private:
};
#endif  //  DMITRIJ_BAGAEV_MAIN_GAME_HOUSE_H
