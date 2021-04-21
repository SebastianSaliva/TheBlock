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




class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void drawOmega();
		vector<FractalMode*> ModeVector{new DrawMode1(), new DrawMode2(), new DrawMode3(), new KochSnowFlake(), new CustomMode1(), new CustomMode2()};

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

	private:
		int depth = 5;
		bool animationIsActive = false;
		int framesSinceAnimationWasActive = 0;
		int animSpeed = 1;

		bool omegaAnimationIsPlaying = false;
		int omegaFrames = 0;
		int frameCount= 0;
		ofSoundPlayer song;
		ofxPanel gui;

		ofxPanel mode1gui;

		ofParameter <ofVec3f> uiPosition;
		ofParameter <ofVec3f> fractalPosition;

		ofParameter <float> fractalSize;
		ofParameter <int> camDistance;
		ofxButton resetcam;
		ofEasyCam camera;
		ofLight light;
		ofxToggle ignoreCamScroll;
		ofxToggle showLight;
		ofxToggle f1;
		ofxToggle f2;
		ofxToggle f3;
		ofxToggle f4;
		ofxToggle f5;

		ofParameter <float> mode1Size;


		ofxToggle m1;
		ofxToggle m2;
		ofxToggle m3;
		ofxToggle m4;
		ofxToggle m5;
		ofxToggle m6;
};
