#include "./ObjectRender.h"
#include "./IoCContainer.h"
#include "./ncurses.h"
void ObjectRender::Render(IoCContainer * container) {
    mvaddch(4, 4, (container->Get(11 * 100 + 1)->GetSymbol()));
}
