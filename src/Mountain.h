#ifndef DMITRIJ_BAGAEV_MAIN_GAME_MOUNTAIN_H
#define DMITRIJ_BAGAEV_MAIN_GAME_MOUNTAIN_H
#include "./Terrain.h"
class Mountain : public Terrain{
 public:
    explicit Mountain(int row, int col, int newId, const char* symbol);
    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type) override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_MOUNTAIN_H
