#include "led.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_NUM 40

static Adafruit_NeoPixel pixels(LED_NUM, LED_PIN, NEO_GRB + NEO_KHZ800);

void initLed() {
    pixels.begin();
}

//未検証
uint32_t convertDisplayColorToLedColor(uint32_t color) {
  float r = ((color >> 16) & 0xFF) / 255.0f;
  float g = ((color >> 8)  & 0xFF) / 255.0f;
  float b = ((color >> 0)  & 0xFF) / 255.0f;

  // ガンマ補正
  r = pow(r, 2.2);
  g = pow(g, 2.2);
  b = pow(b, 2.2);

  // LED個体・拡散材に合わせた補正
  r *= 1.00;
  g *= 0.80;
  b *= 0.45;  // 青を少し弱めると赤がピンク化しにくい

  // 最大値が1を超えたら正規化
  float maxv = max(r, max(g, b));
  if (maxv > 1.0f) {
    r /= maxv;
    g /= maxv;
    b /= maxv;
  }

  uint8_t R = constrain(r * 255, 0, 255);
  uint8_t G = constrain(g * 255, 0, 255);
  uint8_t B = constrain(b * 255, 0, 255);

  return ((uint32_t)R << 16) | ((uint32_t)G << 8) | B;
}

void outputToAllLed(uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < LED_NUM; i++) {
        pixels.setPixelColor(i, pixels.Color(r, g, b));
    }
    pixels.show();
}