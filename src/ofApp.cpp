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

    int y = 25;

    ofDrawBitmapString("Active Modes:", 0, 10);

    for (FractalMode* mode: ModeVector) {if(mode->getActive()) {ofDrawBitmapString(mode->getName(), 0, y); y+= 15;}}

    if (ModeVector[0]->getActive()){
        DrawMode1* mode = dynamic_cast<DrawMode1*>(ModeVector[0]);
        mode->draw(ofGetWidth()/2, ofGetHeight()/2,  4 + depth);
    }
    if (ModeVector[1]->getActive()){
        DrawMode2* mode = dynamic_cast<DrawMode2*>(ModeVector[0]);
        mode->draw(200, 4 + depth, ofGetWidth()/2, ofGetHeight()-50, 30);
    }
    if (ModeVector[2]->getActive()){
        DrawMode3* mode = dynamic_cast<DrawMode3*>(ModeVector[0]);
        mode->draw(ofGetWidth() / 2 - ofGetHeight() / 4, 10, ofGetHeight() / 2, 4 + depth);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // This method is called automatically when any key is pressed
    switch(key){
        case '1':
            ModeVector[0]->setActive(!ModeVector[0]->getActive());
            break;
        case '2':
            ModeVector[1]->setActive(!ModeVector[1]->getActive());
            break;
        case '3':
            ModeVector[2]->setActive(!ModeVector[2]->getActive());
            break;
        case '4':
            //ModeVector[0]->setActive(!ModeVector[0]->getActive());
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