#pragma once
#include "ofMain.h"
#include "string.h"
#include "FractalMode.h"

class CustomMode5: public FractalMode {

    public:
    
    CustomMode5():FractalMode(){}

    string getName() {return "Custom Mode 5";}
    
    void draw(){

        ofDrawBitmapString("aye 5 is active yooooo", ofGetWidth()/2, ofGetHeight()/2);

    }

};
