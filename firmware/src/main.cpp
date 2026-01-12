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
  delay(100); //long boot up on an leonardo
  Serial.println("booting...");
  
  // 1. Read the state of the board
  uint8_t flag = EEPROM.read(EEPROM_VERSION_ADDR);
  
  if (flag != FIRSTRUN_FLAG) {
    // A. FIRST RUN: Initialize defaults and set the first mode (0)
    Serial.println("EEPROM initializing: Setting default mode.");
    eeprom_mode_index = DEFAULT_MODE; // Start at 0
    EEPROM.write(EEPROM_MODE_ADDR, eeprom_mode_index);
    EEPROM.write(EEPROM_VERSION_ADDR, FIRSTRUN_FLAG);
  } else {
    // B. NORMAL RUN: Read current mode index from EEPROM
    eeprom_mode_index = EEPROM.read(EEPROM_MODE_ADDR);
  }

  // 2. Cycle the Mode Index (The reset action)
  // We want the NEXT mode index, so we increment the one we just read.
  eeprom_mode_index++;
  
  // Wrap around logic
  if (eeprom_mode_index >= MODE_COUNT) {
    eeprom_mode_index = 0; 
  }

  // 3. Assign the calculated index to the currentMode variable
  //    This makes the switch() statement and loop() function work correctly.
  currentMode = availableModes[eeprom_mode_index]; 
  
  // 4. Save the NEW mode index to EEPROM for the next reset.
  EEPROM.put(EEPROM_MODE_ADDR, eeprom_mode_index); 
  
  currentMode = MODE_RAINBOW ;

  // 5. Initialize the LED strip
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, LED_NUM);
  
  // 6. Mode-specific initialization
  switch(currentMode) {
    case MODE_OFF:
      Serial.println("Mode: OFF");
      FastLED.clear();
      FastLED.show();
      break;
    case MODE_RAINBOW:
      Serial.println("Mode: RAINBOW");
      FastLED.setBrightness(RAINBOW_BRIGHTNESS);
      break;
    case MODE_PIANO_VISUALIZER:
      Serial.println("Mode: PIANO VISUALIZER");
      // Add visualizer setup here
      break;
    default:
      Serial.println("Error: Unknown Mode.");
      // Fallback to a safe mode if index is bad
      currentMode = MODE_OFF; 
      FastLED.clear();
      FastLED.show();
      break;
  }

  Serial.println("Piano LED Controller Initialized");
  Serial.print("Current Mode Index: ");
  Serial.println(eeprom_mode_index);
}
void loop() {
  // Check if data is available to read
  switch(currentMode){
    case MODE_OFF: {
      FastLED.clear();
      delay(10000);
      break;
    }
    case MODE_RAINBOW: {
      rainbow_mode(RAINBOW_SPEED, RAINBOW_DELTAHUE);
      break;
    }
    default: break;
  }
  FastLED.show();
}