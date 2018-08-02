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
    void New() {
        New(T::typeOf);
    }
    void New(int type);
    template<class T>
    T* Get(int id) {
        return dynamic_cast<T*>(Get((T::typeOf) * 100 + id));
    }
    IObject* Get(int inGdex);

    void Delete(IObject* object);
    int GetNextId(int type);
    ~IoCContainer();

 private:
    std::map<int, OBJECT_CREATE_FUNC> objectTypes;
    std::map<int, IObject*> objectContainer;  // index = type*100 + id
};

#endif  // DMITRIJ_BAGAEV_MAIN_GAME_IOCCONTAINER_H
