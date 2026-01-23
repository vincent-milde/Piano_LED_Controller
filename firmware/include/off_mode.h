#pragma once
#include "custom_types.h"
#include "mode_interface.h"

class OffMode : public ModeInterface {
    private:
        light_mode_t _mode = light_mode_t::MODE_OFF;
    public:
        void worker() override;
        light_mode_t getMode() override;
};

