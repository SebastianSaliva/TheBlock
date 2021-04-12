#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

    song.load("song.wav");
    song.setVolume(0.5);

}

//--------------------------------------------------------------
void ofApp::update(){
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSetBackgroundColor(0,0,0);
}


void ofApp::drawOmega(){
    ofSetColor(255);

    ofBackgroundGradient(ofColor(120), ofColor(0), OF_GRADIENT_CIRCULAR);
    ofDrawBitmapString("Press 0 to deactivate.", 0, 10);
    frameCount++;
    if ( omegaFrames == 18) {
        depth++;
        omegaFrames = -1;
    }

    if (depth == 8){depth = 0;}



    if (omegaFrames<9) {
    CustomMode2* mode = dynamic_cast<CustomMode2*>(ModeVector[5]);
    mode->draw(ofGetWidth()/2, ofGetHeight()/2 + ofGetHeight()/8, ofGetHeight()/3.5, depth);
    }
    else {

    CustomMode1* mode = dynamic_cast<CustomMode1*>(ModeVector[4]);
    mode->draw(ofGetWidth()/2, ofGetHeight()/2, (ofGetHeight()/5) , depth);

    }

    omegaFrames+=1;

    //ofDrawRectangle(40, 40, ofRandom(500), ofRandom(500));
}

//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */

    if (omegaAnimationIsPlaying) {drawOmega(); return;}




    ofNoFill();
    ofSetColor(255);


    ofDrawBitmapString("Depth: "+ to_string(depth), ofGetWidth()/2 -20 , ofGetHeight()-10); //prints depth


    if (!animationIsActive){
    ofDrawBitmapString("Press space to activate Basic animation", 0, ofGetHeight()-75); //prints depth
    ofDrawBitmapString("Press 0 to activate custom animation", 0, ofGetHeight()-60); //prints depth
    }
    else { 
        ofDrawBitmapString("Animation is active, speed: " + to_string(animSpeed), 0, ofGetHeight()-75);
        ofDrawBitmapString("To change speed press ~s~", 0, ofGetHeight()-60);
        ofDrawBitmapString("speed 1, depth changes every 2 seconds.", 0, ofGetHeight()-45);
        ofDrawBitmapString("speed 2, depth changes every second", 0, ofGetHeight()-30);
        ofDrawBitmapString("speed 3, depth changes every 0.6 seconds.", 0, ofGetHeight()-15);
        }

    int y = 25;
    int i = 1;
    ofDrawBitmapString("Modes", 0, 10);
    for (FractalMode* mode: ModeVector) {if(mode->getActive()) {ofSetColor(0,255,0);} else{ofSetColor(255,0,0);} ofDrawBitmapString("press "+to_string(i)+" : "+ mode->getName(), 0, y); y+= 15; i++;} //prints active modes


    if (animationIsActive) {

        framesSinceAnimationWasActive++;
        
        if (framesSinceAnimationWasActive%(120/animSpeed) == 0){

            if (depth != 8 ) {depth++;}
            else {depth = 0;}

        }
    }

    
    if (ModeVector[0]->getActive()){
        DrawMode1* mode = dynamic_cast<DrawMode1*>(ModeVector[0]);
        mode->draw(ofGetWidth()/2, ofGetHeight()/2, depth);
    }
    if (ModeVector[1]->getActive()){
        DrawMode2* mode = dynamic_cast<DrawMode2*>(ModeVector[1]);
        mode->draw(200,depth, ofGetWidth()/2, ofGetHeight()-50, ofRandom(30, 70));
    }
    if (ModeVector[2]->getActive()){
        DrawMode3* mode = dynamic_cast<DrawMode3*>(ModeVector[2]);
        mode->draw(ofGetWidth() / 2 - ofGetHeight() / 4, 10, ofGetHeight() / 2, depth);
    }

    if (ModeVector[3]->getActive()){
        KochSnowFlake* mode = dynamic_cast<KochSnowFlake*>(ModeVector[3]);
        mode->draw();
    }

    if (ModeVector[4]->getActive()){
        CustomMode1* mode = dynamic_cast<CustomMode1*>(ModeVector[4]);
        mode->draw(ofGetWidth()/2, ofGetHeight()/2, (ofGetHeight()/5) , depth);
    }
    
    if (ModeVector[5]->getActive()){
        CustomMode2* mode = dynamic_cast<CustomMode2*>(ModeVector[5]);
        mode->draw(ofGetWidth()/2, ofGetHeight()/2 + ofGetHeight()/8, ofGetHeight()/3.5, depth);
    }
    if (ModeVector[6]->getActive()){
        CustomMode3* mode = dynamic_cast<CustomMode3*>(ModeVector[6]);
        mode->draw();
    }
    if (ModeVector[7]->getActive()){
        CustomMode4* mode = dynamic_cast<CustomMode4*>(ModeVector[7]);
        mode->draw();
    }
    if (ModeVector[8]->getActive()){
        CustomMode5* mode = dynamic_cast<CustomMode5*>(ModeVector[8]);
        mode->draw();
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
            ModeVector[3]->setActive(!ModeVector[3]->getActive());
            break;

        case '5':
            ModeVector[4]->setActive(!ModeVector[4]->getActive());
            break;
        case '6':
            ModeVector[5]->setActive(!ModeVector[5]->getActive());
            break;
        case '7':
            ModeVector[6]->setActive(!ModeVector[6]->getActive());
            break;
        case '8':
            ModeVector[7]->setActive(!ModeVector[7]->getActive());
            break;
        case '9':
            ModeVector[8]->setActive(!ModeVector[8]->getActive());
            break;



        case '-':
            
            if (!animationIsActive){
                if (depth > 0){
                depth -= 1;}
            }
            break;

        case '=':
            
            if (!animationIsActive){
            depth += 1;
            }
            break;
        case ' ':
            
            if(animationIsActive){
                depth = 5;
                animationIsActive = false;
                break;
            }

            if(!animationIsActive){
                depth = 0;
                animationIsActive = true;
                framesSinceAnimationWasActive = 0;
            }

            break;
        
        case 's':
            if (animationIsActive){
                if (animSpeed < 3){
                animSpeed++;
                }
                else {animSpeed = 1;}
            }
            break;
            
        case '0':
            
            if (!omegaAnimationIsPlaying) {

                song.load("song.wav");
                song.play();
            depth = 0;
            frameCount = 25;
            omegaFrames = -6;
            omegaAnimationIsPlaying =true;

            }
            else {
            depth = 5;
            omegaFrames = 0;
            omegaAnimationIsPlaying = false;
            song.unload();

            }
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