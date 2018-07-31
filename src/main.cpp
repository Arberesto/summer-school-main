#include "./Game.h"
#include "./IoCContainer.h"
#include "./IObject.h"
class IObjectA : public IObject {
 public:
    explicit IObjectA() = default;
    int GetType() {
      return TypeOf;
    }
    int GetId() {
      return id;
    }

    void SetId(int newId) {
        id = newId;
    }

    bool IsA(int type) {
      return TypeOf == type;
    }
 private:
    int id = -1;
    static const int TypeOf = 1;
};

class A : public IObjectA {
 public:
    void A(int newId) {
        SetId(newId);
    }
    bool IsA(int type) override { return TypeOf == type || IObjectA::IsA(type); }
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
  container.Delete(pA->GetId(), pA->GetType());
  // delete pA;
  gameObject->gameLoop();
  return 0;
}