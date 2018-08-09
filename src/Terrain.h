#ifndef DMITRIJ_BAGAEV_MAIN_GAME_TERRAIN_H
#define DMITRIJ_BAGAEV_MAIN_GAME_TERRAIN_H
#include "./IoCContainer.h"
class Terrain : public IObject{
 protected:
    int row;
    int col;
    char ** drawField;  // первая строка: sizeRow,SizeCol; остальные - сам массив символов
    int terrainSideSize = 1;

 public:
    Terrain() = default;
    explicit Terrain(int row, int col, int newId, const char* symbol);
    ~Terrain();

    void SetDrawField(char ** newDrawField);

    char** GetDrawField();

    void SetTerrainSideSize(int newTerrainSideSize);

    int GetTerrainSideSize();

    char** GenerateDrawField(char symbol);

    int GetId();

    void SetId(int newId);

    size_t GetType();

    void SetType(size_t newType);

    int GetRow();

    void SetRow(int newRow);

    int GetCol();

    void SetCol(int newCol);

    const char* GetTextField();

    void SetTextField(const char* newTextField);

    void Delete();

    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_TERRAIN_H
