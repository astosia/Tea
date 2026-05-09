#pragma once
#include <pebble.h>

/********************/
/*     VARIABLE     */
/********************/

typedef struct {
  char name[16];       // Name of this tea (up to 15 chars + null terminator)
  uint16_t def_time;   // Default steep time in seconds
  uint8_t persist_key; // Persist key for steep time
  uint8_t hide_key;    // Persist key for hide flag (1 = show, 0 = hidden)
  uint8_t temp;        // Temperature to steep this tea (Celsius)
} TeaInfo;

/********************/
/*     FUNCTION     */
/********************/

void menu_destroy();
void menu_display();
void menu_mark_dirty();
int get_tea_temp(int);