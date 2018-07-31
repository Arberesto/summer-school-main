#ifndef DMITRIJ_BAGAEV_MAIN_GAME_IOCCONTAINER_H
#define DMITRIJ_BAGAEV_MAIN_GAME_IOCCONTAINER_H
#include <map>
#include "./IObject.h"
class IoCContainer {
    typedef IObject* (*OBJECT_CREATE_FUNC)(int type, IoCContainer *iocContainer, int newId);
 public:
    template <class T> void Register(OBJECT_CREATE_FUNC createFunc) {
        Register(T::TypeOf, createFunc);
    }
    void Register(int type, OBJECT_CREATE_FUNC createFunc);
    template<class T>
    T* Get() {
        return static_cast<T*>(Get(T::TypeOf));
    }
    IObject* Get(int type);
    void Delete(int index, int type);
    int GetNextId(int type);
 private:
    std::map<int, OBJECT_CREATE_FUNC> objectTypes;
    std::map<int, IObject*> objectContainer;  // index = type*2000 + id
};

#endif  // DMITRIJ_BAGAEV_MAIN_GAME_IOCCONTAINER_H
