#include <TFT_eSPI.h>
#include <math.h>
#include "src/group_data.h"
#include "src/display.h"
#include "src/led.h"
#include "src/input.h"

int group_page = 0;
int pre_member_idx = -1;

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SWITCH_LEFT_PIN, INPUT);
  pinMode(SWITCH_RIGHT_PIN, INPUT);
  pinMode(DIAL_PIN, INPUT);

  initLed();
  initDisplay();

  uint16_t now_color_palette[DISPLAY_COLOR_PALLETE_MAX];
  for (int i = 0; i < groups[group_page].member_num; i++) {
    uint8_t r5 = 0, g6 = 0, b5 = 0;
    r5 = (groups[group_page].members[i].color >> 16) & 0xFF;
    g6 = (groups[group_page].members[i].color >> 8)  & 0xFF;
    b5 = (groups[group_page].members[i].color >> 0)  & 0xFF;
    now_color_palette[i] = color565(r5, g6, b5);
  }
  drawPalette(groups[group_page].member_num, groups[group_page].group_name, now_color_palette);
}

void loop() {
  int switch_event_left = getLeftSwitchEvent(digitalRead(SWITCH_LEFT_PIN));
  int switch_event_right = getRightSwitchEvent(digitalRead(SWITCH_RIGHT_PIN));

  bool draw_flag = false;
  if (switch_event_left == RELEASED) {
    group_page--;
    if (group_page < 0) group_page = GROUP_PAGE_NUM - 1;
    draw_flag = true;
  }
  if (switch_event_right == RELEASED) {
    group_page++;
    if (group_page >= GROUP_PAGE_NUM) group_page = 0;
    draw_flag = true;
  }

  if (draw_flag == true) {
    uint16_t now_color_palette[DISPLAY_COLOR_PALLETE_MAX];
    for (int i = 0; i < groups[group_page].member_num; i++) {
      uint8_t r5 = 0, g6 = 0, b5 = 0;
      r5 = (groups[group_page].members[i].color >> 16) & 0xFF;
      g6 = (groups[group_page].members[i].color >> 8)  & 0xFF;
      b5 = (groups[group_page].members[i].color >> 0)  & 0xFF;
      now_color_palette[i] = color565(r5, g6, b5);
    }
    drawPalette(groups[group_page].member_num, groups[group_page].group_name, now_color_palette);
    pre_member_idx = -1;
  }

  int dial_raw_value = analogRead(DIAL_PIN);
  int member_num = groups[group_page].member_num;
  int dial_value = constrain(dial_raw_value, DIAL_VALUE_MIN, DIAL_VALUE_MAX);
  int pos = (dial_value - DIAL_VALUE_MIN) * member_num / (DIAL_VALUE_MAX - DIAL_VALUE_MIN + 1);
  if (pos >= member_num) pos = member_num - 1;
  int member_idx = member_num - pos - 1;
  if (member_idx != pre_member_idx) {
    if (pre_member_idx >= 0) {
      drawSelectorCursor(pre_member_idx, groups[group_page].member_num, TFT_BLACK);
    }
    drawSelectorCursor(member_idx, groups[group_page].member_num, TFT_WHITE);
    pre_member_idx = member_idx;
  }

  uint32_t led_color = convertDisplayColorToLedColor(groups[group_page].members[member_idx].color);
  // uint32_t led_color = groups[group_page].members[member_idx].color;
  uint8_t r_led = (led_color >> 16) & 0xFF;
  uint8_t g_led = (led_color >> 8)  & 0xFF;
  uint8_t b_led = led_color & 0xFF;
  uint8_t brightness = LED_BRIGHTNESS;
  r_led = r_led * brightness / 255;
  g_led = g_led * brightness / 255;
  b_led = b_led * brightness / 255;
  outputToAllLed(r_led, g_led, b_led);

  delay(1);
}