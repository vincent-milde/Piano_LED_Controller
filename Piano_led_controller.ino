/**
 * @file Piano_led_controller.ino
 * @brief This file contains the main code for controlling the piano LED lights.
 * @author Vincent-Milde
 * @note Intended for use with an Arduino Leonardo board
 * @version 1.0
 * @date 2024-06-15
 * 
 */
#include <EEPROM.h>
#include <FastLED.h>
#include "config.h"
#include "custom_types.h"

//============ Global variables ============//
CRGB leds[LED_NUM];

uint8_t eeprom_mode_index = 0;
light_mode_t currentMode = MODE_OFF;

// Init mode arrays
light_mode_t availableModes[MODE_COUNT] = {
  #ifdef DARK
    MODE_OFF
  #endif
  #ifdef RAINBOW
    ,MODE_RAINBOW
  #endif
  #ifdef PIANO_VISUALIZER
    ,MODE_PIANO_VISUALIZER
  #endif
};

//============ Methods ===================//
void rainbow_mode(uint8_t speed, uint8_t deltaHue){
  #ifdef RAINBOW_WAVE
    uint8_t currentHue = beatsin8(speed, deltaHue) ;
  #elif defined (RAINBOW_MARCH)
    uint8_t currentHue = beat8(speed, deltaHue);
  #else
    #error "NO WAVE TYPE DEFINED"
  #endif

  fill_rainbow(leds, LED_NUM, currentHue, deltaHue);   
}

//============ Setup and Loop ============//

void setup() {
  Serial.begin(9600);

  //Init EEPROM
  uint8_t flag = EEPROM.read(EEPROM_FLAG_ADDR);
  
  if (flag != FIRSTRUN_FLAG) {
    // EEPROM is blank or old version -> Initialize defaults
    Serial.println("EEPROM initializing: Setting default mode.");
    EEPROM.write(EEPROM_MODE_ADDR, DEFAULT_MODE); 
    EEPROM.write(EEPROM_FLAG_ADDR, FIRSTRUN_FLAG); // Mark as initialized
    eeprom_mode_index = DEFAULT_MODE;
  } else {
    // EEPROM is initialized -> Read current index
    eeprom_mode_index = EEPROM.read(EEPROM_MODE_ADDR);
    eeprom_mode_index++ ; //step into next mode after reset...
    eeprom_mode_index = (eeprom_mode_index >= MODE_COUNT) ? 0 : eeprom_mode_index;
  }

  // Initialize the LED strip
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, LED_NUM);

  switch(currentMode) {
    case MODE_OFF:
      // Turn off all LEDs
      FastLED.clear();
      FastLED.show();
      break;
    case MODE_RAINBOW:
      // Initialize rainbow mode
      FastLED.setBrightness(RAINBOW_BRIGHTNESS);
      break;
    case MODE_PIANO_VISUALIZER:
      // Initialize piano visualizer mode
      break;
    default:
      break;
  }

  Serial.println("Piano LED Controller Initialized");
}
void loop() {
  // Check if data is available to read
  switch(currentMode){
    case MODE_OFF: {
      break;
    }
    case MODE_RAINBOW{
      rainbow_mode(RAINBOW_SPEED, RAINBOW_DELTAHUE);
      break;
    }
    default: break;
  }
}