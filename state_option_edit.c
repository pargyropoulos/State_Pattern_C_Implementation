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
        {MENU_Add,          &State_Option_Edit},    //BTN_UP
        {MENU_Subtract,     &State_Option_Edit},    //BTN_DOWN
        {MENU_EditSelection,&State_Option_Nav},     //BTN_SELECT
        {MENU_EscEdit,      &State_Option_Nav}      //BTN_ESC
    };
    
    *CurrentState=tbl[event].nextState;
    if (tbl[event].handler) tbl[event].handler();    
} 

const state_t State_Option_Edit = {
    .OnSoftwareEvent=&OnSoftwareEvent,
    .OnHardwareEvent=&OnHardwareEvent
};
