#pragma once
#include "mode_interface.h"

class OffMode : public ModeInterface {
public:
    void worker() override;
};

