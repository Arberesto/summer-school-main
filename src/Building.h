#ifndef DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
#define DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
#include "./IoCContainer.h"
class Building : public IObject {
 public:
    char symbol;
    int row;
    int col;
    Building() = default;
    explicit Building(int row, int col, int newId, const char * symbol);

    int GetId();

    int GetRow();

    void SetRow(int newRow);

    int GetCol();

    const char* GetTextField();
    void SetTextField(const char* newTextField);

    void SetCol(int newCol);

    void Delete();

    void SetId(int newId);

    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
