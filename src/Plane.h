#ifndef DMITRIJ_BAGAEV_MAIN_GAME_PLANE_H
#define DMITRIJ_BAGAEV_MAIN_GAME_PLANE_H
#include "./Terrain.h"
class Plane : public Terrain{
 public:
    explicit Plane(int row, int col, int newId, const char* symbol);
    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type) override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_PLANE_H
