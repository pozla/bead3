#include "widget.hpp"
#include "graphics.hpp"

using namespace genv;

Widget::Widget(int positionX_, int positionY_, int sizeX_, int sizeY_): positionX(positionX_), positionY(positionY_), sizeX(sizeX_), sizeY(sizeY_) {}

bool Widget::isSelected(int mouseX, int mouseY) {
    return (positionX <= mouseX && mouseX <= positionX+sizeX &&
            positionY <= mouseY && mouseY <= positionY+sizeY);
}

void Widget::drawTriangle(int positionX, int positionY, int size_, int direction, int r, int g, int b) {
    int sizeX = size_;
    int sizeY = (size_+1)/2;
    int n = sizeX;
    gout << color(r, g, b);
    // direction: 1=up, 2=left, 3=down, 4=right (left and right are not implemented atm)
    if (direction == 1) {
        for (int i=0; i<sizeY; i++) {
            for (int j=0; j<n; j++) { gout << move_to(positionX+i+j, positionY+sizeY-1-i) << dot; }
            n -= 2;
        }
    }
    if (direction == 3) {
        for (int i=0; i<sizeY; i++) {
            for (int j=0; j<n; j++) { gout << move_to(positionX+i+j, positionY+i) << dot; }
            n -= 2;
        }
    }
}
