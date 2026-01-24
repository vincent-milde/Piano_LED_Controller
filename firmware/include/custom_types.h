#pragma once

//Mode interface
enum light_mode_t{
    MODE_OFF,
    MODE_COLOUR,
    MODE_RAINBOW,
    MODE_PIANO_VISUALIZER
};

//Colour mode


//Rainbow mode
typedef enum{
    RAINBOW_SAW_TOOTH,  
    RAINBOW_SINE_WAVE
}rainbow_mode_t;

typedef struct{
    bool direction;          //L to R = false ; R to L = true ;
    int rainbow_brightness ;    // 0 - 255
    int rainbow_speed ;       //How fast the rainbow moves 
    int rainbow_deltahue;       //how many rainbow periods
    rainbow_mode_t mode ;
}rainbow_mode_config_t;

// Piano Visualizer
