#include <stdint.h>
#include "states.h"
#include "fsm.h"

typedef struct{
    const state_t *currentState;
} context_t;

//initialize Context to point to a State
static context_t Context= {
    .currentState=&State_Standard_Nav
};

void FSM_OnSoftwareEvent(menu_event_t event){
    Context.currentState->OnSoftwareEvent(&Context.currentState,event);
}; 

void FSM_OnHardwareEvent(button_t event){
    Context.currentState->OnHardwareEvent(&Context.currentState,event);
}; 
