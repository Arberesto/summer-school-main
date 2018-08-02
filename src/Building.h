#ifndef DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
#define DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
#include "./IoCContainer.h"
class Building : public IObject {
 public:
    char symbol;
    static const int typeOf = 10;
    Building() = default;
    explicit Building(int newId, char symbol, int type);

    int  GetType();

    int GetId();

    void Delete();

    void SetId(int newId);

    void SetSymbol(char newSymbol);

    char GetSymbol();

    void SetType(int newType);

    bool IsA(int type);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
