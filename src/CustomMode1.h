#pragma once
#include "ofMain.h"
#include "string.h"
#include "FractalMode.h"

class CustomMode1: public FractalMode {

    public:
    ofColor color1;
    ofColor color2;
    ofColor color3;
    CustomMode1():FractalMode(){color1 = ofColor(255, 0, 0); color2 = ofColor(255, 0, 0); color3 = ofColor(255, 0, 0);}

    string getName() {return "Custom Mode 1";}

    void draw(){}

    void draw6(float x, float y, float l, int n) {draw6(x, y, l, n, "begin");}
    
    void draw6(float x, float y, float l, int n, string i) {
        ofFill();
        
        if ((n+2)%3 == 0) {ofSetColor(color1);}
        else if ((n+1)%3 == 0) {ofSetColor(color2);}
        else {ofSetColor(color3);}

        if (n==0){return;}

        ofDrawRectangle(x-l/2, y-l/2, l, l);

        if ((n+2)%3 == 0) {ofSetColor(color1.r, 0, 0);}
        else if ((n+1)%3 == 0) {ofSetColor(0, color2.r, 0);}
        else {ofSetColor(0, 0, color3.r);}

        ofDrawTriangle(x-l/2, y-l/2, x+l/2, y+l/2, x+l/2, y-l/2);

        if (i == "begin") {
        draw6(x-(l) +l/4 + 1, y, l/2, n-1, "left");
        draw6(x+(l) -l/4 + 1, y, l/2, n-1, "right");
        draw6(x, y-(l)+1 +l/4, l/2, n-1, "up");
        draw6(x, y+(l)+1 -l/4, l/2, n-1, "down");
        }

        if (!(i == "left")) {draw6(x+(l) -l/4 + 1, y, l/2, n-1, "right");}
        if (!(i== "right")) {draw6(x-(l) +l/4 + 1, y, l/2, n-1, "left");}
        if (!(i== "up")) {draw6(x, y+(l)+1 -l/4, l/2, n-1, "down");}
        if (!(i== "down")) {draw6(x, y-(l)+1 +l/4, l/2, n-1, "up");}
    }


void draw2(float x, float y, float l, int n, int colorLevel){

    if (n == 0){return;}

    ofColor first(colorLevel-50, 0, 0);
    ofColor second(colorLevel-100, 0, 0);
    ofColor third(colorLevel, 0, 0);

    float dis = sqrt(pow(l,2) - pow(l/2, 2));
    ofPoint a(x, y);
    ofPoint b(x-dis, y-l/2);
    ofPoint c(x, y-l);        
    ofPoint d(x+dis, y- l/2);
    ofPoint e(x+dis, y+ l/2);
    ofPoint f(x, y+l);
    ofPoint g(x-dis, y+l/2);
    
    ofFill();
    
    ofSetColor(first);
    ofDrawTriangle(a, b, c);
    ofDrawTriangle(a, c, d);

    ofSetColor(second);
    ofDrawTriangle(a, d, e);
    ofDrawTriangle(a, e, f);

    ofSetColor(third);
    ofDrawTriangle(a, f, g);
    ofDrawTriangle(a, g, b);
    
    draw2(a.x, a.y, l/1.5, n-1,colorLevel-20);
}


void draw2(float x, float y, float l, int n) {
    draw2(x, y, l, n, color1.r);
}

void draw3(ofPoint a, float l, int n) {

    if (!n) {return;}

    if ((n+2)%3 == 0) {ofSetColor(color1);}
    else if ((n+1)%3 == 0) {ofSetColor(color2);}
    else {ofSetColor(color3);}

    ofPoint b(a.x - l, a.y);
    ofPoint c(a.x + l, a.y);
    ofPoint d(a.x, a.y-l);
    ofPoint e(a.x, a.y+l);

    ofDrawLine(b, c);
    ofDrawLine(d,e);

    draw3(b, l/2, n-1);
    draw3(c, l/2, n-1);
    draw3(d, l/2, n-1);
    draw3(e, l/2, n-1);
}

void draw4(ofPoint point, float l, int n) {

    ofSetCircleResolution(128);

    if (!n) {return;}
    float x = point.x;
    float y = point.y;
    ofFill();

    ofPoint pupilLeft(x- l*6, y);

    ofPoint pupilRight(x+ l*6, y);

    ofSetColor(255);

    ofDrawEllipse(pupilLeft, l*9, l*1.5);
    ofDrawEllipse(pupilRight, l*9, l*1.5);

    ofSetColor(0);

    ofDrawCircle(pupilLeft, l*2);
    ofDrawCircle(pupilRight, l*2);

    ofSetColor(255);
    ofDrawCircle(ofPoint(pupilLeft.x+l, pupilLeft.y -l/2), l/8);
    ofDrawCircle(ofPoint(pupilRight.x+l, pupilRight.y -l/2), l/8);

    ofSetColor(100);
    ofDrawLine(ofPoint(x-3*l, y-3*l), ofPoint(x+3*l, y+3*l));
    ofDrawLine(ofPoint(x-6*l, y-3*l), ofPoint(x-6l, y+3*l));
    ofDrawLine(ofPoint(x, y-3*l), ofPoint(x+6*l, y+3*l));
    draw4(pupilLeft, l*2/10, n-1);
    draw4(pupilRight, l*2/10, n-1);

}

void draw5(ofPoint point, float l, int n) {

    ofFill();
    
    ofColor left(0, 0, 0);
    ofColor right(0, 0, 0);
    
    if (n%2 == 0) {left = color1; right = color2;}
    else {left = color2; right =color1;}


    float x = point.x;
    float y = point.y;

    if (!n) {return;}

    ofPoint pointtocall1(x - l, y - l/2);
    ofPoint pointtocall2(x + l, y + l/2);

    ofPoint a(x-l*2, y);
    ofPoint b(x-l, y + l);
    ofPoint c(x-l, y + l/2);
    
    ofPoint d(x+l*2, y);
    ofPoint e(x+l, y - l);
    ofPoint f(x+l, y - l/2);
    ofSetColor(left);
    ofDrawTriangle(a, b, c);
    ofDrawTriangle(point, b, c);
    ofSetColor(right);
    ofDrawTriangle(d, e, f);
    ofDrawTriangle(point, e, f);

    draw5(pointtocall1, l/2, n-1);
    draw5(pointtocall2, l/2, n-1);
}

void draw1(float x, float y, float l, int n){

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
        if ((n+2)%3 == 0) {ofSetColor(color1);}
        else if ((n+1)%3 == 0) {ofSetColor(color2);}
        else {ofSetColor(color3);}
    ofSetColor(color1);
    ofDrawTriangle(a, b, c);
    ofDrawTriangle(a, c, d);

    ofSetColor(color2);
    ofDrawTriangle(a, d, e);
    ofDrawTriangle(a, e, f);

    ofSetColor(color3);
    ofDrawTriangle(a, f, g);
    ofDrawTriangle(a, g, b);
    
    draw1(c.x, c.y, l/2, n-1);
    draw1(e.x, e.y, l/2, n-1);
    draw1(g.x, g.y, l/2, n-1);
}




};
