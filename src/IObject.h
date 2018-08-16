#ifndef DMITRIJ_BAGAEV_MAIN_GAME_IOBJECT_H
#define DMITRIJ_BAGAEV_MAIN_GAME_IOBJECT_H
#include <typeinfo>
class IObject {
 protected:
    int id;
    size_t type;
 public:
    virtual int GetId()  = 0;
    virtual void SetId(int newId) = 0;
    virtual void SetType(size_t newType) = 0;
    virtual size_t GetType() = 0;
    virtual bool IsA(size_t type) = 0;
    virtual void Delete() = 0;
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_IOBJECT_H