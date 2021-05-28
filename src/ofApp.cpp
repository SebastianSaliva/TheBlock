
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

Level ofApp::makeBuildingLevel(){
    
    Level levelInCreation = Level();

    for (int i = 0; i < coords.size(); i++) {

            ofColor currentPixel = colorsForCoords[i];
            int x = coords[i].x; 
            int y = coords[i].y;

            if (currentPixel == ofColor(0)){continue;}

            else if (currentPixel == boundsColor){ 
                levelInCreation.bounds.push_back(new Object(x*scale, y*scale, scale, scale));
            }
            else if (currentPixel == player1Color){
                levelInCreation.player1 = new Player(x*scale, y*scale, scale);
                levelInCreation.spawn1 = levelInCreation.player1->pos;
            }
            else if (currentPixel == player2Color){
                levelInCreation.player2 = new Player(x*scale, y*scale, scale);
                levelInCreation.spawn2 = levelInCreation.player2->pos;
            }
            else if (currentPixel == spikesColor){
                levelInCreation.spikes.push_back(new Object(x*scale, y*scale, scale, scale));
            }
            else if (currentPixel == deadlySpikesColor){
                levelInCreation.deadlySpikes.push_back(new Object(x*scale, y*scale, scale, scale));
            }
            else if (currentPixel == endOfLevelColor){
                levelInCreation.endOfLevel.push_back(new Object(x*scale, y*scale, scale, scale));
            }
            else if (currentPixel == wallsOnColor){
                levelInCreation.walls.push_back(new ActivatableObject(x*scale, y*scale, scale, scale, true));
            } 
            else if (currentPixel == wallsOffColor){
                levelInCreation.walls.push_back(new ActivatableObject(x*scale, y*scale, scale, scale, false));
            }
            else if (currentPixel == wallSwitchColorIdle){
                levelInCreation.wallSwitches.push_back(new ActivatorObject(x*scale, y*scale, scale, scale));
            }
            else if (currentPixel == boundsForP1Color){ 
                levelInCreation.boundsForP1.push_back(new Object(x*scale, y*scale, scale, scale));
            }
            else if (currentPixel == boundsForP2Color){ 
                levelInCreation.boundsForP2.push_back(new Object(x*scale, y*scale, scale, scale));
            }
            else if (currentPixel == boxesColor){ 
                levelInCreation.boxes.push_back(new Object(x*scale, y*scale, scale, scale));
            }


    }
    return levelInCreation;
}

Level ofApp::makeLevel(string levelName){

    // colors 
    // player1Color = ofColor(0, 255, 0);
    // player2Color = ofColor(0, 0, 255);
    // endOfLevelColor = ofColor(0, 255, 255);
    // boundsColor = ofColor(255);
    // boundsForP1Color = ofColor(200, 255, 200);
    // boundsForP2Color = ofColor(200, 200, 255);
    // spikesColor = ofColor(255,0,0);
    // deadlySpikesColor = ofColor(100,0,0);
    // wallsOnColor = ofColor(150);
    // wallsOffColor = ofColor(75);
    // wallSwitchColorIdle = ofColor(10, 125, 100);
    // wallSwitchColorCanPress = ofColor(0, 255, 200);
    // boxesColor = ofColor(75, 50, 25);



    ofImage levelpicture;
    levelpicture.load(levelName);

    Level levelInCreation;
	ofPixels pixels = levelpicture.getPixels();    
    for (int i = 0; i < levelpicture.getWidth(); i++) {
        for (int j = 0; j < levelpicture.getHeight(); j++) {
            ofColor currentPixel = pixels.getColor(i, j);
            
            int x = i-levelpicture.getWidth()/2;
            int y = j-levelpicture.getHeight()/2;

            if (currentPixel == ofColor(0)){continue;}

            else if (currentPixel == boundsColor){ 
                levelInCreation.bounds.push_back(new Object(x*scale, y*scale, scale, scale));
            }
            else if (currentPixel == player1Color){
                levelInCreation.player1 = new Player(x*scale, y*scale, scale);
                levelInCreation.spawn1 = levelInCreation.player1->pos;
            }
            else if (currentPixel == player2Color){
                levelInCreation.player2 = new Player(x*scale, y*scale, scale);
                levelInCreation.spawn2 = levelInCreation.player2->pos;
            }
            else if (currentPixel == spikesColor){
                levelInCreation.spikes.push_back(new Object(x*scale, y*scale, scale, scale));
            }
            else if (currentPixel == deadlySpikesColor){
                levelInCreation.deadlySpikes.push_back(new Object(x*scale, y*scale, scale, scale));
            }
            else if (currentPixel == endOfLevelColor){
                levelInCreation.endOfLevel.push_back(new Object(x*scale, y*scale, scale, scale));
            }
            else if (currentPixel == wallsOnColor){
                levelInCreation.walls.push_back(new ActivatableObject(x*scale, y*scale, scale, scale, true));
            } 
            else if (currentPixel == wallsOffColor){
                levelInCreation.walls.push_back(new ActivatableObject(x*scale, y*scale, scale, scale, false));
            }
            else if (currentPixel == wallSwitchColorIdle){
                levelInCreation.wallSwitches.push_back(new ActivatorObject(x*scale, y*scale, scale, scale));
            }
            else if (currentPixel == boundsForP1Color){ 
                levelInCreation.boundsForP1.push_back(new Object(x*scale, y*scale, scale, scale));
            }
            else if (currentPixel == boundsForP2Color){ 
                levelInCreation.boundsForP2.push_back(new Object(x*scale, y*scale, scale, scale));
            }
            else if (currentPixel == boxesColor){ 
                levelInCreation.boxes.push_back(new Object(x*scale, y*scale, scale, scale));
            }

        }}
    levelInCreation.spawn1 = levelInCreation.player1->pos;
    levelInCreation.spawn2 = levelInCreation.player2->pos;

    return levelInCreation;  
};

void ofApp::setup(){

    ofSetBackgroundColor(ofColor::black);
    currentLevel = makeLevel(levelNames[levelId]);
    currentLevel.isPlaying = true;

}


//--------------------------------------------------------------
void ofApp::update(){
    
    if (building) { 
        
        if(buildingLevel.isPlaying) {buildingLevel.update();}
        return;

    }

    if (currentLevel.isPlaying) {
        currentLevel.update();
        if (currentLevel.finished) {
            levelId++; if (levelId == levelNames.size()) {levelId = 0;}
            currentLevel = makeLevel(levelNames[levelId]);
            }
        return;
    }
    else{
        currentLevel.isPlaying = true;
    }


}
//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(255);

    if (building) { 
        
        if (buildingLevel.isPlaying) {
            ofSetColor(ofColor::blue);
            ofDrawRectangle(500, 500, 10, 10);
            buildingLevel.draw(); return;}
        else {

            for (int i = 0; i < coords.size(); i++){
                ofSetColor(colorsForCoords[i]);
                ofDrawRectangle(coords[i].x*scale, coords[i].y*scale, scale, scale);
                
            }


        }



        int count = -10;
        while (count <= 10){
        ofSetColor(255);            
        if (count == 0) {ofSetColor(ofColor::red);}

        ofDrawLine(-1000, count*scale, 1000, count*scale);
        ofDrawLine(count*scale, -1000, count*scale, 1000);
        count++;   
        }

        ofSetColor(255);
        ofDrawRectangle(-10*scale, -6*scale, scale/2, scale/2);
        ofSetColor(0);
        ofDrawRectangle(-10*scale+2, -6*scale+2, scale/2 -4, scale/2 -4);

        ofSetColor(boundsColor);
        ofDrawRectangle(-10*scale, -5*scale, scale/2, scale/2);
        ofSetColor(player1Color);
        ofDrawRectangle(-10*scale, -4*scale, scale/2, scale/2);
        ofSetColor(player2Color);
        ofDrawRectangle(-10*scale, -3*scale, scale/2, scale/2);
        ofSetColor(spikesColor);
        ofDrawRectangle(-10*scale, -2*scale, scale/2, scale/2);
        ofSetColor(deadlySpikesColor);
        ofDrawRectangle(-10*scale, -1*scale, scale/2, scale/2);
        ofSetColor(boundsForP1Color);
        ofDrawRectangle(-10*scale, 0*scale, scale/2, scale/2);
        ofSetColor(boundsForP2Color);
        ofDrawRectangle(-10*scale, 1*scale, scale/2, scale/2);
        ofSetColor(wallsOnColor);
        ofDrawRectangle(-10*scale, 2*scale, scale/2, scale/2);
        ofSetColor(wallsOffColor);
        ofDrawRectangle(-10*scale, 3*scale, scale/2, scale/2);
        ofSetColor(wallSwitchColorIdle);
        ofDrawRectangle(-10*scale, 4*scale, scale/2, scale/2);
        ofSetColor(boxesColor);
        ofDrawRectangle(-10*scale, 5*scale, scale/2, scale/2);
        ofSetColor(endOfLevelColor);
        ofDrawRectangle(-10*scale, 6*scale, scale/2, scale/2);





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
    
    if (building) {    
        if (key == '/') {buildingLevel.isPlaying = !buildingLevel.isPlaying;}
        if (key == '[') {buildingLevel = makeBuildingLevel();}
        if (key == ']') {coords.clear(); colorsForCoords.clear(); buildingLevel = Level(); return;} 
        if (key == 'u') {coords.pop_back(); colorsForCoords.pop_back();}
        if (buildingLevel.isPlaying){buildingLevel.keyPressed(key);}
        return;
    }
    
    if (key == 'r') {currentLevel = makeLevel(levelNames[levelId]);}
    if (key == '0') {
            levelId++; if (levelId == levelNames.size()) {levelId = 0;}
            currentLevel = makeLevel(levelNames[levelId]);
    }
    currentLevel.keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (building){
        if (buildingLevel.isPlaying){buildingLevel.keyReleased(key);}
        return;
    }
    
    
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

    x -= ofGetWidth()/2;
    y -= ofGetHeight()/2;
    
    if(-10*scale + scale/2 >= x && x >= -10*scale &&  -6*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = 0; return;
    }
    else if(-10*scale + scale/2 >= x && x >= -10*scale &&  -5*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = boundsColor; return;
    }      
    else if(-10*scale + scale/2 >= x && x >= -10*scale &&  -4*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = player1Color; return;
    }
    else if(-10*scale + scale/2 >= x && x >= -10*scale &&  -3*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = player2Color; return;
    }
    else if(-10*scale + scale/2 >= x && x >= -10*scale &&  -2*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = spikesColor; return;
    }
    else if(-10*scale + scale/2 >= x && x >= -10*scale &&  -1*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = deadlySpikesColor; return;
    }
    else if(-10*scale + scale/2 >= x && x >= -10*scale &&  0*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = boundsForP1Color; return;
    }
    else if(-10*scale + scale/2 >= x && x >= -10*scale &&  1*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = boundsForP2Color; return;
    }
    else if(-10*scale + scale/2 >= x && x >= -10*scale &&  2*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = wallsOnColor; return;
    }
    else if(-10*scale + scale/2 >= x && x >= -10*scale &&  3*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = wallsOffColor; return;
    }
    else if(-10*scale + scale/2 >= x && x >= -10*scale &&  4*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = wallSwitchColorIdle; return;
    }
    else if(-10*scale + scale/2 >= x && x >= -10*scale &&  5*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = boxesColor; return;
    }
    else if(-10*scale + scale/2 >= x && x >= -10*scale &&  6*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = endOfLevelColor; return;
    }

        if (x<0){x = x/scale -1;}
        else {x = x/scale;}
        
        if (y<0){y = y/scale -1;}
        else {y = y/scale;}

        if (selectedColor == ofColor::black) {
            if (find(coords.begin(), coords.end(), ofPoint(x, y)) != coords.end()){
                for (int i = 0; i < coords.size(); i++) {

                    if (coords[i] == ofPoint(x, y)) {
                        coords.erase(i + coords.begin());
                        colorsForCoords.erase(i+ colorsForCoords.begin());
                        return;
                        }
                   }
            return;       
            
            }
        }



        if (!(find(coords.begin(), coords.end(), ofPoint(x, y)) != coords.end())){
        coords.push_back(ofPoint(x,y));
        colorsForCoords.push_back(selectedColor);
        }
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

