#pragma once
#include "ofMain.h"
#include "FractalMode.h"

class DrawMode3: public FractalMode {

    public:
    
    DrawMode3():FractalMode(){}

    string getName() {return "Sierpiński triangle";}
    
    void draw(){}
    
    void draw(float x, float y, float size, int n) {
        ofNoFill();

        if ((n+2)%3 == 0) {ofSetColor(0, 255, 0);}
        else if ((n+1)%3 == 0) {ofSetColor(0, 255, 0);}
        else {ofSetColor(0, 0, 255);}

        if(n == 0) {
            return;
        }

        ofPoint a(x, y);
        ofPoint b(x + size, y);
        ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));


        if (n ==1){
        ofDrawTriangle(a, b, c);
        }
        this->draw(x, y, size / 2, n - 1);
        this->draw((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);

        this->draw((a.x + c.x) / 2, (a.y + c.y) / 2, size / 2, n - 1);


    }
};
