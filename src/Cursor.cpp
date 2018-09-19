#include "./Cursor.h"
#include <map>
#include <typeinfo>
#include <string>
#include "./IObject.h"
#include "./LevelManager.h"

Cursor::Cursor(int row, int col, int newId) {
    SetId(newId);
    SetRow(row);
    SetCol(col);
    SetType(typeid(Cursor).hash_code());
}
Cursor::~Cursor() {
}
int Cursor::GetId() {
    return id;
}

void Cursor::Delete() {
}

void Cursor::SetId(int newId) {
    id = newId;
}

size_t Cursor::GetType() {
    return type;
}

void Cursor::SetType(size_t newType) {
    type = newType;
}

int Cursor::GetRow() {
    return row;
}

void Cursor::SetRow(int newRow) {
    row = newRow;
}

int Cursor::GetCol() {
    return col;
}

void Cursor::SetCol(int newCol) {
    col = newCol;
}

bool Cursor::IsA(size_t type) {
    return typeid(Cursor).hash_code() == type;
}

IObject* Cursor::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Cursor(iocContainer->GetY<Cursor>(), iocContainer->GetX<Cursor>(),
                       newId);
}

void Cursor::changePosition(IoCContainer* container, int rowShift, int colShift) {
    if (rowShift + colShift != 0) {
        auto mapMaxRow = container->Get<LevelManager>(1)->getSizeRow();
        auto mapMaxCol = container->Get<LevelManager>(1)->getSizeCol();
        if (isCorrectCoordinates(GetRow() + rowShift - 1, GetCol() + colShift - 1,
                                 mapMaxRow, mapMaxCol)) {
            SetRow((GetRow() + rowShift));
            SetCol((GetCol() + colShift));
        }
    }
}

bool Cursor::isCorrectCoordinates(int cursorRow, int cursorCol, int levelSizeRow, int levelSizeCol) {
    int localRowSize = 0;
    int localColSize = 0;
    return ((cursorRow >= 0)&& (cursorCol >= 0) && (cursorRow + localRowSize <= levelSizeRow) &&
            (cursorCol +  localColSize <= levelSizeCol));
}