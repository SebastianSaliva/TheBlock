#pragma once
#include "ofMain.h"
#include "FractalMode.h"

class DrawMode2: public FractalMode {

    public:
    
    DrawMode2():FractalMode(){}

    string getName() {return "mode 2";}
    
    void draw(){}

    void draw(int length, int n, int x, int y, int d) {

        if ((n+2)%3 == 0) {ofSetColor(255, 0, 0);}
        else if ((n+1)%3 == 0) {ofSetColor(0, 255, 0);}
        else {ofSetColor(0, 0, 255);}

        if(n > 0){
            int middleY = y-length;
            int leftBranchX = x -length*cos(PI/180*d);
            int leftBranchY = middleY -length*sin(PI/180*d);
            int rightBranchX = x +length*cos(PI/180*d);
            int rightBranchY = middleY -length*sin(PI/180*d);

            ofDrawLine(x, y, x,y-length);
            ofDrawLine(x, y-length, rightBranchX, rightBranchY);
            ofDrawLine(x,y-length, leftBranchX, leftBranchY);

 

            this->draw(length/2, n-1,rightBranchX,rightBranchY, 30);
            this->draw(length/2,n-1,leftBranchX,leftBranchY, 30);
        }
    }
};
