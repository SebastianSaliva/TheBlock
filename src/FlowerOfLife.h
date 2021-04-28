#pragma once
#include "ofMain.h"
#include "FractalMode.h"
#include "math.h"

class FlowerOfLife : public FractalMode{
    public:
    ofColor color1;
    ofColor color2;
    ofColor color3;
    FlowerOfLife():FractalMode(){color1 = ofColor(255, 0, 0); color2 = ofColor(255, 0, 0); color3 = ofColor(255, 0, 0);}

    string getName() {return "Flower of Life";}
    
    void draw(){}

    void draw(double x1, double y1, double size, double distance, int n){
        if(n == 1){
        ofNoFill();
        ofDrawCircle(x1, y1, size);
        }
        else if(n>=2){
            ofDrawCircle(x1, y1, size);
            double x2, y2, x3, y3, x4, y4, x5, y5 , x6, y6, x7, y7;
            double angle30 = 0.523599;
            x2 = x1 + (distance*cos(angle30));
            y2 = y1 + (distance*sin(angle30));
            x3 = x1 + (distance*cos(3*angle30));
            y3 = y1 + (distance*sin(3*angle30));
            x4 = x1 + (distance*cos(5*angle30));
            y4 = y1 + (distance*sin(5*angle30));
            x5 = x1 + (distance*cos(7*angle30));
            y5 = y1 + (distance*sin(7*angle30));
            x6 = x1 + (distance*cos(9*angle30));
            y6 = y1 + (distance*sin(9*angle30));
            x7 = x1 + (distance*cos(11*angle30));
            y7 = y1 + (distance*sin(11*angle30));

            this->draw(x2, y2, size, distance, n-1);
            this->draw(x3, y3, size, distance, n-1);
            this->draw(x4, y4, size, distance, n-1);
            this->draw(x5, y5, size, distance, n-1);
            this->draw(x6, y6, size, distance, n-1);
            this->draw(x7, y7, size, distance, n-1);


        }

    }
};