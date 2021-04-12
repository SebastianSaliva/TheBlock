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


    ofDrawBitmapString("Depth: "+ to_string(depth+4), ofGetWidth()/2 -20 , ofGetHeight()-10); //prints depth

    if (animationIsActive){ 
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

            if (depth + 4 != 8 ) {depth++;}
            else {depth = -4;}

        }
    }

    
    if (ModeVector[0]->getActive()){
        DrawMode1* mode = dynamic_cast<DrawMode1*>(ModeVector[0]);
        mode->draw(ofGetWidth()/2, ofGetHeight()/2,  4 + depth);
    }
    if (ModeVector[1]->getActive()){
        DrawMode2* mode = dynamic_cast<DrawMode2*>(ModeVector[1]);
        mode->draw(200, 4 + depth, ofGetWidth()/2, ofGetHeight()-50, ofRandom(30, 70));
    }
    if (ModeVector[2]->getActive()){
        DrawMode3* mode = dynamic_cast<DrawMode3*>(ModeVector[2]);
        mode->draw(ofGetWidth() / 2 - ofGetHeight() / 4, 10, ofGetHeight() / 2, 4 + depth);
    }

    if (ModeVector[3]->getActive()){
        KochSnowFlake* mode = dynamic_cast<KochSnowFlake*>(ModeVector[3]);
        mode->draw();
    }

    if (ModeVector[4]->getActive()){
        CustomMode1* mode = dynamic_cast<CustomMode1*>(ModeVector[4]);
        mode->draw(ofGetWidth()/2, ofGetHeight()/2, (ofGetWidth()/4 + ofGetHeight()/4)/2 , 4 + depth);
    }
    
    if (ModeVector[5]->getActive()){
        CustomMode2* mode = dynamic_cast<CustomMode2*>(ModeVector[5]);
        mode->draw(ofGetWidth()/2, ofGetHeight()/2 + ofGetHeight()/8, ofGetHeight()/3.5, 4 + depth);
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


        case '-':
            
            if (!animationIsActive){
                if (depth > -4){
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
                depth = 0;
                animationIsActive = false;
                break;
            }

            if(!animationIsActive){
                depth = -4;
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