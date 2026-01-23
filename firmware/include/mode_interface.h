#pragma once
#include "custom_types.h"
/**
 * @brief Abstraction class for easy implemtation of many light modes
 * 
 */
class ModeInterface {
    public:
        virtual ~ModeInterface() = default; //deconstruct inherited class too...
        virtual void worker() = 0;          //interface cannot be init without 
                                            //an overriding Class
        virtual light_mode_t getMode() = 0; // return the type of mode
};

 