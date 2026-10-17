#pragma once
#include <Arduino.h>
#define DISPLAY_COLOR_PALLETE_MAX 16

void initDisplay();
uint16_t color565(uint8_t r5, uint8_t g6, uint8_t b5);
void drawPalette(int segment_num, String group_name, uint16_t* colors);
void drawSelectorCursor(int member_idx, int member_num, uint16_t color);