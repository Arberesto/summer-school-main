#ifndef DMITRIJ_BAGAEV_MAIN_GAME_RESOURCE_H
#define DMITRIJ_BAGAEV_MAIN_GAME_RESOURCE_H
#include "./IoCContainer.h"
class Resource : public IObject{
 public:
    Resource() = default;
    int value = 0;
    char symbol;
    explicit Resource(int newId, char symbol);
    int GetId();

    void Delete();

    void SetId(int newId);

    void SetSymbol(char newSymbol);

    char GetSymbol();

    bool IsA(size_t type);

    void SetValue(int newValue);

    int GetValue();
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_RESOURCE_H
