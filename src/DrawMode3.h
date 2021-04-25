#pragma once
#include "ofMain.h"
#include "FractalMode.h"

class DrawMode3: public FractalMode {

    public:
    
    ofColor color1;
    ofColor color2;
    ofColor color3;
    DrawMode3():FractalMode(){color1 = ofColor(255, 0, 0); color2 = ofColor(255, 0, 0); color3 = ofColor(255, 0, 0);}

    string getName() {return "Sierpiński triangle";}


    void draw(){}
    
    void draw(float x, float y, float size, int n) {
        ofNoFill();



        if(n == 0) {
            return;
        }

        ofPoint a(x, y);
        ofPoint b(x + size, y);
        ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));


        this->draw(x, y, size / 2, n - 1);
        this->draw((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
        this->draw((a.x + c.x) / 2, (a.y + c.y) / 2, size / 2, n - 1);



        if ((n+2)%3 == 0) {ofSetColor(color1);}
        else if ((n+1)%3 == 0) {ofSetColor(color2);}
        else {ofSetColor(color3);}

        ofDrawTriangle(a, b, c);
    }
};
