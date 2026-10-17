#pragma once
#include <Arduino.h>
#define LED_PIN 0
#define LED_BRIGHTNESS 255

void initLed();
uint32_t convertDisplayColorToLedColor(uint32_t color);
void outputToAllLed(uint8_t r, uint8_t g, uint8_t b);