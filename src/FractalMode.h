#pragma once
#include "ofMain.h"

class FractalMode{

    public: 
        FractalMode(){

            color1 = ofColor(0);
            color2 = ofColor(0);
            color3 = ofColor(0);
            
        };
        virtual string getName();


        ofColor color1;
        ofColor color2;
        ofColor color3;

        bool isactive = false;
        virtual void draw();
        void setActive(bool var){isactive = var;}
        bool getActive(){return isactive;}

        void setColor1(ofColor c) {color1 = c;}
        void setColor2(ofColor c) {color2 = c;}       
        void setColor3(ofColor c) {color3 = c;}
};