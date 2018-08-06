#ifndef DMITRIJ_BAGAEV_MAIN_GAME_GOLD_H
#define DMITRIJ_BAGAEV_MAIN_GAME_GOLD_H
#include <string>
#include "./Resource.h"
class Gold : public Resource {
 public:
    explicit Gold(int newId, std::string title);
    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type) override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_GOLD_H
