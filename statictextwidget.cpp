#include "statictextwidget.hpp"
#include "graphics.hpp"
#include <string>

using namespace genv;
using namespace std;

StaticTextWidget::StaticTextWidget(int positionX_, int positionY_, int sizeX_, int sizeY_, int br_, int bg_, int bb_, int r_, int g_, int b_, string txt_): Widget(positionX_, positionY_, sizeX_, sizeY_) {
    br = br_;
    bg = bg_;
    bb = bb_;
    r = r_;
    g = g_;
    b = b_;
    txt = txt_;
}

void StaticTextWidget::draw() {
    gout << move_to(positionX, positionY) << color(br, bg, bb) << box(sizeX, sizeY) << move_to(positionX, positionY) << color(r, g, b) << text(txt);
}

void StaticTextWidget::handle(event ev) {}
