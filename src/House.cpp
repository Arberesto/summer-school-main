#include "./House.h"
#include "./IoCContainer.h"
House::House(int newId) {
    SetId(newId);
    SetSymbol('^');
    SetType(11);
}

bool House::IsA(int type) {
return typeOf == type || Building::IsA(type);
}

int House::GetId() {
return id;
}

void House::SetId(int newId) {
id = newId;
}

IObject* House::Create(int type, IoCContainer *iocContainer, int newId) {
    return new House(newId);
}
