#pragma once
#include "ofMain.h"
#include "FractalMode.h"

class KochSnowFlake: public FractalMode {

    public:
    
    KochSnowFlake():FractalMode(){}

    string getName() {return "Koch Snowflake";}
    
    void draw(){}
    
    void draw(float x, float y) {
    
    }
};
