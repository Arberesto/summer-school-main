#include "./Mountain.h"
#include <string>
#include "./Terrain.h"
Mountain::Mountain(int row, int col, int newId, const char* symbol) : Terrain(row, col, newId, symbol) {
    SetType(typeid(Mountain).hash_code());
    SetTerrainSideSize(1);
    SetDrawField(GenerateDrawField('#'));
}

bool Mountain::IsA(size_t type) {
    return typeid(Mountain).hash_code() == type || Terrain::IsA(type);
}

IObject* Mountain::Create(size_t type, IoCContainer *iocContainer, int newId) {
    return new Mountain(iocContainer->GetY<Mountain>(), iocContainer->GetX<Mountain>(),
                     newId, std::string("Mountain").c_str());
}
