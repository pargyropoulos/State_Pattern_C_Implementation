/* 
 * File:   state.h
 * Author: Panagiotis Argyropoulos - pargyropoulos@gmail.com
 */

#ifndef STATE_H
#define STATE_H
#include "events.h"

//--- State Interface ---
typedef struct State {
    void (*OnSoftwareEvent)(const struct State **CurrentState, menu_event_t event); 
    void (*OnHardwareEvent)(const struct State **CurrentState, button_t event); 
} state_t;

typedef struct {
    void (*handler)(void);
    const state_t *nextState;
} state_tbl_entry_t;

#endif /* STATE_H */

