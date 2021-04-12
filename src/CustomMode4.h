#pragma once
#include "ofMain.h"
#include "string.h"
#include "FractalMode.h"

class CustomMode4: public FractalMode {

    public:
    
    CustomMode4():FractalMode(){}

    string getName() {return "Custom Mode 4";}
    
    void draw(){

        ofDrawBitmapString("aye 4 is active yooooo", ofGetWidth()/2, ofGetHeight()/2);

    }



};
