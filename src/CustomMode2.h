#pragma once
#include "ofMain.h"
#include "string.h"
#include "FractalMode.h"

class CustomMode2: public FractalMode {

    public:

    CustomMode2():FractalMode(){}

    string getName() {return "Custom Mode 2 (3d fractals, only this mode will be drawn)";}
    
    void draw(){}

    void draw1(ofPoint a, float l, int n){        
        ofEnableAlphaBlending();
        draw1(a, l, n, 'b');
        ofDisableAlphaBlending();
        }

    void draw1(ofPoint a, float l, int n, char side){

        ofNoFill();
        if (n==0) {return;}
        if ((n+2)%3 == 0) {ofSetColor(255, 0, 0, 100);}
        else if ((n+1)%3 == 0) {ofSetColor(0, 255, 0, 50);}
        else {ofSetColor(0, 0, 255, 150);}      
        
    ofPoint up(a.x, a.y-(l*3/4), a.z);
    ofPoint down(a.x, a.y+(l*3/4), a.z);
    ofPoint front(a.x, a.y, a.z-(l*3/4));
    ofPoint back(a.x, a.y, a.z+(l*3/4));
    ofPoint left(a.x-(l*3/4), a.y, a.z);
    ofPoint right(a.x+(l*3/4), a.y, a.z);

        ofFill();
        ofDrawBox(a , l);

    if (side == 'b') {
        draw1(up, l/2, n-1, 'u');
        draw1(down, l/2, n-1, 'd');
        draw1(front, l/2, n-1, 'f');
        draw1(back, l/2, n-1, 'k');
        draw1(left, l/2, n-1, 'l');
        draw1(right, l/2, n-1, 'r');
        return; 
    }

    if (side != 'u') {draw1(down, l/2, n-1, 'd');}
    if (side != 'd') {draw1(up, l/2, n-1, 'u');}
    if (side != 'f') {draw1(back, l/2, n-1, 'k');}
    if (side != 'k') {draw1(front, l/2, n-1, 'f');}
    if (side != 'l') {draw1(right, l/2, n-1, 'r');}
    if (side != 'r') {draw1(left, l/2, n-1, 'l');}

    }

    void draw2(ofPoint a, float l, int n){
    
    float  x = a.x;
    float  y = a.y;
    float  z = a.z;

    if (n==0) {return;}
    if ((n+2)%3 == 0) {ofSetColor(0, 75, 150);}
    else if ((n+1)%3 == 0) {ofSetColor(75, 0, 150);}
    else {ofSetColor(150, 0, 75);}      
        

    ofPoint b1(x-l, y, z+l);
    ofPoint b2(x+l, y, z-l);
    ofPoint b3(x+l, y, z+l);
    ofPoint b4(x-l, y, z-l);

    ofPoint c1(x, y+l, z+l);    
    ofPoint c2(x, y-l, z-l);
    ofPoint c3(x, y+l, z-l);
    ofPoint c4(x, y-l, z+l);

    ofPoint d1(x-l, y-l, z);
    ofPoint d2(x-l, y+l, z);
    ofPoint d3(x+l, y+l, z);
    ofPoint d4(x+l, y-l, z);

    ofDrawBox(b1, l/2, l*2.5, l/2);
    ofDrawBox(b2, l/2, l*2.5, l/2);
    ofDrawBox(b3, l/2, l*2.5, l/2);
    ofDrawBox(b4, l/2, l*2.5, l/2);

    ofDrawBox(c1, l*3/2, l/2, l/2);
    ofDrawBox(c2, l*3/2, l/2, l/2);
    ofDrawBox(c3, l*3/2, l/2, l/2);
    ofDrawBox(c4, l*3/2, l/2, l/2);
    
    ofDrawBox(d1, l/2, l/2, l*3/2);
    ofDrawBox(d2, l/2, l/2, l*3/2);
    ofDrawBox(d3, l/2, l/2, l*3/2);
    ofDrawBox(d4, l/2, l/2, l*3/2);

    draw2(a, l/2, n-1);
    }

    void draw3(ofPoint a, float l, int n){
    
    float  x = a.x;
    float  y = a.y;
    float  z = a.z;

    if (n==0) {return;}
    if ((n+2)%3 == 0) {ofSetColor(0, 75, 150);}
    else if ((n+1)%3 == 0) {ofSetColor(75, 0, 150);}
    else {ofSetColor(150, 0, 75);}      
        

    ofPoint b1(x-l, y, z+l);
    ofPoint b2(x+l, y, z-l);
    ofPoint b3(x+l, y, z+l);
    ofPoint b4(x-l, y, z-l);

    ofPoint c1(x, y+l, z+l);    
    ofPoint c2(x, y-l, z-l);
    ofPoint c3(x, y+l, z-l);
    ofPoint c4(x, y-l, z+l);

    ofPoint d1(x-l, y-l, z);
    ofPoint d2(x-l, y+l, z);
    ofPoint d3(x+l, y+l, z);
    ofPoint d4(x+l, y-l, z);

    ofDrawBox(b1, l/2, l*2.5, l/2);
    ofDrawBox(b2, l/2, l*2.5, l/2);
    ofDrawBox(b3, l/2, l*2.5, l/2);
    ofDrawBox(b4, l/2, l*2.5, l/2);

    ofDrawBox(c1, l*3/2, l/2, l/2);
    ofDrawBox(c2, l*3/2, l/2, l/2);
    ofDrawBox(c3, l*3/2, l/2, l/2);
    ofDrawBox(c4, l*3/2, l/2, l/2);
    
    ofDrawBox(d1, l/2, l/2, l*3/2);
    ofDrawBox(d2, l/2, l/2, l*3/2);
    ofDrawBox(d3, l/2, l/2, l*3/2);
    ofDrawBox(d4, l/2, l/2, l*3/2);

    

    a.x += l/2;
    a.y += l/2;
    a.z += l/2;
    draw3(a, l/5, n-1);

    a.x -=l;

    draw3(a, l/5, n-1);

    a.y -= l;

    draw3(a, l/5, n-1);

    a.x += l;

    draw3(a, l/5, n-1);

    a.z -=l;

    draw3(a, l/5, n-1);

    a.x -=l;

    draw3(a, l/5, n-1);

    a.y += l;

    draw3(a, l/5, n-1);

    a.x +=l;

    draw3(a, l/5, n-1);
    }

    void draw4(ofPoint a, float l, int n){

    if (n == 0) {return;}
    else if (n == 1) {
        ofSetColor(0, 0, 155);
        ofFill();
        ofDrawBox(a, l);
        return;
    }

    else {
        
        float x = a.x;
        float y = a.y;
        float z = a.z;

        ofPoint b(x+l/3, y, z+l/3);
        ofPoint c(x, y+l/3, z+l/3);
        ofPoint d(x-l/3, y, z+l/3);
        ofPoint e(x, y-l/3, z+l/3);
        ofPoint f(x+l/3, y+l/3, z+l/3);
        ofPoint g(x-l/3, y+l/3, z+l/3);
        ofPoint h(x+l/3, y-l/3, z+l/3);
        ofPoint i(x-l/3, y-l/3, z+l/3);
        
        draw4(b, l/3, n-1);
        draw4(c, l/3, n-1);
        draw4(d, l/3, n-1);
        draw4(e, l/3, n-1);
        draw4(f, l/3, n-1);
        draw4(g, l/3, n-1);
        draw4(h, l/3, n-1);
        draw4(i, l/3, n-1);

        b.z -= l*2/3;
        c.z -= l*2/3;
        d.z -= l*2/3;
        e.z -= l*2/3;
        f.z -= l*2/3;
        g.z -= l*2/3;
        h.z -= l*2/3;
        i.z -= l*2/3;

        draw4(b, l/3, n-1);
        draw4(c, l/3, n-1);
        draw4(d, l/3, n-1);
        draw4(e, l/3, n-1);
        draw4(f, l/3, n-1);
        draw4(g, l/3, n-1);
        draw4(h, l/3, n-1);
        draw4(i, l/3, n-1);

        f.z+= l/3;
        g.z+= l/3;
        h.z+= l/3;
        i.z+= l/3;

        draw4(f, l/3, n-1);
        draw4(g, l/3, n-1);
        draw4(h, l/3, n-1);
        draw4(i, l/3, n-1);
    }
}

    void draw5(ofPoint a, float l, int n) {

        if (n == 0) {return;}

        float x = a.x;
        float y = a.y;
        float z = a.z;
        ofFill();
        if ((n+2)%3 == 0) {ofSetColor(0, 75, 150);}
        else if ((n+1)%3 == 0) {ofSetColor(75, 0, 150);}
        else {ofSetColor(150, 0, 75);}   

        ofDrawBox(a, l*2);

        ofPoint c(x- l/2, y + l + l/2, z-l/2);
        ofPoint d(x+ l + l/2, y-l/2, z-l/2);
        ofPoint e(x- l/2, y- l/2, z+ l + l/2);   

        draw5(c, l/2, n-1);
        draw5(d, l/2, n-1);
        draw5(e, l/2, n-1);

    }


};
