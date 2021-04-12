#pragma once
#include "ofMain.h"
#include "string.h"
#include "FractalMode.h"

class CustomMode1: public FractalMode {

    public:
    
    CustomMode1():FractalMode(){}

    string getName() {return "Custom Mode 1";}
    
    void draw(){}

    void draw(float x, float y, float l, int n) {draw(x, y, l, n, "begin");}
    
    void draw(float x, float y, float l, int n, string i) {
        ofFill();
        if ((n+2)%3 == 0) {ofSetColor(255, 0, 0);}
        else if ((n+1)%3 == 0) {ofSetColor(0, 255, 0);}
        else {ofSetColor(0, 0, 255);}

        if (n==0){return;}

        ofDrawRectangle(x-l/2, y-l/2, l, l);

        if ((n+2)%3 == 0) {ofSetColor(127, 0, 0);}
        else if ((n+1)%3 == 0) {ofSetColor(0, 127, 0);}
        else {ofSetColor(0, 0, 127);}

        ofDrawTriangle(x-l/2, y-l/2, x+l/2, y+l/2, x+l/2, y-l/2);

        if (i == "begin") {
        draw(x-(l) + 1, y, l/2, n-1, "left");
        draw(x+(l) + 1, y, l/2, n-1, "right");
        draw(x, y-(l)+1, l/2, n-1, "up");
        draw(x, y+(l)+1, l/2, n-1, "down");
        }

        if (!(i == "left")) {draw(x+(l) + 1, y, l/2, n-1, "right");}
        if (!(i== "right")) {draw(x-(l) + 1, y, l/2, n-1, "left");}
        if (!(i== "up")) {draw(x, y+(l)+1, l/2, n-1, "down");}
        if (!(i== "down")) {draw(x, y-(l)+1, l/2, n-1, "up");}


    }
};
