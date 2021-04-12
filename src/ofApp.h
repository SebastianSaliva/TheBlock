#pragma once
#include<cmath>

#include "ofMain.h"

#include "FractalMode.h"
#include "DrawMode1.h"
#include "DrawMode2.h"
#include "DrawMode3.h"
#include "KochSnowFlake.h"
#include "CustomMode1.h"
#include "CustomMode2.h"
#include "CustomMode3.h"
#include "CustomMode4.h"
#include "CustomMode5.h"



class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void drawOmega();
		vector<FractalMode*> ModeVector{new DrawMode1(), new DrawMode2(), new DrawMode3(), new KochSnowFlake(), new CustomMode1(), new CustomMode2(),new CustomMode3(),new CustomMode4(),new CustomMode5()};

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





};
