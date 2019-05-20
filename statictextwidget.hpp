#ifndef STATICTEXTWIDGET
#define STATICTEXTWIDGET

#include "widget.hpp"
#include "graphics.hpp"
#include <string>

class StaticTextWidget: public Widget {
    private:
        int br, bg, bb;
        int r, g, b;
        string txt;
    public:
        StaticTextWidget(int, int, int, int, int, int, int, int, int, int, string);
        virtual void draw();
        virtual void handle(event ev);
};

#endif // STATICTEXTWIDGET
