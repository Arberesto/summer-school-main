#include "./Plane.h"
#include <string>
#include "./Terrain.h"
Plane::Plane(int row, int col, int newId, const char* symbol) : Terrain(row, col, newId, symbol) {
    SetType(typeid(Plane).hash_code());
    SetTerrainSideSize(1);
    SetDrawField(GenerateDrawField('.'));
}

bool Plane::IsA(size_t type) {
    return typeid(Plane).hash_code() == type || Terrain::IsA(type);
}

IObject* Plane::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Plane(iocContainer->GetY<Plane>(), iocContainer->GetX<Plane>(),
                     newId, std::string("Plane").c_str());
}
