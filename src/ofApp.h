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
		vector<Object*> makeSquareBounds(int size);
		int scale = 50; 



	private:
		Level level1;
		Level level2;
		Level level3;
		Level level4;
        



		Level currentLevel;
		vector<int> coords;
		vector<ofRectangle> rects;
		bool building = false;
		
};	
