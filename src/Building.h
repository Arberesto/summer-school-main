#ifndef DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
#define DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
#include <string>
#include "./IoCContainer.h"
class Building : public IObject {
 protected:
    std::string symbol;
    int health;
    int level;
    int maxLevel;
    double levelMultiplier;
    int row;
    int col;
    char ** drawField;  // первая строка: sizeRow,SizeCol; остальные - сам массив символов
    int buildingSideSize = 1;

 public:
    Building() = default;
    explicit Building(int row, int col, int newId, std::string symbol, int health,
                      int level, int maxLevel, double levelMultiplier);
    ~Building();

    void SetDrawField(char ** newDrawField);

    char** GetDrawField();

    void SetBuildingSideSize(int newBuildingSideSize);

    int GetBuildingSideSize();

    char** GenerateDrawField(char symbol);

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

    std::string GetTextField();

    void SetTextField(std::string newTextField);

    void Delete();

    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_BUILDING_H
