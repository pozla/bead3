#include "widget.hpp"
#include "checkboxwidget.hpp"
#include "graphics.hpp"
#include <vector>
#include <string>
#include <fstream>

using namespace genv;
using namespace std;

void gameEngine(vector<CheckBoxWidget*> &widgetVector) {
    gout.open(600, 600);
    gout << color(100, 100, 100) << move_to(49, 49) << box(502, 502);
    event ev;
    int active = -1;
    while (gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_mouse) {
            if (ev.button == btn_left || ev.button == btn_right) {
                for (size_t i=0; i<widgetVector.size(); i++) {
                    if (widgetVector[i]->isSelected(ev.pos_x, ev.pos_y)) {
                        active = i;
                    }
                }
            }
        }
        if (active != -1) widgetVector[active]->handle(ev);
        for (Widget *w: widgetVector) w->draw();
        gout << refresh;
    }
}

int main() {
    vector<CheckBoxWidget*> widgetVector(400);
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            widgetVector[20*i+j] = new CheckBoxWidget(50+25*j, 50+25*i, 25, 25);
        }
    }
    gameEngine(widgetVector);
    return 0;
}
