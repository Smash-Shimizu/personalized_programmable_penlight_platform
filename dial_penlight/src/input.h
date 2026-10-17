#pragma once
enum {JUST_PRESSED, RELEASED, HOLDING};
#define SWITCH_LEFT_PIN 4
#define SWITCH_RIGHT_PIN 5
#define DIAL_PIN 6
#define DIAL_VALUE_MIN 0
#define DIAL_VALUE_MAX 1023

int getLeftSwitchEvent(int now_raw_switch_state_left);
int getRightSwitchEvent(int now_raw_switch_state_right);