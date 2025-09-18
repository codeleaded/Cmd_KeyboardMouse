#include "/home/codeleaded/System/Static/Library/InputMouse.h"
#include "/home/codeleaded/System/Static/Library/InputKeyboard.h"
#include "/home/codeleaded/System/Static/Library/Thread.h"

int main() {
    
    InputKeyboard kbi = InputKeyboard_New();
    
    char runnning = 1;
    while(runnning){
        if(InputKeyboard_Get(&kbi,INPUTKEYBOARD_KEY_Q).PRESSED)
            runnning = 0;

        InputKeyboard_Update(&kbi);
        
        for(int i = 0;i<INPUTKEYBOARD_KEYS;i++){
            if(kbi.keys[i].PRESSED)     printf("P: %d\n",i);
            if(kbi.keys[i].RELEASED)    printf("R: %d\n",i);
        }

        Thread_Sleep_M(100);
    }
    InputKeyboard_Free(&kbi);
    runnning = 1;

    InputMouse mi = InputMouse_New(0,0);
    while(runnning){
        if(InputMouse_Get(&mi,INPUTMOUSE_BUTTON_L).PRESSED)
            runnning = 0;
        
        InputMouse_Update(&mi);
        
        for(int i = 0;i<INPUTMOUSE_BUTTONS;i++){
            if(mi.buttons[i].PRESSED)     printf("P: %d\n",i);
            if(mi.buttons[i].RELEASED)    printf("R: %d\n",i);
        }

        Thread_Sleep_M(100);
    }
    InputMouse_Free(&mi);

    return 0;
}
