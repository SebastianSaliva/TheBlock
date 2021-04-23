#pragma once
#include "ofMain.h"
#include "FractalMode.h"
#include "math.h"

class KochSnowFlake: public FractalMode {

    public:
    
    KochSnowFlake():FractalMode(){}

    string getName() {return "Koch Snowflake";}
    
    void draw(){}
    
    void draw(double x1, double y1, double x2, double y2, double angle, int n) {
        if(n==1){
            ofDrawLine(x1, y1, x2, y2);
        }
        else if(n==2){

            ofVec2f p1(x1, y1);
            ofVec2f p2(x2, y2);
            double angle1 = angle + 1.0472;
            double angle2 = angle1 + 4.18879;
            double segmentLength = (p1.distance(p2))/3.0;
            double x3, y3, x4, y4, x5, y5;
            
                x3 = x1 + (segmentLength*cos(angle));
                y3 = y1 - (segmentLength*sin(angle));
                x4 = x3 + (segmentLength*cos(angle1));
                y4 = y3 - (segmentLength*sin(angle1));
                x5 = x4 + (segmentLength*cos(angle2));
                y5 = y4 - (segmentLength*sin(angle2));

            ofSetColor(255, 0, 0);
            ofDrawLine(x1, y1, x3, y3);
            ofSetColor(0, 255, 0);
            ofDrawLine(x3, y3, x4, y4);
            ofSetColor(0, 0, 255);
            ofDrawLine(x4, y4, x5, y5);
            ofSetColor(200, 200, 0);
            ofDrawLine(x5, y5, x2, y2);
        }
        else if(n>2){
            ofVec2f p1(x1, y1);
            ofVec2f p2(x2, y2);
            double angle1 = angle + 1.0472;
            double angle2 = angle1 + 4.18879;
            double segmentLength = (p1.distance(p2))/3.0;
            double x3, y3, x4, y4, x5, y5;
            
                x3 = x1 + (segmentLength*cos(angle));
                y3 = y1 - (segmentLength*sin(angle));
                x4 = x3 + (segmentLength*cos(angle1));
                y4 = y3 - (segmentLength*sin(angle1));
                x5 = x4 + (segmentLength*cos(angle2));
                y5 = y4 - (segmentLength*sin(angle2));

            this->draw(x1, y1, x3, y3, angle, n - 1);
            this->draw(x3, y3, x4, y4, angle1, n - 1);
            this->draw(x4, y4, x5, y5, angle2, n - 1);
            this->draw(x5, y5, x2, y2, angle, n - 1);
            
        }
    }
};
