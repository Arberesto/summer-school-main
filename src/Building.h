#ifndef DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
#define DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
#include "./IoCContainer.h"
class Building : public IObject {
 public:
    char symbol;
    Building() = default;
    explicit Building(int newId, char symbol);

    int GetId();

    void Delete();

    void SetId(int newId);

    void SetSymbol(char newSymbol);

    char GetSymbol();

    bool IsA(size_t type);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
