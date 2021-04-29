#pragma once
#include<cmath>

#include "ofMain.h"

#include "ofxGui.h"

#include "FractalMode.h"
#include "DrawMode1.h"
#include "DrawMode2.h"
#include "DrawMode3.h"
#include "KochSnowFlake.h"
#include "CustomMode1.h"
#include "CustomMode2.h"
#include "FlowerOfLife.h"



class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void drawOmega();
		vector<FractalMode*> ModeVector{new DrawMode1(), new DrawMode2(), new DrawMode3(), new KochSnowFlake(), new CustomMode1(), new CustomMode2(), new FlowerOfLife() };

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
		void angleGenerator();
		void colorGenerator();

	private:
		int depth = 5;
		int kochDepth = 0;
		int treeAngle = 0;
		int tick = 0;
		int coef = 60;
		bool animationIsActive = false;
		int framesSinceAnimationWasActive = 0;
		int animSpeed = 1;
		ofColor colorful;

		bool omegaAnimationIsPlaying = false;
		int omegaFrames = 0;
		int frameCount= 0;
		ofSoundPlayer song;
		ofxPanel gui;

		ofxPanel colorpanel;

		ofxPanel mode1gui;

		ofParameter <ofVec3f> uiPosition;
		ofParameter <ofVec3f> fractalPosition;
		ofParameter <ofVec2f> mode1Position;
		ofParameter <float> fractalSize;
		ofParameter <int> camDistance;
		ofxButton resetcam;
		ofxButton randomizeFractal;
		ofEasyCam camera;
		ofLight light;
		ofxToggle ignoreCamScroll;
		ofxToggle showLight;
		ofxToggle f1;
		ofxToggle f2;
		ofxToggle f3;
		ofxToggle f4;
		ofxToggle f5;
		ofxToggle f6;
		ofxToggle f7;
		ofxToggle f8;
		ofxToggle f9;
		ofxToggle f10;

		ofParameter <ofColor> color1;
		ofParameter <ofColor> color2;
		ofParameter <ofColor> color3;
		vector<int> numbers= {1, 0, 1, 0, 1, 0, 1, 0 , 1, 1, 0, 1, 0, 1, 0, 1, 0 , 1, 1, 0, 1, 0, 1, 0, 1, 0 , 1};

		vector<int> sponge = {

		1, 1, 1,
		1, 0, 1,
		1, 1, 1,

		1, 0, 1,
		0, 0, 0,
		1, 0 ,1,

		1, 1, 1,
		1, 0, 1,
		1, 1, 1,

		};

		vector<int> test1 = {

		0, 0, 0,
		0, 1, 0,
		0, 0, 0,

		0, 1, 0,
		1, 1, 1,
		0, 1, 0,

		0, 0, 0,
		0, 1, 0,
		0, 0, 0,

		};

		vector<int> test2 = {

		1, 0, 1,
		0, 0, 0,
		1, 0, 1,

		0, 0, 0,
		0, 1, 0,
		0, 0, 0,

		1, 0, 1,
		0, 0, 0,
		1, 0, 1,

		};


		vector<int> test3 = {

		0, 0, 0,
		0, 1, 0,
		0, 0, 0,

		0, 1, 0,
		1, 1, 1,
		0, 1, 0,

		1, 1, 1,
		1, 1, 1,
		1, 1, 1,

		};

		ofParameter <float> mode1Size;
		ofxToggle m1;
		ofxToggle m2;
		ofxToggle m3;
		ofxToggle m4;
		ofxToggle m5;
		ofxToggle m6;

		ofxPanel fractal10gui;
		ofxButton updateFractal10;
		ofxToggle u1;
		ofxToggle u2;
		ofxToggle u3;
		ofxToggle u4;
		ofxToggle u5;
		ofxToggle u6;
		ofxToggle u7;
		ofxToggle u8;
		ofxToggle u9;
		ofxToggle i1;
		ofxToggle i2;
		ofxToggle i3;
		ofxToggle i4;
		ofxToggle i5;
		ofxToggle i6;
		ofxToggle i7;
		ofxToggle i8;
		ofxToggle i9;
		ofxToggle o1;
		ofxToggle o2;
		ofxToggle o3;
		ofxToggle o4;
		ofxToggle o5;
		ofxToggle o6;
		ofxToggle o7;
		ofxToggle o8;
		ofxToggle o9;
		vector<int> fractal10nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		vector<ofxToggle> fractal10toggles;
	
};
