#include "./Game.h"
int main() {
  auto *gameObject = new Game(0);
  gameObject->gameLoop();
  return 0;
}