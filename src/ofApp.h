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



class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
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
		int depth = 0;
		bool animationIsActive = false;
		int framesSinceAnimationWasActive = 0;
		int animSpeed = 1;
};
