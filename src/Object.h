#pragma once
#include "Player.h"
#include "ActivatableObject.h"
#include "ActivatorObject.h"

class Object{

    public:
        ofPoint pos;
        int x;
        int y;
        int width;
        int height;
        int xspeed;
        int yspeed;
        
        Object(int xPos, int yPos, int width_, int height_, int xspeed_ ,int yspeed_) {
            x = xPos;
            y = yPos;

            pos.x = x;
            pos.y = y;

            width = width_;
            height = height_;
            xspeed = xspeed_;
            yspeed = yspeed_;
        };
        Object(int xPos, int yPos, int width_, int height_){
            x = xPos;
            y = yPos;

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