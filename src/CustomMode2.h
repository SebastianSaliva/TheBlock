#pragma once
#include "ofMain.h"
#include "string.h"
#include "FractalMode.h"

class CustomMode2: public FractalMode {

    public:

    CustomMode2():FractalMode(){}

    string getName() {return "Custom Mode 2 (3d fractals, only this mode will be drawn)";}
        ofColor color1;
    ofColor color2;
    ofColor color3;
    void draw(){}

    void draw1(ofPoint a, float l, int n){        
        ofEnableAlphaBlending();
        draw1(a, l, n, 'b');
        ofDisableAlphaBlending();
        }

    void draw1(ofPoint a, float l, int n, char side){

        ofNoFill();
        if (n==0) {return;}
        if ((n+2)%3 == 0) {ofSetColor(color1, 200);}
        else if ((n+1)%3 == 0) {ofSetColor(color1, 100);}
        else {ofSetColor(color1, 150);}      
        
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
    if ((n+2)%3 == 0) {ofSetColor(color1);}
    else if ((n+1)%3 == 0) {ofSetColor(color2);}
    else {ofSetColor(color3);}      
        

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
    if ((n+2)%3 == 0) {ofSetColor(color1);}
    else if ((n+1)%3 == 0) {ofSetColor(color2);}
    else {ofSetColor(color3);}      
        

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

    }


    void draw5(ofPoint a, float l, int n) {

        if (n == 0) {return;}

        float x = a.x;
        float y = a.y;
        float z = a.z;
        ofFill();
    
        if ((n+2)%3 == 0) {ofSetColor(color1);}
        else if ((n+1)%3 == 0) {ofSetColor(color2);}
        else {ofSetColor(color3);}   

        ofDrawBox(a, l*2);

        ofPoint c(x- l/2, y + l + l/2, z-l/2);
        ofPoint d(x+ l + l/2, y-l/2, z-l/2);
        ofPoint e(x- l/2, y- l/2, z+ l + l/2);   

        draw5(c, l/2, n-1);
        draw5(d, l/2, n-1);
        draw5(e, l/2, n-1);

    }

    void draw6(ofPoint a, float l, int n, vector<int> numbers){

    if (n == 0) {return;}
    else if (n == 1) {
        ofSetColor(color1);
        ofFill();
        ofDrawBox(a, l);
        return;
    }

    else {
        
        float x = a.x;
        float y = a.y;
        float z = a.z;
        float d = l/3; //how far to move

        if (numbers[0]) {
        ofPoint t1(x-d, y+d, z-d);
        draw6(t1, l/3, n-1, numbers);
        }          
        
        if (numbers[1]) {
        ofPoint t2(x, y+d, z-d);   
        draw6(t2, l/3, n-1, numbers);
        }        
         
        if (numbers[2]) {
        ofPoint t3(x+d, y+d, z-d);       
        draw6(t3, l/3, n-1, numbers);
        }    
        if (numbers[3]) {
        ofPoint t4(x-d, y+d, z);      
        draw6(t4, l/3, n-1, numbers);
        }    
        if (numbers[4]) {
        ofPoint t5(x, y+d, z);
        draw6(t5, l/3, n-1, numbers);
        }    
        if (numbers[5]) {
        ofPoint t6(x+d, y+d, z);
        draw6(t6, l/3, n-1, numbers);
        }    
        if (numbers[6]) {
        ofPoint t7(x-d, y+d, z+d); 
        draw6(t7, l/3, n-1, numbers);
        }    
        if (numbers[7]) {
        ofPoint t8(x, y+d, z+d);   
        draw6(t8, l/3, n-1, numbers);
        }    
        if (numbers[8]) {
        ofPoint t9(x+d, y+d, z+d);
        draw6(t9, l/3, n-1, numbers);
        }

        if (numbers[9]) {
        ofPoint m1(x-d, y, z-d);
        draw6(m1, l/3, n-1, numbers);
        }          
        
        if (numbers[10]) {
        ofPoint m2(x, y, z-d);   
        draw6(m2, l/3, n-1, numbers);
        }        
         
        if (numbers[11]) {
        ofPoint m3(x+d, y, z-d);       
        draw6(m3, l/3, n-1, numbers);
        }    
        if (numbers[12]) {
        ofPoint m4(x-d, y, z);      
        draw6(m4, l/3, n-1, numbers);
        }    
        if (numbers[13]) {
        ofPoint m5(x, y, z);
        draw6(m5, l/3, n-1, numbers);
        }    
        if (numbers[14]) {
        ofPoint m6(x+d, y, z);
        draw6(m6, l/3, n-1, numbers);
        }    
        if (numbers[15]) {
        ofPoint m7(x-d, y, z+d); 
        draw6(m7, l/3, n-1, numbers);
        }    
        if (numbers[16]) {
        ofPoint m8(x, y, z+d);   
        draw6(m8, l/3, n-1, numbers);
        }
        if (numbers[17]) {
        ofPoint m9(x+d, y, z+d);
        draw6(m9, l/3, n-1, numbers);
        }            

        if (numbers[18]) {
        ofPoint d1(x-d, y-d, z-d);
        draw6(d1, l/3, n-1, numbers);
        }          
        
        if (numbers[19]) {
        ofPoint d2(x, y-d, z-d);   
        draw6(d2, l/3, n-1, numbers);
        }        
         
        if (numbers[20]) {
        ofPoint d3(x+d, y-d, z-d);       
        draw6(d3, l/3, n-1, numbers);
        }    
        if (numbers[21]) {
        ofPoint d4(x-d, y-d, z);      
        draw6(d4, l/3, n-1, numbers);
        }    
        if (numbers[22]) {
        ofPoint d5(x, y-d, z);
        draw6(d5, l/3, n-1, numbers);
        }    
        if (numbers[23]) {
        ofPoint d6(x+d, y-d, z);
        draw6(d6, l/3, n-1, numbers);
        }    
        if (numbers[24]) {
        ofPoint d7(x-d, y-d, z+d); 
        draw6(d7, l/3, n-1, numbers);
        }    
        if (numbers[25]) {
        ofPoint d8(x, y-d, z+d);   
        draw6(d8, l/3, n-1, numbers);
        }    
        if (numbers[26]) {
        ofPoint d9(x+d, y-d, z+d);
        draw6(d9, l/3, n-1, numbers);
        }
    }
    }

};
