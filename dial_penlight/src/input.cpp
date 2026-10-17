#include "input.h"
#define CHATTERING_CHECK_NUM 3

static int chattering_counter_left = CHATTERING_CHECK_NUM;
static int chattering_counter_right = CHATTERING_CHECK_NUM;

static int pre_raw_switch_state_left = 0;
static int pre_raw_switch_state_right = 0;

static int pre_fixed_switch_state_left = -1;
static int pre_fixed_switch_state_right = -1;

int getLeftSwitchEvent(int now_raw_switch_state_left) {
    int now_fixed_switch_state_left = -1;
    if (now_raw_switch_state_left == pre_raw_switch_state_left) {
        chattering_counter_left--;
        if (chattering_counter_left == 0) {
            now_fixed_switch_state_left = now_raw_switch_state_left;
            chattering_counter_left = CHATTERING_CHECK_NUM;
        }
    }
    else {
        chattering_counter_left = CHATTERING_CHECK_NUM;
    }
    pre_raw_switch_state_left = now_raw_switch_state_left;

    int switch_event_left = -1;
    if (pre_fixed_switch_state_left == 0 && now_fixed_switch_state_left == 1) {
        switch_event_left = JUST_PRESSED;
    }
    else if (pre_fixed_switch_state_left == 1 && now_fixed_switch_state_left == 0) {
        switch_event_left =  RELEASED;
    }
    if (now_fixed_switch_state_left != -1) pre_fixed_switch_state_left = now_fixed_switch_state_left;

    return switch_event_left;
}

int getRightSwitchEvent(int now_raw_switch_state_right) {
    int now_fixed_switch_state_right = -1;
    if (now_raw_switch_state_right == pre_raw_switch_state_right) {
        chattering_counter_right--;
        if (chattering_counter_right == 0) {
            now_fixed_switch_state_right = now_raw_switch_state_right;
            chattering_counter_right = CHATTERING_CHECK_NUM;
        }
    }
    else {
        chattering_counter_right = CHATTERING_CHECK_NUM;
    }
    pre_raw_switch_state_right = now_raw_switch_state_right;

    int switch_event_right = -1;
    if (pre_fixed_switch_state_right == 0 && now_fixed_switch_state_right == 1) {
        switch_event_right = JUST_PRESSED;
    }
    else if (pre_fixed_switch_state_right == 1 && now_fixed_switch_state_right == 0) {
        switch_event_right =  RELEASED;
    }
    if (now_fixed_switch_state_right != -1) pre_fixed_switch_state_right = now_fixed_switch_state_right;

    return switch_event_right;
}