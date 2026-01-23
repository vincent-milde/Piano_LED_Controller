#include "off_mode.h"
#include <FastLED.h>

void OffMode::worker() {
    FastLED.clear();
}
light_mode_t OffMode::getMode() {
    return _mode;
}