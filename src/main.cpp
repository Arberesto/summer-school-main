#include "./Game.h"
int main() {
  auto *gameObject = new Game(0);
//  IoCContainer container;
//  container.Register<A>(&A::Create);
//  auto pA = container.Get<IObjectA>();
//  // delete pA;
//  container.Delete(pA);
  gameObject->gameLoop();
  return 0;
}