#include "rainbow_mode.h"
#include "config.h"
#include <FastLED.h>

RainbowMode:: RainbowMode(CRGB *leds,int led_amount, const rainbow_mode_config_t& cfg)
 :  _leds(leds),
    _led_amount(led_amount),
    _cfg(cfg) //default init in custom_types.h
   
{
    Serial.println("Rainbow mode initialized...");
}  
void RainbowMode::worker(){
  uint8_t currentHue;
  if(_cfg.mode == RAINBOW_SINE_WAVE)
    currentHue = beatsin8(_cfg.rainbow_speed, _cfg.rainbow_deltahue) ;
  else if(_cfg.mode == RAINBOW_SAW_TOOTH)
    currentHue = beat8(_cfg.rainbow_speed, _cfg.rainbow_deltahue);
  fill_rainbow(_leds, _led_amount, currentHue, _cfg.rainbow_deltahue);   
  Serial.println("rainbow worker called") ;
}
