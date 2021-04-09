#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSetBackgroundColor(0,0,0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    ofNoFill();
    ofSetColor(255);
    ofDrawBitmapString("Depth: "+ to_string(depth+4), ofGetWidth()/2 -20 , ofGetHeight()-10);


    if (mode1IsActive){
        drawMode1(ofGetWidth()/2, ofGetHeight()/2,  4 + depth);
    }
    if (mode2IsActive){
        drawMode2(200, 4 + depth, ofGetWidth()/2, ofGetHeight()-50, 30);
    }
    if(mode3IsActive){
        drawMode3(ofGetWidth() / 2 - ofGetHeight() / 4, 10, ofGetHeight() / 2, 4 + depth);
    }
    // if(mode4IsActive)
    //     drawMode1(ofGetWidth()/2, ofGetHeight()/2, 4);
    // }
    
}
void ofApp::drawMode1(int x, int y, int n){
    // ofSetColor(pow(n,3) + 100, abs(sin(n*90))*255, pow(n, 2) * 20); //ehhh
    
    //ofSetColor(n * 30 + 100, n%2 * 155 , pow(n, 2) * 2 + 100);

    //ofSetColor(pow(n, 2)* 5, x*20+ 100, n%2 * 255);

    if ((n+2)%3 == 0) {ofSetColor(255, 0, 0);}
    else if ((n+1)%3 == 0) {ofSetColor(0, 255, 0);}
    else {ofSetColor(0, 0, 255);}

    if(n>0){
        ofDrawCircle(x, y, n*10 );
        drawMode1(x+100, y, n-1);
        drawMode1(x-100, y, n-1);
        drawMode1(x, y+100, n-1);
        drawMode1(x, y-100, n-1);
    }
}
void ofApp::drawMode2(int length, int n, int x, int y, int d){
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

        drawMode2(length/2, n-1,rightBranchX,rightBranchY, 30);
        drawMode2(length/2,n-1,leftBranchX,leftBranchY, 30);
    }
    
}

void ofApp::drawMode3(float x, float y, float size, int n){
    
    if ((n+2)%3 == 0) {ofSetColor(255, 0, 0);}
    else if ((n+1)%3 == 0) {ofSetColor(0, 255, 0);}
    else {ofSetColor(0, 0, 255);}

    if(n <= 0) {
        return;
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofDrawTriangle(a, b, c);

    drawMode3(x, y, size / 2, n - 1);
    drawMode3((a.x + b.x) / 2, (a.y + b.y) / 2, size / 2, n - 1);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // This method is called automatically when any key is pressed
    switch(key){
        case '1':
            mode1IsActive = !mode1IsActive;
            break;
        case '2':
            mode2IsActive = !mode2IsActive;
            break;
        case '3':
            mode3IsActive = !mode3IsActive;
            break;
        case '4':
            mode4IsActive = !mode4IsActive;
            break;
        case '-':
            if (depth > -4){
            depth -= 1;}
            break;

        case '=':
            depth += 1;
            break;

            
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}