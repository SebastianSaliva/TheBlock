#pragma once
#include "ofMain.h"
#include "FractalMode.h"

class DrawMode1: public FractalMode {

    public:
    
    DrawMode1():FractalMode(){}
    
    string getName() {return "Circles";}
    ofColor getc1();
    ofColor getc2();
    ofColor getc3();
    void draw(){}
    
    void draw(int x, int y, int n) {

        ofNoFill();

        if ((n+2)%3 == 0) {ofSetColor(color1);}
        else if ((n+1)%3 == 0) {ofSetColor(color1);}
        else {ofSetColor(color1);}

        if(n>0){
            ofDrawCircle(x, y, n*10 );
            this->draw(x+100, y, n-1);
            this->draw(x-100, y, n-1);
            this->draw(x, y+100, n-1);  
            this->draw(x, y-100, n-1);
        }
    }
};