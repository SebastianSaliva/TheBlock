#pragma once
#include "ofMain.h"
#include "FractalMode.h"

class DrawMode1: public FractalMode {

    public:
    
    DrawMode1():FractalMode(){}
    
    string getName() {return "mode 1";}

    void draw(){}
    void draw(int x, int y, int n) {

        if ((n+2)%3 == 0) {ofSetColor(255, 0, 0);}
        else if ((n+1)%3 == 0) {ofSetColor(0, 255, 0);}
        else {ofSetColor(0, 0, 255);}

        if(n>0){
            ofDrawCircle(x, y, n*10 );
            this->draw(x+100, y, n-1);
            this->draw(x-100, y, n-1);
            this->draw(x, y+100, n-1);  
            this->draw(x, y-100, n-1);
        }
    }
};