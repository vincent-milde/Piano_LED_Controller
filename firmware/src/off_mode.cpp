#include "off_mode.h"
#include <FastLED.h>

void OffMode::worker() {
    FastLED.clear();
    FastLED.show() ;
}