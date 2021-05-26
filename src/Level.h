#pragma once
#include "ofMain.h"
#include "Player.h"
#include "Object.h"
#include "ActivatableObject.h"
#include "ActivatorObject.h"

class Level{

    
    public:

Player* player1;
Player* player2;
ofPoint spawn1;
ofPoint spawn2;

vector<Object*> spikes;
vector<Object*> spikesButDeadlier;
//vector<Object*> deathItSelf;

vector<ActivatorObject*> wallSwitch;
vector<ActivatableObject*> walls;

vector <Object*> bounds;
Object* endOfLevel = new Object(0, 0, 50, 50);

bool p1tryToMoveUp = false;
bool p1tryToMoveDown = false;
bool p1tryToMoveLeft = false;
bool p1tryToMoveRight = false;
bool p2tryToMoveUp = false;
bool p2tryToMoveDown = false;
bool p2tryToMoveLeft = false;
bool p2tryToMoveRight = false;

bool isPlaying = false;
int finished = 0;
        
Level(){};


Level(vector<Object*> initialBounds, Player* player_1, Player* player_2){
    player1 = player_1;
    player2 = player_2;
    bounds = initialBounds;
    spawn1 = player1->pos;
    spawn2 = player2->pos;
};

void movePlayer1(){
    if (p1tryToMoveUp){
        player1->y -= player1->speed; player1->pos.y -= player1->speed;
        bool collideWithBounds = false;
        
        for (Object* obj: bounds) {
            if (player1->collides(obj->getBounds()) || player1->collides(player2->getBounds()))
            {player1->y += player1->speed; player1->pos.y += player1->speed; collideWithBounds = true; break;}
        }

        if (!collideWithBounds){
            for (ActivatableObject* w: walls){ 
                if (w->active){
                    if (player1->collides(w->getBounds()))
                    {player1->y += player1->speed; player1->pos.y += player1->speed; break;}
                }
            }
        }
    }

    if (p1tryToMoveDown) {
        player1->y += player1->speed; player1->pos.y += player1->speed;
        bool collideWithBounds = false;

        for (Object* obj: bounds) {
            if (player1->collides(obj->getBounds()) || player1->collides(player2->getBounds()))
            {player1->y -= player1->speed; player1->pos.y -= player1->speed; collideWithBounds = true; break;} 
            }

        if (!collideWithBounds){
            for (ActivatableObject* w: walls){ 
                if (w->active){
                    if (player1->collides(w->getBounds()))
                    {player1->y -= player1->speed; player1->pos.y -= player1->speed; break;}
                }
            }
        }
    }

    if (p1tryToMoveLeft) {
        player1->x -= player1->speed; player1->pos.x -= player1->speed;
        bool collideWithBounds = false;
        for (Object* obj: bounds) {
            if (player1->collides(obj->getBounds()) || player1->collides(player2->getBounds()))
            {player1->x += player1->speed; player1->pos.x += player1->speed; collideWithBounds = true; break;}
        }
        if (!collideWithBounds){
            for (ActivatableObject* w: walls){ 
                if (w->active){
                    if (player1->collides(w->getBounds()))
                    {player1->x += player1->speed; player1->pos.x += player1->speed; break;}
                }
            }
        }
    }

    if (p1tryToMoveRight) {
        player1->x += player1->speed; player1->pos.x += player1->speed;
        bool collideWithBounds = false;
        for (Object* obj: bounds) {
            if (player1->collides(obj->getBounds()) || player1->collides(player2->getBounds()))
            {player1->x -= player1->speed; player1->pos.x -= player1->speed; collideWithBounds = true; break;}
        }

        if (!collideWithBounds){
            for (ActivatableObject* w: walls){ 
                if (w->active){
                    if (player1->collides(w->getBounds()))
                    {player1->x -= player1->speed; player1->pos.x -= player1->speed; break;}
                }
            }
        }
    }
}

void movePlayer2(){
    if (p2tryToMoveUp){
        player2->y -= player2->speed; player2->pos.y -= player2->speed;
        bool collideWithBounds = false;
        
        for (Object* obj: bounds) {
            if (player2->collides(obj->getBounds()) || player2->collides(player1->getBounds()))
            {player2->y += player2->speed; player2->pos.y += player2->speed; collideWithBounds = true; break;}
        }

        if (!collideWithBounds){
            for (ActivatableObject* w: walls){ 
                if (w->active){
                    if (player2->collides(w->getBounds()))
                    {player2->y += player2->speed; player2->pos.y += player2->speed; break;}
                }
            }
        }
    }

    if (p2tryToMoveDown) {
        player2->y += player2->speed; player2->pos.y += player2->speed;
        bool collideWithBounds = false;

        for (Object* obj: bounds) {
            if (player2->collides(obj->getBounds()) || player2->collides(player1->getBounds()))
            {player2->y -= player2->speed; player2->pos.y -= player2->speed; collideWithBounds = true; break;} 
            }

        if (!collideWithBounds){
            for (ActivatableObject* w: walls){ 
                if (w->active){
                    if (player2->collides(w->getBounds()))
                    {player2->y -= player2->speed; player2->pos.y -= player2->speed; break;}
                }
            }
        }
    }

    if (p2tryToMoveLeft) {
        player2->x -= player2->speed; player2->pos.x -= player2->speed;
        bool collideWithBounds = false;
        for (Object* obj: bounds) {
            if (player2->collides(obj->getBounds()) || player2->collides(player1->getBounds()))
            {player2->x += player2->speed; player2->pos.x += player2->speed; collideWithBounds = true; break;}
        }
        if (!collideWithBounds){
            for (ActivatableObject* w: walls){ 
                if (w->active){
                    if (player2->collides(w->getBounds()))
                    {player2->x += player2->speed; player2->pos.x += player2->speed; break;}
                }
            }
        }
    }

    if (p2tryToMoveRight) {
        player2->x += player2->speed; player2->pos.x += player2->speed;
        bool collideWithBounds = false;
        for (Object* obj: bounds) {
            if (player2->collides(obj->getBounds()) || player2->collides(player1->getBounds()))
            {player2->x -= player2->speed; player2->pos.x -= player2->speed; collideWithBounds = true; break;}
        }

        if (!collideWithBounds){
            for (ActivatableObject* w: walls){ 
                if (w->active){
                    if (player2->collides(w->getBounds()))
                    {player2->x -= player2->speed; player2->pos.x -= player2->speed; break;}
                }
            }
        }
    }
}

void RespawnP1(){player1->pos = spawn1; player1->x = spawn1.x; player1->y = spawn1.y;}
void RespawnP2(){player2->pos = spawn2; player2->x = spawn2.x; player2->y = spawn2.y;}
void Respawn(){RespawnP1(); RespawnP2();}

void keyPressed(int key){
    // This method is called automatically when any key is pressed
    switch(key){
        case ' ':
            player1->speed = 5;
            break;
        case 'w':
            p1tryToMoveUp = true;
            break;
        case 's':
            p1tryToMoveDown = true;
            break;
        case 'd':
            p1tryToMoveRight = true;
            break;    
        
        case 'a':
            p1tryToMoveLeft = true;
            break;

        case '7':
            player2->speed = 5;
            break;
        case '8':
            p2tryToMoveUp = true;
            break;
        case '2':
            p2tryToMoveDown = true;
            break;
        case '6':
            p2tryToMoveRight = true;
            break;    
        
        case '4':
            p2tryToMoveLeft = true;
            break;

        case 'e':
            for (ActivatorObject* sw: wallSwitch){
                if (sw->p1canTurnOn) {
                sw->pressed = true;
                }            
            }
            break;
        case 'i':
            for (ActivatorObject* sw: wallSwitch){
                if (sw->p2canTurnOn) {
                sw->pressed = true;
                }            
            }
            break;
    }
}

void keyReleased(int key){

    switch(key){


        case ' ':
            player1->speed = 1;
            break;
        case 'w':
            p1tryToMoveUp = false;
            break;
        case 's':
            p1tryToMoveDown = false;
            break;
        case 'd':
            p1tryToMoveRight = false;
            break;

        case 'a':
            p1tryToMoveLeft = false;
            break;
        
        case '7':
            player2->speed = 1;
            break;
        case '8':
            p2tryToMoveUp = false;
            break;
        case '2':
            p2tryToMoveDown = false;
            break;
        case '6':
            p2tryToMoveRight = false;
            break;    
        
        case '4':
            p2tryToMoveLeft = false;
            break;
    }
}

void update(){

    if (player1->collides(endOfLevel->getBounds()) && player2->collides(endOfLevel->getBounds())) {finished = 1;} //checks that both players are on end pad

    for (Object* spike: spikes) {
        if (player1->collides(spike->getBounds())){RespawnP1();}; 
        if (player2->collides(spike->getBounds())){RespawnP2();};
    } //checks collisions with spikes

    for (Object* spike: spikesButDeadlier) {
        if (player1->collides(spike->getBounds()) || player2->collides(spike->getBounds())){Respawn();};
    } //checks collisions with spikes that kill both


    for (ActivatableObject* w: walls){         
        if (w->active){
            if (player1->collides(w->getBounds())){
                RespawnP1();
            }
            if (player2->collides(w->getBounds())){
                RespawnP2();
        }}
    }//checks to see if a player is inside a wall

    for (ActivatorObject* sw: wallSwitch){
        if (sw->framesSinceUsed == 0){
            if (sw->pressed) {
                for (ActivatorObject* sw: wallSwitch){ sw->framesSinceUsed = 60; sw->active = !sw->active; sw->pressed = false;}
                for (ActivatableObject* wall: walls){wall->active = !wall->active;}
                sw->p1canTurnOn = false;
                sw->p2canTurnOn = false;
                continue;
            }
            if (player1->collides(sw->getBounds())){
                sw->p1canTurnOn = true;
            }
            else{sw->p1canTurnOn = false;}
            
            if (player2->collides(sw->getBounds())){
                sw->p2canTurnOn = true;
            }
            else{sw->p2canTurnOn = false;}
        } 
        else {sw->framesSinceUsed--;}
    }//checks to see if wall switches can be turned on by either player

    movePlayer1();
    movePlayer2();
}

void draw(){
    ofSetBackgroundColor(0);
    endOfLevel->render(ofColor::gold); 

    for (Object* obj: bounds){obj->render();}



    bool eDrawn = false;
    bool iDrawn = false;
    bool drawWalls = false;

    ofSetColor(ofColor::green);
    for (ActivatorObject* sw: wallSwitch){
        if(!eDrawn){if (sw->p1canTurnOn){
            ofDrawBitmapString("press e to interact", -ofGetWidth()/2 + 2, 0); eDrawn = true;
        }}
        if(!iDrawn){if (sw->p2canTurnOn){
            ofDrawBitmapString("press i to interact", ofGetWidth()/2 -100, 0); iDrawn = true;
        }}
        if (sw->p1canTurnOn || sw->p2canTurnOn){sw->render(ofColor::green);}
        else {sw->render(ofColor::darkGreen);}
              
    }

    for (ActivatableObject* wall: walls){
        if (wall->active) {wall->render(ofColor::blueSteel);}
        else {wall->render(ofColor::darkGray);}
    }
    

   for (Object* spk: spikes) {spk->render(ofColor::red);}
   for (Object* spk: spikesButDeadlier) {spk->render(ofColor::darkRed);}

   player1->render(ofColor::lime);
   player2->render(ofColor::cyan);
}



};
