#ifndef CHECKBOXWIDGET
#define CHECKBOXWIDGET

#include "widget.hpp"
#include "graphics.hpp"

class CheckBoxWidget: public Widget {
    private:
        int style;
        bool isChecked;
        void drawX(int, int, int);
    public:
        CheckBoxWidget(int, int, int, int);
        virtual void draw();
        virtual void handle(event ev);
};

#endif // CHECKBOXWIDGET
