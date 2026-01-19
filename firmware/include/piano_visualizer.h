#pragma once
#include "mode_interface.h"
#include "custom_types.h"

class PianoVisualizer : public ModeInterface {
public:
    PianoVisualizer();
    void worker() override;
};