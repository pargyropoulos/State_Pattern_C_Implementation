#include <stdint.h>
#include <stddef.h>
#include "events.h"
#include "state.h"
#include "states.h"
#include "menu.h"

static void OnSoftwareEvent(const state_t **CurrentState, menu_event_t event){
    static const state_tbl_entry_t tbl[MENU_EVENT_COUNT] = {
        [MENU_EVENT_SPECIAL_NAV]  =   {NULL,      &State_Special_Nav},
        [MENU_EVENT_STANDARD_NAV] =   {NULL,      &State_Standard_Nav}   
    }; 
    
    *CurrentState=tbl[event].nextState;
    if (tbl[event].handler) tbl[event].handler();
}

static void OnHardwareEvent(const state_t **CurrentState, button_t event){
    static const state_tbl_entry_t tbl[BTN_COUNT] = {
        {MENU_MoveLeft,     &State_Option_Nav},     //BTN_UP
        {MENU_MoveRight,    &State_Option_Nav},     //BTN_DOWN
        {MENU_SelectOption, &State_Option_Edit},    //BTN_SELECT
        {MENU_EscOption,    &State_Standard_Nav}    //BTN_ESC    
    };
    
    *CurrentState=tbl[event].nextState;
    if (tbl[event].handler) tbl[event].handler();    
} 

const state_t State_Option_Nav = {
    .OnSoftwareEvent=&OnSoftwareEvent,
    .OnHardwareEvent=&OnHardwareEvent
};
