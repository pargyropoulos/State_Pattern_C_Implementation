/* 
 * State Pattern Implementation for Menu Navigation
 * Author: Panagiotis Argyropoulos - pargyropoulos@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "events.h"
#include "menu.h"
#include "fsm.h"

//--- NON Blocking Button Handler ---//
void GetButton(void) {
    if (_kbhit()) {
        char ch = _getch();
        ch = toupper(ch);
        switch (ch) {
            case 'Q': RaiseButtonEvent(BTN_UP);return;
            case 'W': RaiseButtonEvent(BTN_DOWN);return;
            case 'E': RaiseButtonEvent(BTN_SELECT);return;
            case 'R': RaiseButtonEvent(BTN_ESC);return;
            default: return;
        }
    }
}

int main(void) {
    MENU_Initialize();
    
    while (1) {
        GetButton();
        
        button_t btn_event = GetButtonEvent();
        if (btn_event!=BTN_NONE){
            ClearButtonEvent();
            FSM_OnHardwareEvent(btn_event);
        }
        
        menu_event_t menu_event= GetMenuEvent();
        if (menu_event!=MENU_EVENT_NONE){
            ClearMenuEvent();
            FSM_OnSoftwareEvent(menu_event);
        }
        
    }  
    return (EXIT_SUCCESS);
}

