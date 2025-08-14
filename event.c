#include "events.h"
static button_t hw_event=BTN_NONE;
static menu_event_t sw_event=MENU_EVENT_NONE;

void RaiseMenuEvent(menu_event_t event){
    sw_event=event;
}

void RaiseButtonEvent(button_t event){
    hw_event=event;
}

void ClearButtonEvent(void){
    hw_event= BTN_NONE;
}

void ClearMenuEvent(void){
    sw_event= MENU_EVENT_NONE;
}

button_t GetButtonEvent(void){
    return hw_event;
}

menu_event_t GetMenuEvent(void){
    return sw_event;
}