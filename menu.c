#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "events.h"
#include "menu.h"
#include "fsm.h"

#define ARRAY_SIZE(arr)  (sizeof(arr) / sizeof((arr)[0]))

//---Globals---
static uint8_t v_index = 0;
static uint8_t h_index = 0;
static option_t active_options;
static menu_t active_menu;

//---Function Prototypes---
static void Clock(void);
static void Date(void);
static void ShowSubMenu(void);
static void ExitSubMenu(void);
static void ExitMenu(void);

//---Menu---
static const menu_item_t menu[]={
    {"Set Clock",   &Clock,         NULL},
    {"Set Date",    &Date,          NULL},
    {"Sub Menu",    &ShowSubMenu,   NULL},
    {"Exit",        &ExitMenu,      NULL}
};

//---Sub Menu---
static const menu_item_t sub_menu[]={
    {"Sub Item 1",    NULL,   &ExitSubMenu},
    {"Sub Item 2",    NULL,   &ExitSubMenu},
    {"Sub Item 3",    NULL,   &ExitSubMenu}
};

//---Clock Options---
static option_item_t clock_options[] = {
    {12,0,23}, //hours
    {0,0,59},  //minutes
    {0,0,59}   //seconds
};

//---Date Options---
static option_item_t date_options[] = {
    {1,1,31},   //day
    {1,1,12},   //month
    {25,00,99}  //year
};

//---VIEW FUNCTIONS---
static void ShowMenu(uint8_t index) {
    printf("\033[H\033[J");//clear screen
    printf("\033[?25l");//disable cursor
    printf("\033[40;32m");
    printf("\n=== MENU ===\n");
    
    uint8_t menu_size=active_menu.menu_items;
    menu_item_t *menu_ptr = (menu_item_t*) active_menu.menu_tbl_ptr;

    for (uint8_t i = 0; i < menu_size; i++) {
        if (i == index) printf(" > %s\n", menu_ptr[i].text);
        else printf("   %s\n", menu_ptr[i].text);
    }
    fflush(stdout);
}

static void ShowOptions(uint8_t index) {
    printf("\033[H\033[J");
    printf("\n=== OPTIONS ===\n");
    
    printf("%s", active_options.text);
    for (uint8_t i = 0; i < active_options.option_items; i++) {
        printf("%02hhu", active_options.option_tbl_ptr[i].var);
        if (i < active_options.option_items - 1) printf("%c", active_options.separator);
    }
    printf("\n%*s--\n", (int) index * 3 + 6, "");
}

static void EditOptions(uint8_t index) {
    printf("\033[H\033[J");//clear screen
    printf("\n=== OPTIONS ===\n");
    
    printf("%s", active_options.text);
    for (uint8_t i = 0; i < active_options.option_items; i++) {
        printf("%02hhu", active_options.option_tbl_ptr[i].var);
        if (i < active_options.option_items - 1) printf("%c", active_options.separator);
    }
    printf("\n%*s[%02hhu]\n", (int) index * 3 + 5, "", active_options.option_tbl_ptr[index].var);
}

//---Handlers---
void MENU_MoveUp(void) {
    if (v_index > 0) v_index--;    
    ShowMenu(v_index);
}

void MENU_MoveDown(void) {
    if (v_index < active_menu.menu_items-1) v_index++;
    ShowMenu(v_index);
}

void MENU_Select(void) {
    menu_item_t *menu_ptr = (menu_item_t*) active_menu.menu_tbl_ptr;
    if (menu_ptr[v_index].menu_handler_on_entry) menu_ptr[v_index].menu_handler_on_entry();
}

void MENU_Esc(void) {
    menu_item_t *menu_ptr = (menu_item_t*) active_menu.menu_tbl_ptr;
    if (menu_ptr[v_index].menu_handler_on_exit) menu_ptr[v_index].menu_handler_on_exit();
}

void MENU_MoveLeft(void) {
    if (h_index > 0) h_index--;
    ShowOptions(h_index);
}

void MENU_MoveRight(void) {
    if (h_index < active_options.option_items-1) h_index++;
    ShowOptions(h_index);
}

void MENU_SelectOption(void) {
    EditOptions(h_index);
}

void MENU_EscOption(void) {
    ShowMenu(v_index);
}

void MENU_Add(void) {
    option_item_t *item = &active_options.option_tbl_ptr[h_index];
    if (item->var < item->max) item->var++;
    EditOptions(h_index);
}

void MENU_Subtract(void) {
    option_item_t *item = &active_options.option_tbl_ptr[h_index];
    if (item->var > item->min) item->var--;
    EditOptions(h_index);
}

void MENU_EditSelection(void) {
    ShowOptions(h_index);
}

void MENU_EscEdit(void) {
    ShowOptions(h_index);
}

//--- MENU HANDLERS ---
static void Clock(void) {
    active_options.option_tbl_ptr = clock_options;
    active_options.option_items = ARRAY_SIZE(clock_options);
    active_options.text = "Time: ";
    active_options.separator = ':';
    h_index = 0;
    ShowOptions(0);
}
static void Date(void) {
    active_options.option_tbl_ptr = date_options;
    active_options.option_items = ARRAY_SIZE(date_options);
    active_options.text = "Date: ";
    active_options.separator = '/';
    h_index = 0;
    ShowOptions(0);
}

static void ShowSubMenu(void) {
    v_index = 0;
    active_menu.menu_tbl_ptr= sub_menu;
    active_menu.menu_items=ARRAY_SIZE(sub_menu);
    ShowMenu(v_index);
    RaiseMenuEvent(MENU_EVENT_SPECIAL_NAV);
}

static void ExitSubMenu(void) {
    v_index = 2;
    active_menu.menu_tbl_ptr= menu;
    active_menu.menu_items=ARRAY_SIZE(menu);
    ShowMenu(v_index);
    RaiseMenuEvent(MENU_EVENT_STANDARD_NAV);
}

static void ExitMenu(void) {
    printf("Exiting...\n");
    exit(EXIT_SUCCESS);
}

void MENU_Initialize(void){
    active_menu.menu_tbl_ptr=menu;
    active_menu.menu_items=ARRAY_SIZE(menu);
    ShowMenu(0);
}

