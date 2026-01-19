#pragma once
class ModeInterface {
public:
    virtual ~ModeInterface() = default; //deconstruct inherited class too...
    virtual void worker() = 0; //interface cannot be init without an overriding
                               //Class
};

 