/*
____    __    ____  _______  __        ______   ______   .___  ___.  _______
\   \  /  \  /   / |   ____||  |      /      | /  __  \  |   \/   | |   ____|
 \   \/    \/   /  |  |__   |  |     |  ,----'|  |  |  | |  \  /  | |  |__
  \            /   |   __|  |  |     |  |     |  |  |  | |  |\/|  | |   __|
   \    /\    /    |  |____ |  `----.|  `----.|  `--'  | |  |  |  | |  |____
    \__/  \__/     |_______||_______| \______| \______/  |__|  |__| |_______|

*/

//=============== LED SECTION ===================//
#define LED_PIN 13//Make sure this pin has PWM support
#define LED_NUM 174//How many LEDs are you using?
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

//=============== MODE SECTION ==================//
#define DARK 
#define RAINBOW
//#define PIANO_VISUALIZER
#define MODE_COUNT 2 //amount of modes


//=============== RAINBOW MODE ==================//
#define RAINBOW_BRIGHTNESS 80 // 0 - 255
#define RAINBOW_SPEED 10
#define RAINBOW_DELTAHUE 3
//#define RAINBOW_WAVE
#define RAINBOW_MARCH

//=============== PIANO VISUALIZER MODE ===============//



//=============== EEPROM Settings ================//
// --- EEPROM Address Map ---
const uint8_t EEPROM_VERSION_ADDR = 0;  // Use address 0 for our version flag
const uint8_t EEPROM_MODE_ADDR    = 1;  // Address for your mode variable

// --- Default Values ---
const uint8_t FIRSTRUN_FLAG = 0xAC;    // A unique value (like 0xAB) for the flag
const uint8_t DEFAULT_MODE  = 1 ;

//=============== ERROR CHECKING ==================//
#if !defined(RAINBOW) && ((defined(RAINBOW_WAVE) || defined(RAINBOW_MARCH)))
  #error "YOU CANT USE RAINBOW MODES WITHOUT DEFINING THE PARENT FIRST"
#endif
#if defined(RAINBOW_WAVE) && defined(RAINBOW_MARCH)
  #error "You can only enable one rainbow effect at a time!"
#endif
#if MODE_COUNT < 1
  #error "You must enable at least one mode!"
#endif
#if MODE_COUNT > 3
  #error "You have enabled more modes than are available!"
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
