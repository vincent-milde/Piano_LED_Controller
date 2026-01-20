#pragma once
#include <FastLED.h>
#include "custom_types.h"
#include "mode_interface.h"

/*
____    __    ____  _______  __        ______   ______   .___  ___.  _______
\   \  /  \  /   / |   ____||  |      /      | /  __  \  |   \/   | |   ____|
 \   \/    \/   /  |  |__   |  |     |  ,----'|  |  |  | |  \  /  | |  |__
  \            /   |   __|  |  |     |  |     |  |  |  | |  |\/|  | |   __|
   \    /\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____
    \__/  \__/     |_______||_______| \______| \______/  |__|  |__| |_______|

*/

//=============== General config =====================//
#define VERSION 0001

//============ Supported LEDs===================//
#define WS2812B 0

//=============== LED SECTION ===================//
#define LED_PIN 14//Make sure this pin has PWM support
#define LED_NUM 174//How many LEDs are you using?
#define LED_TYPE WS2812B


//=============== FASTLED Section ==================//
  #if (LED_TYPE == WS2812B) 
    extern CRGB leds[LED_NUM];
  #endif

extern ModeInterface *modes[];
extern const int modeCount;



//=============== EEPROM Settings ================//
// --- EEPROM Address Map ---
const uint8_t EEPROM_VERSION_ADDR = VERSION;  // Use address 0 for our version flag
const uint8_t EEPROM_MODE_ADDR    = 1;  // Address for your mode variable

// --- Default Values ---
const uint8_t FIRSTRUN_FLAG = 0xAC;    // A unique value (like 0xAB) for
                                       // the flag
const uint8_t DEFAULT_MODE  = 1 ;

//=============== ERROR CHECKING ==================//
