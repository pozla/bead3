#include "widget.hpp"
#include "checkboxwidget.hpp"
#include "graphics.hpp"
#include <vector>
#include <string>
#include <fstream>

using namespace genv;
using namespace std;

class Rules {
    public:
        bool horizontalCheck(int gameData[20][20]) {
            for (int i=0; i<20; i++) {
                for (int j=0; j<16; j++) {
                    if ((gameData[i][j] == 1) && (gameData[i][j+1] == 1) && (gameData[i][j+2] == 1) && (gameData[i][j+3] == 1) && (gameData[i][j+4] == 1) ||
                        (gameData[i][j] == 2) && (gameData[i][j+1] == 2) && (gameData[i][j+2] == 2) && (gameData[i][j+3] == 2) && (gameData[i][j+4] == 2)) return true;
                }
            }
            return false;
        }
        bool verticalCheck(int gameData[20][20]) {
            for (int i=0; i<16; i++) {
                for (int j=0; j<20; j++) {
                    if ((gameData[i][j] == 1) && (gameData[i+1][j] == 1) && (gameData[i+2][j] == 1) && (gameData[i+3][j] == 1) && (gameData[i+4][j] == 1) ||
                        (gameData[i][j] == 2) && (gameData[i+1][j] == 2) && (gameData[i+2][j] == 2) && (gameData[i+3][j] == 2) && (gameData[i+4][j] == 2)) return true;
                }
            }
            return false;
        }
        bool diagonalCheck1(int gameData[20][20]) {
            for (int i=0; i<16; i++) {
                for (int j=0; j<16; j++) {
                    if ((gameData[i][j] == 1) && (gameData[i+1][j+1] == 1) && (gameData[i+2][j+2] == 1) && (gameData[i+3][j+3] == 1) && (gameData[i+4][j+4] == 1) ||
                        (gameData[i][j] == 2) && (gameData[i+1][j+1] == 2) && (gameData[i+2][j+2] == 2) && (gameData[i+3][j+3] == 2) && (gameData[i+4][j+4] == 2)) return true;
                }
            }
            return false;
        }
        bool diagonalCheck2(int gameData[20][20]) {
            for (int i=0; i<16; i++) {
                for (int j=4; j<20; j++) {
                    if ((gameData[i][j] == 1) && (gameData[i+1][j-1] == 1) && (gameData[i+2][j-2] == 1) && (gameData[i+3][j-3] == 1) && (gameData[i+4][j-4] == 1) ||
                        (gameData[i][j] == 2) && (gameData[i+1][j-1] == 2) && (gameData[i+2][j-2] == 2) && (gameData[i+3][j-3] == 2) && (gameData[i+4][j-4] == 2)) return true;
                }
            }
            return false;
        }
};

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
                    }
                }
            }
            if (ev.button == btn_right) {
                for (size_t i=0; i<widgetVector.size(); i++) {
                    if (widgetVector[i]->isSelected(ev.pos_x, ev.pos_y)) {
                        active = i;
                        gameData[active/20][active%20] = 2;
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
