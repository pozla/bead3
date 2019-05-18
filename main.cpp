#include "widget.hpp"
#include "setnumberwidget.hpp"
#include "chooselistwidget.hpp"
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
    SetNumberWidget *snw1 = new SetNumberWidget(25, 50, 75, gout.cascent()+gout.cdescent(), -25, 25);
    SetNumberWidget *snw2 = new SetNumberWidget(25, 125, 100, gout.cascent()+gout.cdescent(), -50, 50);
    vector<string> options1 {"Red", "Green", "Blue"};
    vector<string> options2 {"Cyan", "Magenta", "Yellow", "Black", "Purple", "Orange", "White"};
    ChooseListWidget *clw1 = new ChooseListWidget(200, 25, 75, 3*(gout.cascent()+gout.cdescent()), options1);
    ChooseListWidget *clw2 = new ChooseListWidget(400, 25, 100, 5*(gout.cascent()+gout.cdescent()), options2);
    widgetVector.push_back(snw1);
    widgetVector.push_back(snw2);
    widgetVector.push_back(clw1);
    widgetVector.push_back(clw2);
    for(Widget *w: widgetVector) { w->draw(); }
    gout << refresh;
    eventLoop(widgetVector);
    return 0;
}
