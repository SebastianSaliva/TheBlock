#pragma once
#include "ofMain.h"

class FractalMode{

    public: 

        virtual string getName();
        FractalMode(){};
        bool isactive = false;
        virtual void draw();
        void setActive(bool var){isactive = var;}
        bool getActive(){return isactive;}

};