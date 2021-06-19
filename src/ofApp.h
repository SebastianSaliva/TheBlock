#pragma once
#include<cmath>

#include "ofMain.h"
#include "ofxGui.h"
#include "Level.h"
#include "Player.h"
#include "Object.h"
#include "ActivatableObject.h"
#include "ActivatorObject.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void movePlayer();
		void saveLevel();
		void saveLevelAsVectors();
		Level makeLevel(string levelName);
		Level makeLevel(vector<ofPoint> coords, vector<ofColor> colorsForCoords);

		int scale = 50;
		vector<string> levelNames = {"2435.txt", "6.png", "7.png", "3.png", "4.png"}; int levelId = 0;

	private:
		Level buildingLevel;
		ofColor selectedColor;	
		vector<ofPoint> coords;
		vector<ofColor> colorsForCoords;
		ofstream savedCoordsAndColors;
		Level currentLevel;
		bool building = false;

// colors
		ofColor player1Color = ofColor(0, 255, 0);
		ofColor player2Color = ofColor(0, 0, 255);
        ofColor endOfLevelColor = ofColor(0, 255, 255);
		ofColor boundsColor = ofColor(255);
		ofColor boundsForP1Color = ofColor(200, 255, 200);
		ofColor boundsForP2Color = ofColor(200, 200, 255);
		ofColor spikesColor = ofColor(255,0,0);
     	ofColor deadlySpikesColor = ofColor(100,0,0);
		ofColor wallsOnColor = ofColor(150);
		ofColor wallsOffColor = ofColor(75);
		ofColor wallSwitchColorIdle = ofColor(10, 125, 100);
		ofColor wallSwitchColorCanPress = ofColor(0, 255, 200);
        ofColor boxesColor = ofColor(75, 50, 25);
		ofColor	holdDownSpikesOnColor = ofColor(150, 50, 0);
		ofColor	holdDownSpikesOffColor = ofColor(50, 20, 0);
		ofColor	holdDownSpikesPadsOnColor = ofColor(150, 50, 100);
		ofColor	holdDownSpikesPadsOffColor = ofColor(175, 75, 125);

        ofColor upOnlyPassagesColor = ofColor(250,250,0);
        ofColor downOnlyPassagesColor = ofColor(200, 200, 0);
        ofColor leftOnlyPassagesColor = ofColor(150, 150, 0);
        ofColor rightOnlyPassagesColor = ofColor(100, 100, 0);

// levelVectors

vector<ofPoint> levelCoordsVec1 = {ofPoint(-4,-1), ofPoint(-4,-2), ofPoint(-4,-3), ofPoint(-4,-4), ofPoint(-3,-4), ofPoint(-2,-4), ofPoint(-1,-4), ofPoint(0,-4), ofPoint(2,-4), ofPoint(1,-4), ofPoint(3,-4), ofPoint(3,-3), ofPoint(3,-2), ofPoint(3,-1), ofPoint(3,0), ofPoint(3,1), ofPoint(3,2), ofPoint(3,3), ofPoint(2,3), ofPoint(1,3), ofPoint(0,3), ofPoint(-1,3), ofPoint(-2,3), ofPoint(-3,3), ofPoint(-4,3), ofPoint(-4,2), ofPoint(-4,0), ofPoint(-3,-3), ofPoint(-2,-3), ofPoint(-1,-3), ofPoint(-1,-2), ofPoint(-1,-1), ofPoint(-1,0), ofPoint(-1,1), ofPoint(-1,2), ofPoint(-2,0), ofPoint(-3,0), ofPoint(-3,2), ofPoint(2,2), ofPoint(0,-3), ofPoint(0,-2), ofPoint(0,-1), ofPoint(1,-1), ofPoint(2,-1), ofPoint(2,-3), ofPoint(0,2), ofPoint(1,2), ofPoint(1,1), ofPoint(2,1), ofPoint(-4,1)};
vector<ofColor> levelColorsVec1 = {ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(0,255,0), ofColor(0,0,255), ofColor(150,150,150), ofColor(150,150,150), ofColor(150,150,150), ofColor(150,150,150), ofColor(150,150,150), ofColor(150,150,150), ofColor(200,200,255), ofColor(200,200,255), ofColor(10,125,100), ofColor(175,75,125), ofColor(150,50,0), ofColor(150,50,0), ofColor(150,50,0), ofColor(150,50,0), ofColor(150,50,0), ofColor(0,255,255), ofColor(75,50,25), ofColor(200,255,200), ofColor(200,255,200), ofColor(200,255,200), ofColor(255,255,255)};

vector<ofPoint> levelCoordsVec2 = {ofPoint(-10,-10), ofPoint(-9,-10), ofPoint(-8,-10), ofPoint(-7,-10), ofPoint(-6,-10), ofPoint(-5,-10), ofPoint(-4,-10), ofPoint(-3,-10), ofPoint(-2,-10), ofPoint(-1,-10), ofPoint(0,-10), ofPoint(1,-10), ofPoint(2,-10), ofPoint(3,-10), ofPoint(4,-10), ofPoint(5,-10), ofPoint(6,-10), ofPoint(7,-10), ofPoint(8,-10), ofPoint(9,-10), ofPoint(9,-9), ofPoint(9,-8), ofPoint(9,-7), ofPoint(9,-6), ofPoint(9,-5), ofPoint(9,-4), ofPoint(9,1), ofPoint(9,-3), ofPoint(9,-2), ofPoint(9,-1), ofPoint(9,0), ofPoint(9,2), ofPoint(9,3), ofPoint(9,4), ofPoint(9,5), ofPoint(9,6), ofPoint(9,7), ofPoint(9,8), ofPoint(9,9), ofPoint(8,9), ofPoint(7,9), ofPoint(6,9), ofPoint(4,9), ofPoint(5,9), ofPoint(3,9), ofPoint(2,9), ofPoint(1,9), ofPoint(0,9), ofPoint(-1,9), ofPoint(-2,9), ofPoint(-3,9), ofPoint(-4,9), ofPoint(-5,9), ofPoint(-6,9), ofPoint(-7,9), ofPoint(-8,9), ofPoint(-9,9), ofPoint(-10,9), ofPoint(-10,8), ofPoint(-10,7), ofPoint(-10,6), ofPoint(-10,5), ofPoint(-10,4), ofPoint(-10,3), ofPoint(-10,2), ofPoint(-10,1), ofPoint(-10,0), ofPoint(-10,-1), ofPoint(-10,-2), ofPoint(-10,-3), ofPoint(-10,-4), ofPoint(-10,-5), ofPoint(-10,-6), ofPoint(-10,-7), ofPoint(-10,-8), ofPoint(-10,-9), ofPoint(-9,-9), ofPoint(8,8), ofPoint(8,5), ofPoint(7,5), ofPoint(7,6), ofPoint(7,7), ofPoint(8,7), ofPoint(-9,-8), ofPoint(-8,-8), ofPoint(-8,-7), ofPoint(-8,-6), ofPoint(-9,-6), ofPoint(-9,-7), ofPoint(8,6), ofPoint(-5,-9), ofPoint(-5,-8), ofPoint(-7,-8), ofPoint(6,7), ofPoint(4,8), ofPoint(4,7), ofPoint(-6,-6), ofPoint(5,5), ofPoint(-6,-2), ofPoint(5,1), ofPoint(-8,-5), ofPoint(-4,-5), ofPoint(-4,-6), ofPoint(-4,-7), ofPoint(3,4), ofPoint(3,5), ofPoint(3,6), ofPoint(7,4), ofPoint(-6,-4), ofPoint(-7,-7), ofPoint(-5,-7), ofPoint(-5,-6), ofPoint(-7,-6), ofPoint(-7,-5), ofPoint(-7,-4), ofPoint(-7,-3), ofPoint(-7,-2), ofPoint(-7,-1), ofPoint(-5,-1), ofPoint(-5,-2), ofPoint(-5,-3), ofPoint(-5,-4), ofPoint(-5,-5), ofPoint(-6,0), ofPoint(4,6), ofPoint(4,5), ofPoint(4,4), ofPoint(4,3), ofPoint(4,2), ofPoint(4,1), ofPoint(4,0), ofPoint(6,0), ofPoint(6,1), ofPoint(6,2), ofPoint(6,3), ofPoint(6,4), ofPoint(6,5), ofPoint(6,6), ofPoint(5,3), ofPoint(5,-1), ofPoint(-2,-2), ofPoint(1,-2), ofPoint(1,1), ofPoint(-2,1), ofPoint(-2,-1), ofPoint(-2,0), ofPoint(1,-1), ofPoint(1,0), ofPoint(-4,1), ofPoint(-4,-4), ofPoint(-7,0), ofPoint(-5,0), ofPoint(4,-1), ofPoint(6,-1), ofPoint(-1,1), ofPoint(0,1), ofPoint(-1,-2), ofPoint(0,-2), ofPoint(-1,-1), ofPoint(0,-1), ofPoint(0,0), ofPoint(-1,0), ofPoint(-7,1), ofPoint(-7,2), ofPoint(-5,1), ofPoint(-5,2), ofPoint(-3,-2), ofPoint(-4,-2), ofPoint(-2,2), ofPoint(2,1), ofPoint(3,1), ofPoint(1,-3), ofPoint(1,-4), ofPoint(-2,3), ofPoint(2,-4), ofPoint(3,-4), ofPoint(4,-4), ofPoint(6,-4), ofPoint(8,-4), ofPoint(7,-4), ofPoint(-3,3), ofPoint(-4,3), ofPoint(-5,3), ofPoint(-7,3), ofPoint(-8,3), ofPoint(-9,3), ofPoint(4,-3), ofPoint(4,-2), ofPoint(6,-3), ofPoint(6,-2), ofPoint(-6,3), ofPoint(5,-4)};
vector<ofColor> levelColorsVec2 = {ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(0,255,0), ofColor(0,0,255), ofColor(200,255,200), ofColor(200,255,200), ofColor(200,255,200), ofColor(200,255,200), ofColor(200,255,200), ofColor(200,200,255), ofColor(200,200,255), ofColor(200,200,255), ofColor(200,200,255), ofColor(200,200,255), ofColor(0,255,255), ofColor(0,255,255), ofColor(255,0,0), ofColor(255,0,0), ofColor(255,0,0), ofColor(255,0,0), ofColor(255,0,0), ofColor(255,0,0), ofColor(10,125,100), ofColor(10,125,100), ofColor(10,125,100), ofColor(10,125,100), ofColor(0,0,0), ofColor(0,0,0), ofColor(0,0,0), ofColor(0,0,0), ofColor(0,0,0), ofColor(0,0,0), ofColor(0,0,0), ofColor(0,0,0), ofColor(150,150,150), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(75,75,75), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(150,150,150), ofColor(75,75,75), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(200,200,255), ofColor(200,200,255), ofColor(200,255,200), ofColor(200,255,200), ofColor(0,0,0), ofColor(0,0,0), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(200,255,200), ofColor(200,255,200), ofColor(200,200,255), ofColor(200,200,255), ofColor(150,50,0), ofColor(150,50,0), ofColor(150,50,0), ofColor(150,50,0), ofColor(200,200,255), ofColor(200,200,255), ofColor(200,200,255), ofColor(200,200,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(200,255,200), ofColor(200,255,200), ofColor(200,255,200), ofColor(200,255,200), ofColor(200,255,200), ofColor(200,200,255)};

vector<ofPoint> levelCoordsVec5347 = {ofPoint(-3,-1), ofPoint(-3,-2), ofPoint(-3,-3), ofPoint(-2,-3), ofPoint(-1,-3), ofPoint(0,-3), ofPoint(1,-3), ofPoint(1,-2), ofPoint(1,-1), ofPoint(1,0), ofPoint(1,1), ofPoint(-1,1), ofPoint(-2,1), ofPoint(-3,1), ofPoint(-3,0), ofPoint(0,1), ofPoint(-2,-2), ofPoint(0,-2), ofPoint(-1,0)};
vector<ofColor> levelColorsVec5347 = {ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(255,255,255), ofColor(0,255,0), ofColor(0,0,255), ofColor(0,255,255)};

vector<vector<ofPoint>> levelCoords = {levelCoordsVec1, levelCoordsVec2, levelCoordsVec5347};
vector<vector<ofColor>> levelColors = {levelColorsVec1, levelColorsVec2, levelColorsVec5347};


};	
