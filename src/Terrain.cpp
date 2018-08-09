#include "./Terrain.h"
#include <string>
#include <typeinfo>
#include "./IoCContainer.h"
#include "./IObject.h"
Terrain::Terrain(int row, int col, int newId, const char* symbol) {
    SetId(newId);
    SetTextField(symbol);
    SetRow(row);
    SetCol(col);
    SetType(typeid(Terrain).hash_code());
}

Terrain::~Terrain() {
    int temp = drawField[0][0];
    for (int i = 0; i < temp + 1; i++) {
        delete drawField[i];
    }
    delete drawField;
}

bool Terrain::IsA(size_t type) {
    return typeid(Terrain).hash_code() == type;
}

const char* Terrain::GetTextField() {
    return new char[1]{'.'};
}

void Terrain::SetTextField(const char* newTextField) {
}

int Terrain::GetTerrainSideSize() {
    return terrainSideSize;
}

void Terrain::SetTerrainSideSize(int newTerrainSideSize) {
    terrainSideSize = newTerrainSideSize;
}

void Terrain::Delete() {
}

char** Terrain::GenerateDrawField(char symbol) {
    auto newDrawField = new char*[GetTerrainSideSize() + 1];
    for (int i = 1; i < GetTerrainSideSize() + 1; i++) {
        newDrawField[i] = new char[GetTerrainSideSize()];
        for (int j = 0; j < GetTerrainSideSize(); j++) {
            newDrawField[i][j] = symbol;
        }
    }
    newDrawField[0] = new char[2];
    newDrawField[0][0] = static_cast<char>(GetTerrainSideSize());
    newDrawField[0][1] = static_cast<char>(GetTerrainSideSize());
    return newDrawField;
}

void Terrain::SetDrawField(char ** newDrawField) {
    drawField = new char*[newDrawField[0][0] + 1];
    for (int i = 1; i < newDrawField[0][0] + 1; i++) {
        drawField[i] = new char[newDrawField[0][1]];
        for (int j = 0; j < newDrawField[0][1]; j++) {
            drawField[i][j] = newDrawField[i][j];
        }
    }
    drawField[0] = new char[2];
    drawField[0][0] = newDrawField[0][0];
    drawField[0][1] = newDrawField[0][1];
}

char** Terrain::GetDrawField() {
    return drawField;
}

int Terrain::GetId() {
    return id;
}

void Terrain::SetId(int newId) {
    id = newId;
}

size_t Terrain::GetType() {
    return type;
}

void Terrain::SetType(size_t newType) {
    type = newType;
}

int Terrain::GetRow() {
    return row;
}

void Terrain::SetRow(int newRow) {
    row = newRow;
}

int Terrain::GetCol() {
    return col;
}

void Terrain::SetCol(int newCol) {
    col = newCol;
}