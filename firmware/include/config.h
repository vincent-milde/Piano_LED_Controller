#pragma once
#include "custom_types.h"
#include "mode_interface.h"
#include "off_mode.h"
#include "rainbow_mode.h"

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
#define LED_PIN 13//Make sure this pin has PWM support
#define LED_NUM 174//How many LEDs are you using?
#define LED_TYPE WS2812B


//=============== FASTLED Section ==================//
  #if (LED_TYPE == WS2812B) 
    CRGB leds[LED_NUM];
  #endif

//=============== MODE SECTION ===================//
/**
 * 
 * @example
 * //init custom modes 
 * Rainbow
 * ModeInterface modes [] = {
 *       
 * }
 * 
 */
OffMode of1 ;
RainbowMode rb1(leds,LED_NUM,
  {
    .rainbow_brightness = 50;
  }
);

ModeInterface modes [] = {

}



//=============== EEPROM Settings ================//
// --- EEPROM Address Map ---
const uint8_t EEPROM_VERSION_ADDR = 0;  // Use address 0 for our version flag
const uint8_t EEPROM_MODE_ADDR    = 1;  // Address for your mode variable

// --- Default Values ---
const uint8_t FIRSTRUN_FLAG = 0xAC;    // A unique value (like 0xAB) for
                                       // the flag
const uint8_t DEFAULT_MODE  = 1 ;

//=============== ERROR CHECKING ==================//
#if !defined(RAINBOW) && ((defined(RAINBOW_WAVE) || defined(RAINBOW_MARCH)))
  #error "YOU CANT USE RAINBOW MODES WITHOUT DEFINING THE PARENT FIRST"
#endif
#if defined(RAINBOW_WAVE) && defined(RAINBOW_MARCH)
  #error "You can only enable one rainbow effect at a time!"
#endif

#ifndef LED_PIN
  #error "You must define an LED_PIN!"
#endif
#ifndef LED_NUM
  #error "You must define an LED_NUM!"
#endif
#ifndef LED_TYPE
  #error "You must define an LED_TYPE!"
#endif
#ifndef COLOR_ORDER
  #error "You must define a COLOR_ORDER!"
#endif
