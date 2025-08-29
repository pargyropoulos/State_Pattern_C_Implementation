/* 
 * File:   fsm.h
 * Author: Panagiotis Argyropoulos - pargyropoulos@gmail.com
 */

#ifndef FSM_H
#define FSM_H

#include "events.h"

void FSM_OnSoftwareEvent(menu_event_t event); 
void FSM_OnHardwareEvent(button_t event); 


#endif /* FSM_H */

