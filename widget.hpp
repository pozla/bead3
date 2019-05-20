#ifndef WIDGETS_HPP
#define WIDGETS_HPP

#include "graphics.hpp"
#include <string>

using namespace genv;
using namespace std;

class Widget {
    protected:
        int positionX, positionY;
        int sizeX, sizeY;
        void drawTriangle(int, int, int, int, int, int, int);
    public:
        Widget(int, int, int ,int);
        virtual void draw() = 0;
        virtual bool isSelected(int, int);
        virtual void handle(event ev) = 0;
};

#endif // WIDGETS_HPP
