#ifndef UIMAIN_H
#define UIMAIN_H

#include "Util.h"
#include "Text.h"
#include "Menu.h"
#include "Cursor.h"
#include "Box.h"
#include "InputBox.h"
#include "ExpressionBlock.h"
#include "Calculator.h"
#include "Macropad.h"
#include "MacropadUI.h"
#include "Keyboard.h"

extern std::string clipboard;
extern Keyboard kb;

extern Macro layout1[5][6];
extern Macro layout2[5][6];
extern Macro layout3[5][6];
extern Macro layout4[5][6];
extern MacroPad macroPad;
extern MacroPad calcLayout;
extern MacropadUI macropadUI;

extern Menu menu;


#endif