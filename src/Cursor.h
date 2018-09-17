#ifndef DMITRIJ_BAGAEV_MAIN_GAME_CURSOR_H
#define DMITRIJ_BAGAEV_MAIN_GAME_CURSOR_H
#include <map>
#include <typeinfo>
#include <string>
#include "./IoCContainer.h"
#include "./IObject.h"
class Cursor : public IObject{
 protected:
    int col;
    int row;

 public:
    Cursor() = default;

    explicit Cursor(int row, int col, int newId);

    ~Cursor();

    int GetRow();

    void SetRow(int newRow);

    int GetCol();

    void SetCol(int newCol);

    int GetId();

    void SetId(int newId);

    size_t GetType();

    void SetType(size_t newType);

    void Delete();

    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type);

    void changePosition(IoCContainer* container, int rowShift, int colShift);
    bool isCorrectCoordinates(int cursorRow, int cursorCol, int levelSizeRow, int levelSizeCol);

    static IObject* Create(size_t type, IoCContainer *iocContainer, int newId);
};
#endif
