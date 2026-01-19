#pragma once
typedef enum {
    MODE_OFF,
    MODE_RAINBOW,
    MODE_PIANO_VISUALIZER
} light_mode_t;

typedef enum{
    RAINBOW_SAW_TOOTH,  
    RAINBOW_SINE_WAVE
}rainbow_mode_t;

typedef struct{
    bool direction = false ;          //L to R = false ; R to L = true ;
    int rainbow_brightness = 80 ;    // 0 - 255
    int rainbow_speed = 10   ;       //How fast the rainbow moves 
    int rainbow_deltahue = 3 ;       //how many rainbow periods
    rainbow_mode_t mode = RAINBOW_SAW_TOOTH;
}rainbow_mode_config_t;