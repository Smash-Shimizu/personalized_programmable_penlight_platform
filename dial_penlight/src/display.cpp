#include "display.h"
#include <TFT_eSPI.h>
#include <math.h>

#define DISPLAY_INNER_R 55
#define DISPLAY_TRI_STEPS 6
#define DISPLAY_START_DEG -210.0f
#define DISPLAY_END_DEG 30.0f

static void fillSector(int cx, int cy, int r, float a0, float a1, uint16_t color);
static TFT_eSPI tft = TFT_eSPI();

void initDisplay() {
    tft.init();
    tft.setRotation(0);
}

uint16_t color565(uint8_t r5, uint8_t g6, uint8_t b5) {
    return tft.color565(r5, g6, b5);
}

void fillSector(int cx, int cy, int r, float a0, float a1, uint16_t color) {
  for (int i = 0; i < DISPLAY_TRI_STEPS; i++) {
    float t0 = a0 + (a1 - a0) * i / DISPLAY_TRI_STEPS;
    float t1 = a0 + (a1 - a0) * (i + 1) / DISPLAY_TRI_STEPS;
    int x0 = cx + r * cos(t0);
    int y0 = cy + r * sin(t0);
    int x1 = cx + r * cos(t1);
    int y1 = cy + r * sin(t1);
    tft.fillTriangle(cx, cy, x0, y0, x1, y1, color);
  }
}

void drawPalette(int segment_num, String group_name, uint16_t* colors) {
  int w = tft.width();
  int h = tft.height();
  int cx = w / 2;
  int cy = h / 2;
  int outerR = min(w, h) / 2 - 2;
  tft.fillScreen(TFT_BLACK);
  for (int i = 0; i < segment_num; i++) {
    float a0 = radians(DISPLAY_START_DEG + (DISPLAY_END_DEG - DISPLAY_START_DEG) * i / segment_num);
    float a1 = radians(DISPLAY_START_DEG + (DISPLAY_END_DEG - DISPLAY_START_DEG) * (i + 1) / segment_num);
    fillSector(cx, cy, outerR, a0, a1, colors[i]);
  }
  tft.fillCircle(cx, cy, DISPLAY_INNER_R, TFT_BLACK);

  tft.setTextDatum(MC_DATUM);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString(group_name, cx, cy + 80);
}

void drawSelectorCursor(int member_idx, int member_num, uint16_t color) {
  int w = tft.width();
  int h = tft.height();
  int cx = w / 2;
  int cy = h / 2;
  float angle = radians(
    DISPLAY_START_DEG +
    (DISPLAY_END_DEG - DISPLAY_START_DEG) * (member_idx + 0.5f) / member_num
  );
  int tip_r = DISPLAY_INNER_R - 4;
  int base_r = DISPLAY_INNER_R - 18;
  int half_w = 6;
  int tip_x = cx + tip_r * cos(angle);
  int tip_y = cy + tip_r * sin(angle);
  int base_x = cx + base_r * cos(angle);
  int base_y = cy + base_r * sin(angle);
  float side = angle + PI / 2;
  int left_x  = base_x + half_w * cos(side);
  int left_y  = base_y + half_w * sin(side);
  int right_x = base_x - half_w * cos(side);
  int right_y = base_y - half_w * sin(side);
  tft.fillTriangle(tip_x, tip_y, left_x, left_y, right_x, right_y, color);
}