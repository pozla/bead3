#include "widget.hpp"
#include "checkboxwidget.hpp"
#include "graphics.hpp"
#include "rules.hpp"
#include "statictextwidget.hpp"
#include <vector>
#include <string>

#include <iostream>

using namespace genv;
using namespace std;

void gameEngine(vector<CheckBoxWidget*> &widgetVector) {
    Rules rules;
    int gameData[20][20];
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) gameData[i][j] = 0;
    }
    gout.open(600, 600);
    gout << color(100, 100, 100) << move_to(49, 49) << box(502, 502);
    event ev;
    int active = -1;
    while (gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_mouse) {
            if (ev.button == btn_left) {
                for (size_t i=0; i<widgetVector.size(); i++) {
                    if (widgetVector[i]->isSelected(ev.pos_x, ev.pos_y)) {
                        active = i;
                        gameData[active/20][active%20] = 1;
                        if (rules.horizontalCheck(gameData) || rules.verticalCheck(gameData) || rules.diagonalCheck1(gameData) || rules.diagonalCheck2(gameData)) cout << "Player 1 won!" << endl;
                        if (rules.fullCheck(gameData)) cout << "It's a draw!" << endl;
                    }
                }
            }
            if (ev.button == btn_right) {
                for (size_t i=0; i<widgetVector.size(); i++) {
                    if (widgetVector[i]->isSelected(ev.pos_x, ev.pos_y)) {
                        active = i;
                        gameData[active/20][active%20] = 2;
                        if (rules.horizontalCheck(gameData) || rules.verticalCheck(gameData) || rules.diagonalCheck1(gameData) || rules.diagonalCheck2(gameData)) cout << "Player 2 won!" << endl;
                        if (rules.fullCheck(gameData)) cout << "It's a draw!" << endl;
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
