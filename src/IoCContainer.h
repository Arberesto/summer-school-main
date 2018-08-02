#ifndef DMITRIJ_BAGAEV_MAIN_GAME_IOCCONTAINER_H
#define DMITRIJ_BAGAEV_MAIN_GAME_IOCCONTAINER_H
#include <map>
#include <typeinfo>
#include "./IObject.h"
class IoCContainer {
    typedef IObject* (*OBJECT_CREATE_FUNC)(size_t type, IoCContainer *iocContainer, int newId);

 public:
    explicit IoCContainer();
    template <class T> void Register(OBJECT_CREATE_FUNC createFunc) {
        Register(typeid(T).hash_code(), createFunc);
    }
    void Register(size_t type, OBJECT_CREATE_FUNC createFunc);
    template<class T>
    void New() {
        New(typeid(T).hash_code());
    }
    void New(size_t type);
    template<class T>
    T* Get(int id) {
        // return Get(id, typeid(T).hash_code());
        return static_cast<T*>(Get(id, typeid(T).hash_code()));
    }
    IObject* Get(int id, size_t type);

    void Delete(IObject* object);
    int GetNextId(size_t type);
    ~IoCContainer();

 private:
    std::map<size_t, OBJECT_CREATE_FUNC> objectTypes;
    std::map<size_t, IObject*> objectContainer;  // index = type + id
    const int TYPE_MULTIPLIER = 100;
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_IOCCONTAINER_H