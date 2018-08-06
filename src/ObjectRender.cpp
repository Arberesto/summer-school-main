#include "./ObjectRender.h"
#include "./House.h"
#include "./ncurses.h"
void ObjectRender::Render(IoCContainer * container) {
    mvaddch(4, 4, (container->Get<House>(1)->GetTextField()[0]));
}
