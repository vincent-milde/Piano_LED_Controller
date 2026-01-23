#pragma once
#include "mode_interface.h"
#include "custom_types.h"

class PianoVisualizer : public ModeInterface {
    private: 
        light_mode_t _mode = light_mode_t::MODE_PIANO_VISUALIZER ;
    public:
        PianoVisualizer() ;
        void worker() override ;
        light_mode_t getMode() override ;
};