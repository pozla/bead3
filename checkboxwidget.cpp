#include "checkboxwidget.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;

CheckBoxWidget::CheckBoxWidget(int positionX_, int positionY_, int sizeX_, int sizeY_): Widget(positionX_, positionY_, sizeX_, sizeY_) {
    style = 0; //default
    isChecked = false;
}

void CheckBoxWidget::drawX(int r, int g, int b) {
    gout << color(r, g, b);
    gout << move_to(positionX+3, positionY+4) << line_to(positionX+sizeX-4, positionY+sizeY-3);
    gout << move_to(positionX+3, positionY+3) << line_to(positionX+sizeX-3, positionY+sizeY-3);
    gout << move_to(positionX+4, positionY+3) << line_to(positionX+sizeX-3, positionY+sizeY-4);
    gout << move_to(positionX+3, positionY+sizeY-4) << line_to(positionX+sizeX-4, positionY+3);
    gout << move_to(positionX+3, positionY+sizeY-3) << line_to(positionX+sizeX-3, positionY+3);
    gout << move_to(positionX+4, positionY+sizeY-3) << line_to(positionX+sizeX-3, positionY+4);
}

void CheckBoxWidget::draw() {
    gout << move_to(positionX, positionY) << color(100, 100, 100) << box(sizeX, sizeY);
    gout << move_to(positionX+1, positionY+1) << color(0, 0, 0) << box(sizeX-2, sizeY-2);
    if (isChecked == true) {
        if (style == 1) drawX(255, 0, 0);
        if (style == 2) drawX(0, 0, 255);
    }
}

void CheckBoxWidget::handle(event ev) {
    if (isChecked == false && ev.type == ev_mouse && ev.button == btn_left && isSelected(ev.pos_x, ev.pos_y)) { isChecked = !isChecked; style = 1; }
    if (isChecked == false && ev.type == ev_mouse && ev.button == btn_right && isSelected(ev.pos_x, ev.pos_y)) { isChecked = !isChecked; style = 2; }
}
