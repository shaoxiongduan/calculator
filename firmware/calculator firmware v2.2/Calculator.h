#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Animation.h"
#include "Text.h"
#include "Menu.h"
#include "Cursor.h"
#include "Box.h"
#include "InputBox.h"
#include "ExpressionBlock.h"
//this is only for testing, the final product will be very different to this

class Calculator : public UIElement {
    public:
        Calculator(int x, int y, int width, int height, Menu* calcMenu, InputBox* expressionInput);
        
        void init();
        void insertExpression();
        void activate();

        void enter();

        void draw();

        void update();

    private:
        Menu* calcMenu;
        InputBox* expressionInput;
        bool mode; //0: input mode 1: navigate mode
};

#endif