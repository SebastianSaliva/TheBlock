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

ofImage player1pic;
ofImage player2pic;


 
vector <Object*> bounds;
vector <Object*> upOnlyPassages;
vector <Object*> downOnlyPassages;
vector <Object*> leftOnlyPassages;
vector <Object*> rightOnlyPassages;
ofImage ArrowUpPic;
ofImage ArrowDownPic;
ofImage ArrowLeftPic;
ofImage ArrowRightPic;
vector <Object*> boundsForP1;
vector <Object*> boundsForP2;

vector <Object*> boxes;

vector<Object*> spikes;
vector<Object*> deadlySpikes;

vector<ActivatorObject*> holdDownSpikesPads;
vector<ActivatableObject*> holdDownSpikes;

vector<ActivatorObject*> wallSwitches;
vector<ActivatableObject*> walls;

vector<Object*> holdDownWallSwitches;
vector<ActivatableObject*> holdDownWalls;

vector<Object*> endOfLevel;

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



Level(){
player1pic.load("blockImages/player1.png");
player2pic.load("blockImages/player2.png");
ArrowUpPic.load("blockImages/ArrowUp.png");
ArrowDownPic.load("blockImages/ArrowDown.png");
ArrowLeftPic.load("blockImages/ArrowLeft.png");
ArrowRightPic.load("blockImages/ArrowRight.png");
player1 = new Player(0, 0, 50);
player2 = new Player(-50, -50, 50);
spawn1 = player1->pos;
spawn2 = player2->pos;
};

bool tryToMoveBox(int xMove, int yMove, Object*& box, Player* player){

        box->x += xMove;
        box->y += yMove;
        box->pos = ofPoint(box->x, box->y);

        vector<vector<Object*>> allBounds = {bounds, spikes, deadlySpikes};

        for (vector<Object*> bound: allBounds){
            for (Object* obj: bound) {
                if (box->collides(obj->getBounds())){
                    box->x -= xMove;
                    box->y -= yMove;
                    box->pos = ofPoint(box->x, box->y);
                    return false;
                    }
            }
        }
        
        Player* otherPlayer;
        if (player == player1){otherPlayer = player2;}
        else {otherPlayer = player1;}

        for (ActivatableObject* w: walls){ 
            if (w->active){
                if (box->collides(w->getBounds())){              
                box->x -= xMove;
                box->y -= yMove;
                box->pos = ofPoint(box->x, box->y);
                return false;
                }
            }
        }

        if (box->collides(otherPlayer->getBounds())){
                box->x -= xMove;
                box->y -= yMove;
                box->pos = ofPoint(box->x, box->y);
                return false;
        }

        for (Object* box2: boxes) {
            
            if (box == box2) {continue;}

            if (box->collides(box2->getBounds())){
                box->x -= xMove;
                box->y -= yMove;
                box->pos = ofPoint(box->x, box->y);
                return false;
                }
        }
        return true;
}

void movePlayerHelper(int xMove, int yMove,  Player*& player){

        player->x += xMove;
        player->y += yMove;
        player->pos = ofPoint(player->x, player->y);
  
        for (Object* obj: bounds) {
            if (player->collides(obj->getBounds())){
                player->x -= xMove;
                player->y -= yMove;
                player->pos = ofPoint(player->x, player->y);
                return;
                }
        }
        vector<vector<Object*>> passages;
        if (xMove < 0) {passages = {upOnlyPassages, downOnlyPassages, rightOnlyPassages};}
        else if (xMove > 0) {passages = {upOnlyPassages, downOnlyPassages, leftOnlyPassages};}
        else if (yMove < 0) {passages = {leftOnlyPassages, downOnlyPassages, rightOnlyPassages};}
        else {passages = {upOnlyPassages, leftOnlyPassages, rightOnlyPassages};}

        for (vector<Object*> passage: passages){
            for (Object* obj: passage) {
                if (player->collides(obj->getBounds())){
                    player->x -= xMove;
                    player->y -= yMove;
                    player->pos = ofPoint(player->x, player->y);
                    return;
                    }
                }            
        }


        Player* otherPlayer; vector<Object*> playerBounds;
        if (player == player1){otherPlayer = player2; playerBounds = boundsForP2;}
        else {otherPlayer = player1; playerBounds = boundsForP1;}

        for (Object* obj: playerBounds) {
            if (player->collides(obj->getBounds())){
                player->x -= xMove;
                player->y -= yMove;
                player->pos = ofPoint(player->x, player->y);
                return;
                }
        }

        for (ActivatableObject* w: walls){ 
            if (w->active){
                if (player->collides(w->getBounds())){              
                player->x -= xMove;
                player->y -= yMove;
                player->pos = ofPoint(player->x, player->y);
                return;
                }
            }
        }

        if (player->collides(otherPlayer->getBounds())){
                player->x -= xMove;
                player->y -= yMove;
                player->pos = ofPoint(player->x, player->y);
                return;
        }

        for (Object* box: boxes) {
            if (player->collides(box->getBounds())){
                
                bool boxCanMove = tryToMoveBox(xMove, yMove, box, player);

                if (!boxCanMove){
                    player->x -= xMove;
                    player->y -= yMove;
                    player->pos = ofPoint(player->x, player->y);
                    return;
                }
            }
        }


}

void movePlayer1(){
    if (p1tryToMoveUp){
        movePlayerHelper(0, -player1->speed, player1);
    }
    if (p1tryToMoveDown){
        movePlayerHelper(0, player1->speed, player1);
    }
    if (p1tryToMoveRight){
        movePlayerHelper(player1->speed, 0, player1);
    }
    if (p1tryToMoveLeft){
        movePlayerHelper(-player1->speed, 0, player1);
    }
}

void movePlayer2(){
    if (p2tryToMoveUp){
        movePlayerHelper(0, -player2->speed, player2);
    }
    if (p2tryToMoveDown){
        movePlayerHelper(0, player2->speed, player2);
    }
    if (p2tryToMoveRight){
        movePlayerHelper(player2->speed, 0, player2);
    }
    if (p2tryToMoveLeft){
        movePlayerHelper(-player2->speed, 0, player2);
    }
}

void RespawnP1(){player1->pos = spawn1; player1->x = spawn1.x; player1->y = spawn1.y;}

void RespawnP2(){player2->pos = spawn2; player2->x = spawn2.x; player2->y = spawn2.y;}

void Respawn(){RespawnP1(); RespawnP2();}

void keyPressed(int key){
    // This method is called automatically when any key is pressed
    switch(key){

        case ' ':
            player1->size = player1->size/2;
            player2->size = player2->size/2;        
            break;
        case 'x':
            player1->size = player1->size*2;
            player2->size = player2->size*2;
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

        case 't':
            p2tryToMoveUp = true;
            break;
        case 'g':
            p2tryToMoveDown = true;
            break;
        case 'h':
            p2tryToMoveRight = true;
            break;    
        
        case 'f':
            p2tryToMoveLeft = true;
            break;

        case 'e':
            for (ActivatorObject* sw: wallSwitches){
                if (sw->p1canTurnOn) {
                sw->pressed = true;
                return;
                }            
            }
            break;
        case 'i':
            for (ActivatorObject* sw: wallSwitches){
                if (sw->p2canTurnOn) {
                sw->pressed = true;
                return;
                }            
            }
            break;
    }
}

void keyReleased(int key){

    switch(key){

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
        case 't':
            p2tryToMoveUp = false;
            break;
        case 'g':
            p2tryToMoveDown = false;
            break;
        case 'h':
            p2tryToMoveRight = false;
            break;    
        
        case 'f':
            p2tryToMoveLeft = false;
            break;
    }
}

void update(){
    bool p1AtEnd = false;
    bool p2AtEnd = false;
    for (Object* end: endOfLevel){
        if (player1->collides(end->getBounds())){p1AtEnd = true;}
        if (player2->collides(end->getBounds())){p2AtEnd = true;}
    }
    if (p1AtEnd && p2AtEnd) {finished = 1; return;} //checks that both players are on end pad

    for (Object* spike: spikes) {
        if (player1->collides(spike->getBounds())){RespawnP1();}; 
        if (player2->collides(spike->getBounds())){RespawnP2();};
    } //checks collisions with spikes

    for (Object* spike: deadlySpikes) {
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

    for (ActivatorObject* sw: wallSwitches){
        if (sw->framesSinceUsed == 0){
            if (sw->pressed) {
                for (ActivatorObject* sw: wallSwitches){ sw->framesSinceUsed = 60; sw->active = false; sw->pressed = false; sw->p1canTurnOn = false; sw->p2canTurnOn = false;}
                for (ActivatableObject* wall: walls){wall->active = !wall->active;}
                sw->p1canTurnOn = false;
                sw->p2canTurnOn = false;
                break;
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


    int heldCount = 0;
    for (ActivatorObject* spikePad: holdDownSpikesPads){
        spikePad->active = (player1->collides(spikePad->getBounds()) || player2->collides(spikePad->getBounds()));
        if (spikePad->active) {heldCount++; continue;}
        
        for (Object* box: boxes) {
            spikePad->active = (box->collides(spikePad->getBounds()));
            if (spikePad->active) {heldCount++; break;}  
        }
    }
    for (ActivatableObject* spike: holdDownSpikes) {spike->active = (!(heldCount == holdDownSpikesPads.size()));
        if (spike->active){
            if (player1->collides(spike->getBounds())){RespawnP1();}
            if (player2->collides(spike->getBounds())){RespawnP2();}
        }           
    }

    movePlayer1();
    movePlayer2();
}
		ofColor player1Color = ofColor(0, 255, 0);
		ofColor player2Color = ofColor(0, 0, 255);
        ofColor endOfLevelColor = ofColor(0, 255, 255);
		ofColor boundsColor = ofColor(255);
		ofColor boundsForP1Color = ofColor(200, 255, 200);
		ofColor boundsForP2Color = ofColor(200, 200, 255);
		ofColor spikesColor = ofColor(255,0,0);
     	ofColor deadlySpikesColor = ofColor(100,0,0);
		ofColor wallsOnColor = ofColor(150);
		ofColor wallsOffColor = ofColor(75);
		ofColor wallSwitchColorIdle = ofColor(10, 125, 100);
		ofColor wallSwitchColorCanPress = ofColor(0, 255, 200);
        ofColor boxesColor = ofColor(75, 50, 25);
        ofColor holdDownSpikesOnColor = ofColor(150, 50, 0);
        ofColor holdDownSpikesOffColor = ofColor(50, 20, 0);
        ofColor holdDownSpikesPadsOnColor = ofColor(150, 50, 100);
        ofColor holdDownSpikesPadsOffColor = ofColor(175, 75, 125);

        ofColor upOnlyPassagesColor = ofColor(250,250,0);
        ofColor downOnlyPassagesColor = ofColor(200, 200, 0);
        ofColor leftOnlyPassagesColor = ofColor(150, 150, 0);
        ofColor rightOnlyPassagesColor = ofColor(100, 100, 0);




void draw(){
    ofSetBackgroundColor(0);

    for (Object* end: endOfLevel) {end->render(endOfLevelColor);} //renders end of level
    for (Object* bound: bounds){bound->render();} //renders bounds
    for (Object* bound: boundsForP1){bound->render(boundsForP1Color);} //renders bounds for p1
    for (Object* bound: boundsForP2){bound->render(boundsForP2Color);} //renders bounds for p2

    bool eDrawn = false;
    bool iDrawn = false;

    ofSetColor(255); 



    for (ActivatorObject* sw: wallSwitches){
        if(!eDrawn && sw->p1canTurnOn){
            ofDrawBitmapString("press e to interact", -ofGetWidth()/2 + 2, 0); eDrawn = true;
        }
        if(!iDrawn && sw->p2canTurnOn){
            ofDrawBitmapString("press i to interact", ofGetWidth()/2 -200, 0); iDrawn = true;
        }
    }

    if (eDrawn || iDrawn) {for (ActivatorObject* sw: wallSwitches){sw->render(wallSwitchColorCanPress);}}
    else {for (ActivatorObject* sw: wallSwitches){sw->render(wallSwitchColorIdle);}}

    for (ActivatableObject* wall: walls){
        if (wall->active) {wall->render(wallsOnColor);}
        else {wall->render(wallsOffColor);}
    }

    for (Object* spk: spikes) {spk->render(spikesColor);}
    for (Object* spk: deadlySpikes) {spk->render(deadlySpikesColor);}

    for (ActivatableObject* spike: holdDownSpikes) {
        if (spike->active) {spike->render(holdDownSpikesOnColor);}
        else {spike->render(holdDownSpikesOffColor);}
    }

    for (ActivatorObject* spikePad: holdDownSpikesPads){
        if (spikePad->active) {spikePad->render(holdDownSpikesPadsOnColor);}
        else {spikePad->render(holdDownSpikesPadsOffColor);}
    }
    for (Object* box: boxes){box->render(boxesColor);}

    for (Object* passage: upOnlyPassages){passage->render(ArrowUpPic);}
    for (Object* passage: downOnlyPassages){passage->render(ArrowDownPic);}
    for (Object* passage: leftOnlyPassages){passage->render(ArrowLeftPic);}
    for (Object* passage: rightOnlyPassages){passage->render(ArrowRightPic);}
    
    ofSetColor(255);    
    player1->render(player1pic);
    player2->render(player2pic);

    }



};
