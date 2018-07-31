#ifndef DMITRIJ_BAGAEV_MAIN_GAME_IOBJECT_H
#define DMITRIJ_BAGAEV_MAIN_GAME_IOBJECT_H
class IObject {
 public:
    static const int typeOf = 0;
    virtual int GetType() = 0;
    virtual int GetId()  = 0;
    virtual void SetId(int newId) = 0;
    virtual bool IsA(int type)  = 0;
    virtual void Delete() = 0;
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_IOBJECT_H