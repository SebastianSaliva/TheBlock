#pragma once
#include "ofMain.h"
#include "FractalMode.h"

class DrawMode1: public FractalMode {

    public:
    
    ofColor color1;
    ofColor color2;
    ofColor color3;
    DrawMode1():FractalMode(){color1 = ofColor(255, 0, 0); color2 = ofColor(255, 0, 0); color3 = ofColor(255, 0, 0);}

    string getName() {return "Circles";}

    void draw(){}
    
    void draw(int x, int y, int n) {

        ofNoFill();

        if ((n+2)%3 == 0) {ofSetColor(color1);}
        else if ((n+1)%3 == 0) {ofSetColor(color2);}
        else {ofSetColor(color3);}

        if(n>0){
            ofDrawCircle(x, y, n*10 );
            this->draw(x+100, y, n-1);
            this->draw(x-100, y, n-1);
            this->draw(x, y+100, n-1);  
            this->draw(x, y-100, n-1);
        }
    }
};