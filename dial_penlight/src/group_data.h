#pragma once
#include <Arduino.h>
#define GROUP_PAGE_NUM 7

struct Member {
  const String name;
  const uint32_t color;
};

struct Group {
  const String group_name;
  const int member_num;
  const Member* members;
};

extern const Group groups[];