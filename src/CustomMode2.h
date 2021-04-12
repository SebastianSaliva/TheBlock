#pragma once
#include "ofMain.h"
#include "string.h"
#include "FractalMode.h"

class CustomMode2: public FractalMode {

    public:
    
    CustomMode2():FractalMode(){}

    string getName() {return "Custom Mode 2";}
    
    void draw(){}

    void draw(float x, float y, float l, int n, int colorLevel){

        
        if (n == 0){return;}
        float dis = sqrt(pow(l,2) - pow(l/2, 2));
        ofPoint a(x, y);
        ofPoint b(x-dis, y-l/2);
        ofPoint c(x, y-l);        
        ofPoint d(x+dis, y- l/2);
        ofPoint e(x+dis, y+ l/2);
        ofPoint f(x, y+l);
        ofPoint g(x-dis, y+l/2);
        
        ofFill();
        
        ofSetColor(colorLevel-70);
        ofDrawTriangle(a, b, c);
        ofDrawTriangle(a, c, d);

        ofSetColor(colorLevel-120);
        ofDrawTriangle(a, d, e);
        ofDrawTriangle(a, e, f);

        ofSetColor(colorLevel);
        ofDrawTriangle(a, f, g);
        ofDrawTriangle(a, g, b);


        draw(c.x, c.y, l/2, n-1,colorLevel-10);
        draw(e.x, e.y, l/2, n-1,colorLevel-10);
        draw(g.x, g.y, l/2, n-1,colorLevel-10);

    }



    

    void draw(float x, float y, float l, int n) {

        draw(x, y, l, n, 255);
    }
};
