
#pragma once
#include "ofApp.h"
#include "Player.h"
#include "Object.h"
#include "ActivatableObject.h"
#include "ActivatorObject.h"
#include <fstream>

//--------------------------------------------------------------

Level ofApp::makeLevel(vector<ofPoint> coords, vector<ofColor> colorsForCoords){
    
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
            else if (currentPixel == holdDownSpikesOnColor){ 
                levelInCreation.holdDownSpikes.push_back(new ActivatableObject(x*scale, y*scale, scale, scale, true));
            }
            else if (currentPixel == holdDownSpikesPadsOffColor){ 
                levelInCreation.holdDownSpikesPads.push_back(new ActivatorObject(x*scale, y*scale, scale, scale));
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
    // holdDownSpikesOnColor = ofColor(150, 50, 0);
    // holdDownSpikesOffColor = ofColor(50, 20, 0);
    // holdDownSpikesPadsOnColor = ofColor(150, 50, 100);
    // holdDownSpikesPadsOffColor = ofColor(175, 75, 125);

    if (levelName[levelName.size()-1] == 't'){

        vector<string> pairOfPoints;
        vector<ofPoint> pointsForLevelBeingCreated;
        vector<string> colorForPoint;       
        vector<ofColor> colorsForLevelBeingCreated;

        string line;
        ifstream myfile;
        myfile.open(levelName);
        getline(myfile, line);       
        stringstream  ss(line);
        string str;
        while (getline(ss, str, '/')) {
            pairOfPoints.push_back(str);
        }
        for (string pair: pairOfPoints){
            stringstream  ss2(pair);
            string str2;
            vector<string> point;
            while (getline(ss2, str2, ',')) {
            point.push_back(str2);
            }
            int x = stoi(point[0]);
            int y = stoi(point[1]);
            pointsForLevelBeingCreated.push_back(ofPoint(x, y));                        
        }            
        getline(myfile, line);
        stringstream  ss3(line);
        string str3;
        while (getline(ss3, str3, '/')) {
            colorForPoint.push_back(str3);
        }
        for (string c: colorForPoint){
            stringstream  ss4(c);
            string str4;
            vector<string> rgb;
            while (getline(ss4, str4, ',')) {
            rgb.push_back(str4);
            }
            int r = stoi(rgb[0]);
            int g = stoi(rgb[1]);
            int b = stoi(rgb[2]);
            colorsForLevelBeingCreated.push_back(ofColor(r, g, b));                        
        } 
        myfile.close();
    return makeLevel(pointsForLevelBeingCreated, colorsForLevelBeingCreated);
    }

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
            else if (currentPixel == holdDownSpikesOnColor){ 
                levelInCreation.holdDownSpikes.push_back(new ActivatableObject(x*scale, y*scale, scale, scale, true));
            }
            else if (currentPixel == holdDownSpikesPadsOnColor){ 
                levelInCreation.holdDownSpikesPads.push_back(new ActivatorObject(x*scale, y*scale, scale, scale));
            }
        }}
    levelInCreation.spawn1 = levelInCreation.player1->pos;
    levelInCreation.spawn2 = levelInCreation.player2->pos;

    return levelInCreation;  
};

void ofApp::saveLevel(){
    int n = ofRandom(0, 10000);
    string randomName = to_string(n) + ".txt";
    savedCoordsAndColors.open(randomName);

    for (ofPoint coord: coords){
        int x = coord.x, y = coord.y;
        string str = to_string(x) + "," + to_string(y) + "/";
        if (coord == coords.back()) {str.erase(str.size() - 1);}
        savedCoordsAndColors << str;
    } 
    savedCoordsAndColors << endl;
    int count = 0;         
    for (ofColor c: colorsForCoords){
        string str = to_string(c.r) + "," + to_string(c.g)  + "," + to_string(c.b) + "/";
        if (count == colorsForCoords.size()-1) {str.erase(str.size() - 1);}
        savedCoordsAndColors << str;
        count++;
    }

    savedCoordsAndColors.close();
    return;
}

void ofApp::saveLevelAsVectors(){
    int n = ofRandom(0, 10000);
    string randomName = to_string(n) + ".txt";
    savedCoordsAndColors.open(randomName);
    savedCoordsAndColors << "vector<ofPoint> levelCoordsVec"+to_string(n) + " = {";

    for (ofPoint coord: coords){
        int x = coord.x, y = coord.y;
        string str = "ofPoint(" + to_string(x) + "," + to_string(y) + "), ";
        if (coord == coords.back()) {str.erase(str.size() - 2, 2);}
        savedCoordsAndColors << str;
    }
    savedCoordsAndColors << "};" << endl << "vector<ofPoint> levelColorsVec"+to_string(n) + " = {";   

    for (ofColor c: colorsForCoords){
        string str = "ofColor(" + to_string(c.r) + "," + to_string(c.g)  + "," + to_string(c.b) + "), ";
        if (c == colorsForCoords.back()) {str.erase(str.size() - 2, 2);}
        savedCoordsAndColors << str;
    }
    savedCoordsAndColors << "};" << endl;
    savedCoordsAndColors.close();
    return;
}

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
            levelId++; if (levelId == levelNames.size() + levelCoords.size()) {levelId = 0;}
            
            if (levelId < levelNames.size()){
            currentLevel = makeLevel(levelNames[levelId]);
            }
            else {
                currentLevel = makeLevel(levelCoords[levelId - levelNames.size()], levelColors[levelId - levelNames.size()]);
            }
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

        ofDrawLine(-10*scale, count*scale, 10*scale, count*scale);
        ofDrawLine(count*scale, -10*scale, count*scale, 10*scale);
        count++;   
        }

        ofSetColor(255);
        ofDrawRectangle(-11*scale, -7*scale, scale/2, scale/2);
        ofSetColor(0);
        ofDrawRectangle(-11*scale+2, -7*scale+2, scale/2 -4, scale/2 -4);

        ofSetColor(boundsColor);
        ofDrawRectangle(-11*scale, -6*scale, scale/2, scale/2);
        ofSetColor(player1Color);
        ofDrawRectangle(-11*scale, -5*scale, scale/2, scale/2);
        ofSetColor(player2Color);
        ofDrawRectangle(-11*scale, -4*scale, scale/2, scale/2);
        ofSetColor(spikesColor);
        ofDrawRectangle(-11*scale, -3*scale, scale/2, scale/2);
        ofSetColor(deadlySpikesColor);
        ofDrawRectangle(-11*scale, -2*scale, scale/2, scale/2);
        ofSetColor(boundsForP1Color);
        ofDrawRectangle(-11*scale, -1*scale, scale/2, scale/2);
        ofSetColor(boundsForP2Color);
        ofDrawRectangle(-11*scale, 0*scale, scale/2, scale/2);
        ofSetColor(wallsOnColor);
        ofDrawRectangle(-11*scale, 1*scale, scale/2, scale/2);
        ofSetColor(wallsOffColor);
        ofDrawRectangle(-11*scale, 2*scale, scale/2, scale/2);
        ofSetColor(wallSwitchColorIdle);
        ofDrawRectangle(-11*scale, 3*scale, scale/2, scale/2);
        ofSetColor(boxesColor);
        ofDrawRectangle(-11*scale, 4*scale, scale/2, scale/2);
        ofSetColor(endOfLevelColor);
        ofDrawRectangle(-11*scale, 5*scale, scale/2, scale/2);
        ofSetColor(holdDownSpikesOnColor);
        ofDrawRectangle(-11*scale, 6*scale, scale/2, scale/2);      
        ofSetColor(holdDownSpikesPadsOffColor);
        ofDrawRectangle(-11*scale, 7*scale, scale/2, scale/2); 

        return;
    }

    if (currentLevel.isPlaying){
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
        if (key == '/') {buildingLevel.isPlaying = !buildingLevel.isPlaying; return;}
        if (key == '[') {buildingLevel = makeLevel(coords, colorsForCoords); return;}
        if (key == ']') {coords.clear(); colorsForCoords.clear(); buildingLevel = Level(); return;} 
        if (key == 'u') {coords.pop_back(); colorsForCoords.pop_back(); return;}

        if (key == '=') {
            saveLevelAsVectors();
        }

        if (key == '-') {
            saveLevel();
        }

        if (buildingLevel.isPlaying){buildingLevel.keyPressed(key);}
        return;
    }
    
    if (key == 'r') {currentLevel = makeLevel(levelNames[levelId]);}
    if (key == '0') {
        currentLevel.finished = 1;
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
    
    if(-11*scale + scale/2 >= x && x >= -11*scale &&  -7*scale + scale/2 >= y && y >= -10*scale){
        selectedColor = ofColor(0); return;  
    }
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  -6*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = boundsColor; return;    
    }      
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  -5*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = player1Color; return;
    }
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  -4*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = player2Color; return;
    }
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  -3*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = spikesColor; return;
    }
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  -2*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = deadlySpikesColor; return;
    }
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  -1*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = boundsForP1Color; return;
    }
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  0*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = boundsForP2Color; return;
    }
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  1*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = wallsOnColor; return;
    }
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  2*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = wallsOffColor; return;
    }
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  3*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = wallSwitchColorIdle; return;
    }
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  4*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = boxesColor; return;
    }
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  5*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = endOfLevelColor; return;
    }
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  6*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = holdDownSpikesOnColor; return;
    }
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  7*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = holdDownSpikesPadsOffColor; return;
    }
    else if(-11*scale + scale/2 >= x && x >= -11*scale &&  8*scale + scale/2 >= y && y >= -6*scale){
        selectedColor = ofColor(0); return;  
    }

        if (x<0){x = x/scale -1;}
        else {x = x/scale;}
        
        if (y<0){y = y/scale -1;}
        else {y = y/scale;}

        if (!(-10 <= x && x<= 10)) {return;} 
        if (!(-10 <= y && y<= 10)) {return;} 

        if (find(coords.begin(), coords.end(), ofPoint(x, y)) != coords.end()){
            for (int i = 0; i < coords.size(); i++) {

                if (coords[i] == ofPoint(x, y)) {
                    coords.erase(i + coords.begin());
                    colorsForCoords.erase(i+ colorsForCoords.begin());
                    }
                }
        }
        if (selectedColor == ofColor(0)) {return;}
        coords.push_back(ofPoint(x,y));
        colorsForCoords.push_back(selectedColor);
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

