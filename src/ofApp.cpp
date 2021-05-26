
#pragma once
#include "ofApp.h"
#include "Player.h"
#include "Object.h"
#include "ActivatableObject.h"
#include "ActivatorObject.h"


//--------------------------------------------------------------

vector<Object*> ofApp::makeSquareBounds(int size){

    	Object* obj1 = new Object(-scale*(size+1), -scale*(size+1), scale*(size+1)*2, scale);
		
        Object* obj2 = new Object(-scale*(size+1), -scale*(size+1), scale, scale*(size+1)*2);

        Object* obj3 = new Object(-scale*(size+1), scale*size, scale*(size+1)*2, scale);
 
        Object* obj4 = new Object(scale*size, -scale*(size+1), scale, scale*(size+1)*2 );

		vector<Object*> bounds = {obj1, obj2, obj3, obj4};
        return bounds;
}



void ofApp::setup(){

    ofSetBackgroundColor(ofColor::black);

        level1 = Level(makeSquareBounds(5), new Player(-scale*4, -scale*4, scale), new Player(scale*3, -scale*4, scale));

        level1.endOfLevel = new Object(-scale, scale*3, scale*2, scale*2);

        level1.spikes.push_back(new Object(-5*scale, -1*scale, 4*scale, 1*scale));

        level1.spikesButDeadlier.push_back(new Object(scale, -1*scale, 4*scale, 1*scale));

        level1.walls.push_back(new ActivatableObject(scale, -5*scale, scale, scale*4, false));
        level1.walls.push_back(new ActivatableObject(-scale, -scale, scale*2, scale, true));
        
        level1.wallSwitch.push_back(new ActivatorObject(4*scale, -2*scale, scale, scale));
        level1.wallSwitch.push_back(new ActivatorObject(-1*scale, -5*scale, 2*scale, scale));





    currentLevel = level1;
    currentLevel.isPlaying = true;

}





//--------------------------------------------------------------
void ofApp::update(){
    
    if (coords.size() == 4) { 
        coords.clear();
        rects.push_back(ofRectangle(coords[0]- ofGetWidth()/2, coords[1]- ofGetHeight()/2, coords[2] - coords[0], coords[3] - coords[1]));
    }

    if (currentLevel.isPlaying) {
        currentLevel.update();
        if (currentLevel.finished) {currentLevel.isPlaying = false;}
        return;
    }
    else{
    ofSetBackgroundColor(ofColor::green);
    }


}
//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(255);

    if (building) { 
        ofSetColor(ofColor::pink);
        int i = 10;
        for (ofRectangle rect: rects){      
            ofDrawRectangle(rect);
            ofDrawBitmapString("x: " + to_string(rect.x) + ". y: " + to_string(rect.y), 5, i);
            ofDrawBitmapString("w: " + to_string(rect.width) + ". h: " + to_string(rect.height), 5, i + 15);
            i+= 40;
        }
        return;
    }

    if (currentLevel.isPlaying) {
    currentLevel.draw();
    }
    else {
    ofSetBackgroundColor(ofColor::green);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'b') {building = !building; return;}
    if (key == 'n') {rects.clear(); coords.clear(); return;} 
    currentLevel.keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    currentLevel.keyReleased(key);
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
if (building) {
    coords.push_back(x);
    coords.push_back(y);
}
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

//--------------------------------------------------------------

