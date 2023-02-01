#include "UIMain.h"

std::string clipboard = "";

Keyboard kb;


Macro layout1[5][6] = {
    {Macro({KEY_ESC}),          Macro({'/'}), Macro({'*'}), Macro({'-'}),           Macro({KEY_LEFT_GUI, 'a'}, "CMD+A"), Macro({KEY_LEFT_GUI, 'r'}, "CMD+R")},
    {Macro({'7'}),              Macro({'8'}), Macro({'9'}), Macro({'+'}),           Macro({KEY_LEFT_GUI, 'c'}, "COPY"),  Macro({KEY_LEFT_GUI, 'v'}, "PASTE")},
    {Macro({'4'}),              Macro({'5'}), Macro({'6'}), Macro({'^'}),           Macro({KEY_LEFT_GUI, 'x'}, "CUT"),   Macro({KEY_LEFT_GUI, 's'}, "SAVE")},
    {Macro({'1'}),              Macro({'2'}), Macro({'3'}), Macro({KEY_RETURN}),    Macro({KEY_LEFT_GUI, 'h'}, "HIDE"),  Macro({KEY_LEFT_GUI, 'n'}, "NEW")},
    {Macro({KEY_LAYER_SWITCH}), Macro({'0'}), Macro({'.'}), Macro({KEY_BACKSPACE}), Macro({'8'}),                        Macro({'8'})}
};

Macro layout2[5][6] = {
    {Macro({KEY_ESC}),          Macro({'/'}),            Macro({'*'}),             Macro({'-'}),           Macro({KEY_LEFT_GUI, 'a'}, "CMD+A"), Macro({KEY_LEFT_GUI, 'r'}, "CMD+R")},
    {Macro({'7'}),              Macro({KEY_UP_ARROW}),   Macro({'9'}),             Macro({'+'}),           Macro({KEY_LEFT_GUI, 'c'}, "COPY"),  Macro({KEY_LEFT_GUI, 'v'}, "PASTE")},
    {Macro({KEY_LEFT_ARROW}),   Macro({'5'}),            Macro({KEY_RIGHT_ARROW}), Macro({'^'}),           Macro({KEY_LEFT_GUI, 'x'}, "CUT"),   Macro({KEY_LEFT_GUI, 's'}, "SAVE")},
    {Macro({'1'}),              Macro({KEY_DOWN_ARROW}), Macro({'3'}),             Macro({KEY_RETURN}),    Macro({KEY_LEFT_GUI, 'h'}, "HIDE"),  Macro({KEY_LEFT_GUI, 'n'}, "NEW")},
    {Macro({KEY_LAYER_SWITCH}), Macro({'0'}),            Macro({'.'}),             Macro({KEY_BACKSPACE}), Macro({'8'}),                        Macro({'8'})}
};

MacroPad macroPad({ 
    Layout("standard", layout1),
    Layout("layout 2", layout2)
});

MacropadUI macropadUI(&macroPad);



 
Macro layout3[5][6] = {
    {Macro({KEY_ESC}),          Macro({'/'}), Macro({'*'}), Macro({'-'}),           Macro({KEY_SIN}), Macro({KEY_SEC})},
    {Macro({'7'}),              Macro({'8'}), Macro({'9'}), Macro({'+'}),           Macro({KEY_COS}), Macro({KEY_CSC})},
    {Macro({'4'}),              Macro({'5'}), Macro({'6'}), Macro({'^'}),           Macro({KEY_TAN}), Macro({KEY_COT})},
    {Macro({'1'}),              Macro({'2'}), Macro({'3'}), Macro({KEY_RETURN}),    Macro({KEY_EXP}), Macro({'x'})},
    {Macro({KEY_LAYER_SWITCH}), Macro({'0'}), Macro({'.'}), Macro({KEY_BACKSPACE}), Macro({'('}),     Macro({KEY_TAB})}
};

Macro layout4[5][6] = { 
    {Macro({KEY_ESC}),          Macro({'('}),            Macro({')'}),             Macro({'-'}),           Macro({KEY_ASIN}), Macro({KEY_SEC})},
    {Macro({'7'}),              Macro({KEY_UP_ARROW}),   Macro({'9'}),             Macro({'+'}),           Macro({KEY_ACOS}), Macro({KEY_CSC})},
    {Macro({KEY_LEFT_ARROW}),   Macro({'5'}),            Macro({KEY_RIGHT_ARROW}), Macro({KEY_SQRT}),      Macro({KEY_ATAN}), Macro({KEY_COT})},
    {Macro({'1'}),              Macro({KEY_DOWN_ARROW}), Macro({'3'}),             Macro({KEY_RETURN}),    Macro({KEY_LN}),   Macro({'y'})},
    {Macro({KEY_LAYER_SWITCH}), Macro({'0'}),            Macro({'.'}),             Macro({KEY_BACKSPACE}), Macro({'('}),      Macro({KEY_TAB})}
};

InputBox inputBox(0, 0, 100, 12, 15);
Menu calcMenu(0, 0, 220, 48, 3);
InputBox expressionInput(0, 57, 220, 12, 48);

MacroPad calcLayout({
    Layout("1", layout3),
    Layout("2", layout4)
});

Menu menuSpecs(0, 0, 256, 64, 5, {
    new Text("Powered by an ESP32 WROOM-32E"), 
    new Text("Kailh choc switches"), 
    new Text("Designed by SHAO")
},
{
    nullptr,
    nullptr,
    nullptr
});

Menu menuSettings(0, 0, 256, 64, 5, {
    new Text("Nothing"), 
    new Text("To see"), 
    new Text("here.")
},
{
    nullptr,
    nullptr,
    nullptr
});

Menu menuMisc(0, 0, 256, 64, 5, {
    &inputBox,
    new Text("THOCC."), 
    new Text("CLACK.")
},
{
    &inputBox, 
    nullptr, 
    nullptr
});

Calculator calcMain(0, 0, 220, 64, &calcMenu, &expressionInput);

Menu menu(0, 0, 70, 64, 4, {
    new Text("Calculator"), 
    new Text("Macropad"), 
    new Text("Games"), 
    new Text("Misc"), 
    new Text("Debug"), 
    new Text("Specs"), 
    new Text("Settings")
},
{
    &calcMain, 
    &macropadUI, 
    nullptr, 
    &menuMisc, 
    nullptr, 
    &menuSpecs, 
    &menuSettings
});


UIElement* currentElement = &menu;

