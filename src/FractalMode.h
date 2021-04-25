#pragma once
#include "ofMain.h"

class FractalMode{

    public: 
        FractalMode(){};
        virtual string getName();

        bool isactive = false;
        virtual void draw();
        void setActive(bool var){isactive = var;}
        bool getActive(){return isactive;}

};