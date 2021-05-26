#pragma once
#include "Object.h"
#include "Player.h"
#include "ActivatorObject.h"

class ActivatableObject{

    public:
        bool active = false;
        ofPoint pos = ofPoint(0, 0);
        int x;
        int y;
        int width;
        int height;
        int xspeed;
        int yspeed;
        
        ActivatableObject(int xPos, int yPos, int width_, int height_, int xspeed_ ,int yspeed_, bool active_) {
            x = xPos;
            y = yPos;

            pos.x = x;
            pos.y = y;
            active = active_;
            width = width_;
            height = height_;
            xspeed = xspeed_;
            yspeed = yspeed_;
        };
        ActivatableObject(int xPos, int yPos, int width_, int height_, bool active_){
            x = xPos;
            y = yPos;
            active = active_;
            pos.x = x;
            pos.y = y;

            width = width_;
            height = height_;
            xspeed = 0;
            yspeed = 0;
        };

        void render(){render(ofColor::white);}

        void render(ofColor color){
            ofSetColor(color);
            ofDrawRectangle(pos, width, height);
            ofSetColor(ofColor::magenta);

        }
        ofRectangle getBounds(){
            return ofRectangle(pos, width, height);
        }
        bool collides(ofRectangle obj){
            return getBounds().intersects(obj);
        }


};