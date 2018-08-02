#ifndef DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
#define DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
#include "./IObject.h"
class Building : public IObject {
 public:
    Building() = default;
    explicit Building(int newId);

    int  GetType();

    int GetId();

    void Delete();

    void SetId(int newId);

    void SetSymbol(char newSymbol);

    char GetSymbol();

    void SetType(int newType);

    bool IsA(int type);

 private:
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
