#pragma once
#include "Object.h"
#include "Player.h"
#include "ActivatableObject.h"

class ActivatorObject{

    public:
        int framesSinceUsed = 0;
        bool active = false;
        bool p1canTurnOn = false;
        bool p2canTurnOn = false;
        bool pressed = false;
        ofPoint pos;
        int x;
        int y;
        int width;
        int height;
        int xspeed;
        int yspeed;
        
        ActivatorObject(int xPos, int yPos, int width_, int height_, int xspeed_ ,int yspeed_) {
            x = xPos;
            y = yPos;

            pos.x = x;
            pos.y = y;

            width = width_;
            height = height_;
            xspeed = xspeed_;
            yspeed = yspeed_;
        };
        ActivatorObject(int xPos, int yPos, int width_, int height_){
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
        void render(ofImage img){
            ofSetColor(255);
            img.draw(pos);
        }
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