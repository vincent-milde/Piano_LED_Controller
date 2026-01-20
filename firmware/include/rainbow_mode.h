#pragma once
#include "custom_types.h"
#include <FastLED.h>
#include "mode_interface.h"

class RainbowMode : public ModeInterface{
    private:
        rainbow_mode_config_t _cfg ;
        CRGB* _leds;
        int _led_amount;
    public:
        RainbowMode(CRGB *leds,int led_amount, const rainbow_mode_config_t& cfg = {false, 80, 10, 3, RAINBOW_SAW_TOOTH})  ;  //default init in custom_types.h
        void worker() override;
};
