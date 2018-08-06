#ifndef DMITRIJ_BAGAEV_MAIN_GAME_FOOD_H
#define DMITRIJ_BAGAEV_MAIN_GAME_FOOD_H
#include <string>
#include "./Resource.h"
class Food : public Resource{
 public:
    explicit Food(int newId, std::string title);
    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type) override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_FOOD_H
