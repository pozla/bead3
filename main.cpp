#include "widget.hpp"
#include "graphics.hpp"
#include <vector>
#include <string>
#include <fstream>

using namespace genv;
using namespace std;

ofstream output("output.txt");

void eventLoop(vector<Widget*> &widgetVector) {
    event ev;
    int active = -1;
    while (gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_mouse) {
            if (ev.button == btn_left) {
                for (size_t i=0; i<widgetVector.size(); i++) {
                    if (widgetVector[i]->isSelected(ev.pos_x, ev.pos_y)) active = i;
                }
            }
        }
        if (active != -1) widgetVector[active]->handle(ev);
        for (Widget *w: widgetVector) w->draw();
        if (ev.type == ev_key)
            if (ev.keycode == key_enter) {
                for (Widget *w: widgetVector) output << w->getValue() << endl;
                output << endl;
            }
        gout << refresh;
    }
}

int main() {
    gout.open(600,200);
    vector<Widget*> widgetVector;
    for(Widget *w: widgetVector) { w->draw(); }
    gout << refresh;
    eventLoop(widgetVector);
    return 0;
}
