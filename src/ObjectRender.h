#ifndef DMITRIJ_BAGAEV_MAIN_GAME_OBJECTRENDER_H
#define DMITRIJ_BAGAEV_MAIN_GAME_OBJECTRENDER_H
#include "./IoCContainer.h"
class ObjectRender {
 public:
    explicit ObjectRender() = default;
    void Render(IoCContainer * container);
};
#endif  // DMITRIJ_BAGAEV_MAIN_GAME_OBJECTRENDER_H
