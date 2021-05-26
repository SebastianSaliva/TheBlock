#pragma once
#include "Object.h"
#include "ActivatableObject.h"
#include "ActivatorObject.h"

class Player{

    public:
        ofPoint pos;
        
        int x;
        int y;

        int health;
        int speed;
        int size;
        
        Player(int xPos, int yPos, int health_, int speed_, int size_) {
            x = xPos;
            y = yPos;
            health = health_;
            speed = speed_;
            pos = ofPoint(xPos, yPos);
            size = size_;
        };
        Player(){
            x = 0;
            y = 0;
            health = 100;
            speed = 1;
            pos = ofPoint(0, 0);
            size = 50;
        };
        Player(int xPos, int yPos, int size_){
            x = xPos;
            y = yPos;
            health = 100;
            speed = 1;
            pos = ofPoint(x, y);
            size = size_;
        };

        float getDistanceTo(ofPoint objPos) {return -1;};

        void render(){
            render(ofColor::blue);
        }

        void render(ofColor color){
            ofSetColor(color);

            ofDrawRectangle(pos, size, size);

            ofSetColor(ofColor::magenta);
        }
        ofRectangle getBounds(){
            return ofRectangle(pos, size, size);
        }
        bool collides(ofRectangle obj){
            return getBounds().intersects(obj);
        }



};