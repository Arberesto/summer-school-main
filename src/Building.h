#ifndef DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
#define DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
#include "./IoCContainer.h"
class Building : public IObject {
 protected:
    char symbol;
    int health;
    int level;
    int maxLevel;
    double levelMultiplier;
    int row;
    int col;

 public:
    Building() = default;
    explicit Building(int row, int col, int newId, const char* symbol, int health,
                      int level, int maxLevel, double levelMultiplier);

    int GetHealth();

    void SetHealth(int newHealth);

    int GetLevel();

    void SetLevel(int newLevel);

    int GetMaxLevel();

    void SetMaxLevel(int newMaxLevel);

    double GetLevelMultiplier();

    void SetLevelMultiplier(double newLevelMultiplier);

    int GetId();

    void SetId(int newId);

    size_t GetType();

    void SetType(size_t newType);

    int GetRow();

    void SetRow(int newRow);

    int GetCol();

    void SetCol(int newCol);

    const char* GetTextField();

    void SetTextField(const char* newTextField);

    void Delete();

    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
