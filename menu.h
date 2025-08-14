/* 
 * File:   menu.h
 * Author: Panagiotis Argyropoulos - pargyropoulos@gmail.com
 */

#ifndef MENU_H
#define MENU_H
#include <stdint.h>

typedef struct {
    const char *text;
    void (*menu_handler_on_entry)(void);
    void (*menu_handler_on_exit)(void);
} menu_item_t;

typedef struct {
    const menu_item_t *menu_tbl_ptr;
    uint8_t menu_items;
} menu_t;

typedef struct {
    uint8_t var;
    const uint8_t min;
    const uint8_t max;
} option_item_t;

typedef struct {
    option_item_t *option_tbl_ptr;
    uint8_t option_items;
    const char *text;
    char separator;
} option_t;

void MENU_MoveUp(void);
void MENU_MoveDown(void);
void MENU_Select(void);
void MENU_Esc(void);
void MENU_MoveLeft(void);
void MENU_MoveRight(void);
void MENU_SelectOption(void);
void MENU_EscOption(void);
void MENU_Add(void);
void MENU_Subtract(void);
void MENU_EditSelection(void);
void MENU_EscEdit(void);
void MENU_Navigate(void);
void MENU_Initialize(void);
#endif /* MENU_H */

