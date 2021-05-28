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
		Level makeLevel(string levelName);
		Level makeBuildingLevel();
		vector<Object*> makeSquareBounds(int size);
		int scale = 50;
		vector<string> levelNames = {"1.png", "2.png", "3.png", "4.png"}; int levelId = 0;



	private:
		Level buildingLevel;
		ofColor selectedColor;	
		vector<ofPoint> coords;
		vector<ofColor> colorsForCoords;

		Level currentLevel;


		bool building = false;

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
		
};	
