#include "./Tower.h"
#include <string>
Tower::Tower(int row, int col, int newId, const char* symbol, int health, int level, int maxLevel,
             double levelMultiplier, int attackDamage, int attackSpeed, int attackRadius) :
        Building(row, col, newId, symbol, health, level, maxLevel, levelMultiplier) {
    SetAttackDamage(attackDamage);
    SetAttackSpeed(attackSpeed);
    SetAttackRadius(attackRadius);
    SetType(typeid(Tower).hash_code());
    SetBuildingSideSize(1);
    SetDrawField(GenerateDrawField('T'));
}

bool Tower::IsA(size_t type) {
    return typeid(Tower).hash_code() == type || Building::IsA(type);
}

IObject* Tower::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Tower(iocContainer->GetY<Tower>(), iocContainer->GetX<Tower>(),
            newId, std::string("Tower").c_str(), 25 , 1, 3, 1.0, CONST_ATK_DMG, CONST_ATK_SPD, CONST_ATK_RDS);
}

int Tower::GetAttackDamage() {
    return attackDamage;
}

void Tower::SetAttackDamage(int newAttackDamage) {
    attackDamage = newAttackDamage;
}

int Tower::GetAttackSpeed() {
    return attackSpeed;
}

void Tower::SetAttackSpeed(int newAttackSpeed) {
    attackSpeed = newAttackSpeed;
}

int Tower::GetAttackRadius() {
    return attackRadius;
}

void Tower::SetAttackRadius(int newAttackRadius) {
    attackRadius = newAttackRadius;
}