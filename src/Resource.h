#ifndef DMITRIJ_BAGAEV_MAIN_GAME_RESOURCE_H
#define DMITRIJ_BAGAEV_MAIN_GAME_RESOURCE_H
#include <string>
#include "./IoCContainer.h"
class Resource : public IObject{
 public:
    Resource() = default;
    int value = 0;
    std::string title;
    explicit Resource(int newId, std::string newTitle);
    int GetId();

    void Delete();

    void SetId(int newId);

    const char* GetTextField();

    void SetTextField(const char* newTextField);

    template<class T>
    bool IsA() {
        return IsA(typeid(T).hash_code());
    }
    bool IsA(size_t type);

    void SetValue(int newValue);

    int GetValue();
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_RESOURCE_H
