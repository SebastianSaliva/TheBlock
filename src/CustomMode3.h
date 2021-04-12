#pragma once
#include "ofMain.h"
#include "string.h"
#include "FractalMode.h"

class CustomMode3: public FractalMode {

    public:
    
    CustomMode3():FractalMode(){}

    string getName() {return "Custom Mode 3";}
    
    void draw(){

        ofDrawBitmapString("aye 3 is active yooooo", ofGetWidth()/2, ofGetHeight()/2);

    }

};
