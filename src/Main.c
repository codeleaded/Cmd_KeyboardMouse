#include "/home/codeleaded/System/Static/Library/InputMouse.h"
#include "/home/codeleaded/System/Static/Library/InputKeyboard.h"

int main() {
    
    InputKeyboard kbi = InputKeyboard_New();
    while(1){
        InputKeyboard_Update(&kbi);
        
        for(int i = 0;i<INPUTKEYBOARD_KEYS;i++){
            if(kbi.keys[i].PRESSED)     printf("P: %d\n",i);
            if(kbi.keys[i].RELEASED)    printf("R: %d\n",i);
        }
    }
    InputKeyboard_Free(&kbi);
    

    InputMouse mi = InputMouse_New(0,0);
    while(1){
        InputMouse_Update(&mi);
        
        for(int i = 0;i<INPUTMOUSE_BUTTONS;i++){
            if(mi.buttons[i].PRESSED)     printf("P: %d\n",i);
            if(mi.buttons[i].RELEASED)    printf("R: %d\n",i);
        }
    }
    InputMouse_Free(&mi);

    return 0;
}
