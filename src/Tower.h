#ifndef DMITRIJ_BAGAEV_MAIN_GAME_TOWER_H
#define DMITRIJ_BAGAEV_MAIN_GAME_TOWER_H
#include "./Building.h"
class Tower : public Building{
 public:
    explicit Tower(int row, int col, int newId, const char* symbol, int health, int level,
                   int maxLevel, double levelMultiplier, int attackDamage, int attackSpeed, int attackRadius);
    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type) override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
    int GetAttackDamage();
    void SetAttackDamage(int newAttackDamage);
    int GetAttackSpeed();
    void SetAttackSpeed(int newAttackSpeed);
    int GetAttackRadius();
    void SetAttackRadius(int newAttackRadius);
 protected:
    int attackDamage;
    int attackSpeed;
    int attackRadius;
    static const int CONST_ATK_SPD = 1;
    static const int CONST_ATK_DMG = 2;
    static const int CONST_ATK_RDS = 4;
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_TOWER_H
