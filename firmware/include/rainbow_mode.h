#pragma once
#include "custom_types.h"
#include "mode_interface.h"

class RainbowMode : public ModeInterface{
    private:
        rainbow_mode_config_t _cfg ;
        CRGB* _leds;
        int _led_amount;
    public:
        RainbowMode(CRGB *leds,int &led_amount, const rainbow_mode_config_t& cfg = {});    //default init in custom_types.h
        void worker() override;
};
