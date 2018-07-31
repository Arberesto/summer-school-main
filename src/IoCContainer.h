#ifndef DMITRIJ_BAGAEV_MAIN_GAME_IOCCONTAINER_H
#define DMITRIJ_BAGAEV_MAIN_GAME_IOCCONTAINER_H
#include <map>
#include "./IObject.h"
class IoCContainer {
    typedef IObject* (*OBJECT_CREATE_FUNC)(int type, IoCContainer *iocContainer, int newId);
 public:
    explicit IoCContainer();
    template <class T> void Register(OBJECT_CREATE_FUNC createFunc) {
        Register(T::typeOf, createFunc);
    }
    void Register(int type, OBJECT_CREATE_FUNC createFunc);
    template<class T>
    T* Get() {
        return dynamic_cast<T*>(Get(T::typeOf));
    }
    IObject* Get(int type);
    void Delete(IObject* object);
    int GetNextId(int type);
    ~IoCContainer();
 private:
    std::map<int, OBJECT_CREATE_FUNC> objectTypes;
    std::map<int, IObject*> objectContainer;  // index = type*2000 + id
};

#endif  // DMITRIJ_BAGAEV_MAIN_GAME_IOCCONTAINER_H
