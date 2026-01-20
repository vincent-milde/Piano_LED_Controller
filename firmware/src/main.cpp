/**
 * @file Piano_led_controller.ino
 * @brief This file contains the main code for controlling the piano LED lights.
 * @author Vincent-Milde
 * @note Intended for use with an Arduino Leonardo board
 * @version 1.0
 * @date 2024-06-15
 * 
 */
#include <Arduino.h>
#include <FastLED.h>
#include "config.h"
#include "custom_types.h"
#include "off_mode.h"
#include "rainbow_mode.h"

// Global variable definitions

//=============== MODE SECTION ===================//
/**
 * 
 * @example
  CRGB leds[LED_NUM];
  OffMode of1 ;
  RainbowMode rb1(leds, LED_NUM);
  RainbowMode rb2(leds, LED_NUM, {false, 50, 10, 3, RAINBOW_SAW_TOOTH});

  ModeInterface *modes[] = {
      &of1,  
      &rb1,  
      &rb2   
  };
 */
CRGB leds[LED_NUM];
OffMode of1 ;
RainbowMode rb1(leds, LED_NUM);
RainbowMode rb2(leds, LED_NUM, {false, 50, 10, 3, RAINBOW_SAW_TOOTH});

ModeInterface *modes[] = {
    &of1,  
    &rb1,  
    &rb2   
};

const int modeCount = sizeof(modes) / sizeof(modes[0]);

int current_mode_index = 0 ;

//============ Setup and Loop ============//

void setup() {
  Serial.begin(9600);
  delay(100); 
  Serial.println("booting...");
  FastLED.addLeds<LED_TYPE, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.clear();
  FastLED.show();
}
void loop() {
  // Check if data is available to read
  modes[current_mode_index]->worker() ;
  FastLED.show();  
}