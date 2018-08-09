#ifndef ROUGE_DEMO_FLOOR_H
#define ROUGE_DEMO_FLOOR_H
#include "./Terrain.h"
class Floor : public Terrain{
    explicit Floor(int row, int col, int newId, const char* symbol);
    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type) override;
    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
};
#endif  // ROUGE_DEMO_FLOOR_H
