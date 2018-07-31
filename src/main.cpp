#include "./Game.h"
#include "./IoCContainer.h"
#include "./IObject.h"
class IObjectA : public IObject {
 public:
    static const int TypeOf = 1;
    IObjectA() = default;

    explicit IObjectA(int newId) {
        SetId(newId);
    }

    int  GetType() {
      return TypeOf;
    }

    int GetId() {
      return id;
    }

    void Delete() {
    }

    void SetId(int newId) {
        id = newId;
    }

    bool IsA(int type) {
      return TypeOf == type;
    }

 private:
    int id;
};

class A : public IObjectA {
 public:
    int id = 0;
    explicit A(int newId) {
        SetId(newId);
    }

    bool IsA(int type) override {
        return TypeOf == type || IObjectA::IsA(type);
    }

    int GetId() override {
        return id;
    }

    void SetId(int newId) override {
        id = newId;
    }

    static IObject* Create(int type, IoCContainer *iocContainer, int newId) {
        return new A(newId);
    }

    void DoSomething() {
    }

 private:
    static const int TypeOf = 2;
};

int main() {
  auto *gameObject = new Game(0);
  IoCContainer container;
  container.Register<IObjectA>(&A::Create);
  auto pA = container.Get<IObjectA>();
  delete pA;
  // container.Delete(pA);
  gameObject->gameLoop();
  return 0;
}