/* 
 * File:   events.h
 * Author: Panagiotis Argyropoulos - pargyropoulos@gmail.com
 */

#ifndef EVENTS_H
#define EVENTS_H

typedef enum {
    BTN_UP,
    BTN_DOWN,
    BTN_SELECT,
    BTN_ESC,
    BTN_COUNT,
    BTN_NONE
} button_t;

typedef enum {
    MENU_EVENT_SPECIAL_NAV,
    MENU_EVENT_STANDARD_NAV,
    MENU_EVENT_COUNT,
    MENU_EVENT_NONE
} menu_event_t;

void RaiseMenuEvent(menu_event_t event);
void RaiseButtonEvent(button_t event);
button_t GetButtonEvent(void);
menu_event_t GetMenuEvent(void);
void ClearButtonEvent(void);
void ClearMenuEvent(void);

#endif /* EVENTS_H */

