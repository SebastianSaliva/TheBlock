#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){

    song.load("song.wav");
    song.setVolume(0.5);
    gui.setup("Main 3d Menu");
    
    gui.add(showLight.setup("Show light source", true));
    gui.add(uiPosition.set("Light pos", ofVec3f(400, 400, 400), ofVec3f(-3000, -3000, -3000), ofVec3f(3000, 3000, 3000)));

    gui.add(fractalPosition.set("Fractal pos", ofVec3f(0, 0, 0), ofVec3f(-1500, -1500, -1500), ofVec3f(1500, 1500, 1500)));
    gui.add(fractalSize.set("size", 200, 0, 1000));
    
    gui.add(ignoreCamScroll.setup("Ignore cam distance", true));
    gui.add(camDistance.set("Cam distance", 1000, 0, 1500));

    gui.add(resetcam.setup("Reset cam"));

    gui.add(f1.setup("3dFractal 1", true));
    gui.add(f2.setup("3dFractal 2", false));
    gui.add(f3.setup("3dFractal 3", false));
    gui.add(f4.setup("3dFractal 4", false));
    gui.add(f5.setup("3dFractal 5", false));
    gui.add(f6.setup("3dFractal 6", false));
    gui.add(f7.setup("3dFractal 7", false));
    gui.add(f8.setup("3dFractal 8", false));
    gui.add(f9.setup("3dFractal 9", false));
    gui.add(randomizeFractal.setup("Randomize Fractal 9"));
    gui.add(f10.setup("3dFractal 10", false));

    fractal10gui.setup("Fractal 10 boxes");

    fractal10gui.add(updateFractal10.setup("update"));

    fractal10gui.add(u1.setup(false));
    fractal10gui.add(u2.setup(false));
    fractal10gui.add(u3.setup(false));
    fractal10gui.add(u4.setup(false));
    fractal10gui.add(u5.setup(false));
    fractal10gui.add(u6.setup(false));
    fractal10gui.add(u7.setup(false));
    fractal10gui.add(u8.setup(false));
    fractal10gui.add(u9.setup(false));

    fractal10gui.add(i1.setup(false));
    fractal10gui.add(i2.setup(false));
    fractal10gui.add(i3.setup(false));
    fractal10gui.add(i4.setup(false));
    fractal10gui.add(i5.setup(false));
    fractal10gui.add(i6.setup(false));
    fractal10gui.add(i7.setup(false));
    fractal10gui.add(i8.setup(false));
    fractal10gui.add(i9.setup(false));
    
    fractal10gui.add(o1.setup(false));
    fractal10gui.add(o2.setup(false));
    fractal10gui.add(o3.setup(false));
    fractal10gui.add(o4.setup(false));
    fractal10gui.add(o5.setup(false));
    fractal10gui.add(o6.setup(false));
    fractal10gui.add(o7.setup(false));
    fractal10gui.add(o8.setup(false));
    fractal10gui.add(o9.setup(false));
    
    fractal10toggles = {u1, u2, u3, u4, u5, u6, u7, u8, u9,i1, i2, i3, i4, i5, i6, i7, i8, i9, o1, o2, o3, o4, o5, o6, o7, o8, o9};

    mode1gui.setup("Main Costume Fractal Menu");
    mode1gui.add(mode1Size.set("Fractal Size", 200, 0, 1500));

    mode1gui.add(mode1Position.set("Position", ofVec2f(ofGetWidth()/2, ofGetHeight()/2), ofVec2f(-1000, -1000), ofVec2f(1500, 1500)));

    mode1gui.add(m1.setup("draw custom fractal 1", false));
    mode1gui.add(m2.setup("draw custom fractal 2", false));
    mode1gui.add(m3.setup("draw custom fractal 3", false));
    mode1gui.add(m4.setup("draw custom fractal 4", false));
    mode1gui.add(m5.setup("draw custom fractal 5", false));
    mode1gui.add(m6.setup("draw custom fractal 6", false));

    colorpanel.setup("Colors");

    colorpanel.add(color1.set("color 1", ofColor(255, 0, 0), ofColor(0, 0, 0), ofColor(255, 255, 255)));
    colorpanel.add(color2.set("color 2", ofColor(0, 255, 0), ofColor(0, 0, 0), ofColor(255, 255, 255)));
    colorpanel.add(color3.set("color 3", ofColor(0, 0, 255), ofColor(0, 0, 0), ofColor(255, 255, 255)));

}

//--------------------------------------------------------------
void ofApp::update(){
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSetBackgroundColor(0,0,0);
    if (!ignoreCamScroll) {camera.setDistance(camDistance);}
    light.setPosition(uiPosition->x, uiPosition->y, uiPosition->z);
    if (resetcam){camera.reset();}

    //if (updateFractal10) {
        fractal10nums.clear();
        for (ofxToggle tog: fractal10toggles) {
            if (tog) {fractal10nums.push_back(1);} 
            else {fractal10nums.push_back(0);}
        }
    //}

    if(randomizeFractal) {
        numbers.clear();
        for (int in: fractal10nums) {
        int n = ofRandom(2);
        numbers.push_back(n);
        }

    }
}


void ofApp::drawOmega(){
    ofSetColor(255);

    ofBackgroundGradient(ofColor(120), ofColor(0), OF_GRADIENT_CIRCULAR);
    ofDrawBitmapString("Press 0 to deactivate.", 0, 10);
    frameCount++;
    if ( omegaFrames == 18) {
        depth++;
        omegaFrames = -1;
    }

    if (depth == 8){depth = 0;}

    CustomMode1* mode = dynamic_cast<CustomMode1*>(ModeVector[4]);

    if (omegaFrames<9) {
    mode->draw1(ofGetWidth()/2, ofGetHeight()/2, (ofGetHeight()/3-10) , depth);
    }
    else{
    mode->draw2(ofGetWidth()/2, ofGetHeight()/2, (ofGetHeight()/3-10) , depth);
    }

    omegaFrames+=1;

    //ofDrawRectangle(40, 40, ofRandom(500), ofRandom(500));
}

//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */



    if (omegaAnimationIsPlaying) {drawOmega(); return;}


    ofSetColor(255);
    ofDrawBitmapString(to_string(ofGetFrameRate()),ofGetWidth()- 100, 10);


    ofDrawBitmapString("Depth: "+ to_string(depth), ofGetWidth()/2 -20 , ofGetHeight()-10); //prints depth
    
    if (!animationIsActive){
    ofDrawBitmapString("Press space to activate Basic animation", 0, ofGetHeight()-75); //prints depth
    ofDrawBitmapString("Press 0 to activate custom animation", 0, ofGetHeight()-60); //prints depth
    }

    else { 
        ofDrawBitmapString("Animation is active, speed: " + to_string(animSpeed), 0, ofGetHeight()-75);
        ofDrawBitmapString("To change speed press ~s~", 0, ofGetHeight()-60);
        ofDrawBitmapString("speed 1, depth changes every 2 seconds.", 0, ofGetHeight()-45);
        ofDrawBitmapString("speed 2, depth changes every second", 0, ofGetHeight()-30);
        ofDrawBitmapString("speed 3, depth changes every 0.6 seconds.", 0, ofGetHeight()-15);

        framesSinceAnimationWasActive++;
        if (framesSinceAnimationWasActive%(120/animSpeed) == 0){
            if (depth != 8) {depth++;}
            else {depth = 0;}
        }
    }



    int y = 25;
    int i = 1;
    ofDrawBitmapString("Modes", 0, 10);
    
    
    for (FractalMode* mode: ModeVector) {if(mode->getActive()) {ofSetColor(0,255,0);} else{ofSetColor(255,0,0);} ofDrawBitmapString("press "+to_string(i)+" : "+ mode->getName(), 0, y); y+= 15; i++;} //prints active modes




    //exclusive mode cause of 3d rendering

    if (ModeVector[5]->getActive()){
        CustomMode2* mode = dynamic_cast<CustomMode2*>(ModeVector[5]);
        mode->color1 = color1;
        mode->color2 = color2;
        mode->color3 = color3;
        camera.begin();
        light.enable();
        ofEnableDepthTest();

        ofFill();
        ofSetColor(255);
        
        if(showLight){ofDrawSphere(uiPosition->x, uiPosition->y, uiPosition->z, fractalSize/20);}
        
        if (f1) {mode->draw1(fractalPosition, fractalSize, depth);}
        if (f2) {mode->draw2(fractalPosition, fractalSize, depth);}
        if (f3) {mode->draw3(fractalPosition, fractalSize, depth);}
        if (f4) {mode->draw4(fractalPosition, fractalSize, depth);}
        if (f5) {mode->draw5(fractalPosition, fractalSize, depth);}
        if (f6) {mode->draw6(fractalPosition, fractalSize, depth, sponge);}
        if (f7) {mode->draw6(fractalPosition, fractalSize, depth, test1);}
        if (f8) {mode->draw6(fractalPosition, fractalSize, depth, test2);}
        if (f9) {mode->draw6(fractalPosition, fractalSize, depth, numbers);}
        if (f10) {mode->draw6(fractalPosition, fractalSize, depth, fractal10nums);}

        camera.end();
        light.disable();
        ofDisableLighting();
        ofDisableDepthTest();
        if (f10) {fractal10gui.draw();}
        gui.draw();
        colorpanel.draw();
        return;
    }


    
    if (ModeVector[0]->getActive()){
        DrawMode1* mode = dynamic_cast<DrawMode1*>(ModeVector[0]);

        mode->color1 = color1;
        mode->color2 = color2;
        mode->color3 = color3;
        mode->draw(ofGetWidth()/2, ofGetHeight()/2, depth);
    }

    if (ModeVector[1]->getActive()){
        DrawMode2* mode = dynamic_cast<DrawMode2*>(ModeVector[1]);
        mode->color1 = color1;
        mode->color2 = color2;
        mode->color3 = color3;
        mode->draw(200,depth, ofGetWidth()/2, ofGetHeight()-50, ofRandom(30, 70));
    }

    if (ModeVector[2]->getActive()){
        DrawMode3* mode = dynamic_cast<DrawMode3*>(ModeVector[2]);
        mode->color1 = color1;
        mode->color2 = color2;
        mode->color3 = color3;
        mode->draw(ofGetWidth() / 2 - ofGetHeight() / 4, 10, ofGetHeight() / 2, depth);
    }

    if (ModeVector[3]->getActive()){
        KochSnowFlake* mode = dynamic_cast<KochSnowFlake*>(ModeVector[3]);

        double height = (ofGetWidth()/2)*sin(1.0472);
        mode->draw(ofGetWidth()/2 - ofGetWidth()/4, ofGetHeight()/2 - height/2, ofGetWidth()/2 + ofGetWidth()/4,ofGetHeight()/2 - height/2, 0, depth);
        mode->draw(ofGetWidth()/2 + ofGetWidth()/4, ofGetHeight()/2 - height/2, ofGetWidth()/2,ofGetHeight()/2 + height/2, 4.18879, depth);
        mode->draw(ofGetWidth()/2, ofGetHeight()/2 + height/2, ofGetWidth()/2 - ofGetWidth()/4,ofGetHeight()/2 - height/2, 2.0944, depth);
    }

    if (ModeVector[4]->getActive()){
        CustomMode1* mode = dynamic_cast<CustomMode1*>(ModeVector[4]);
        mode->color1 = color1;
        mode->color2 = color2;
        mode->color3 = color3;

        float x = mode1Position->x;
        float y = mode1Position->y;

        if (m1) {mode->draw1(x, y, mode1Size, depth);}
        if (m2) {mode->draw2(x, y, mode1Size, depth);}
        if (m3) {mode->draw3(ofPoint(x, y), mode1Size, depth);}
        if (m4) {mode->draw4(ofPoint(x, y), mode1Size/3, depth);}
        if (m5) {mode->draw5(ofPoint(x, y), mode1Size, depth);}
        if (m6) {mode->draw6(x, y, mode1Size, depth);}
        mode1gui.draw();

    }
    colorpanel.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // This method is called automatically when any key is pressed
    switch(key){
        
        
        case '1':
            ModeVector[0]->setActive(!ModeVector[0]->getActive());
            break;
        case '2':
            ModeVector[1]->setActive(!ModeVector[1]->getActive());
            break;
        case '3':
            ModeVector[2]->setActive(!ModeVector[2]->getActive());
            break;
        case '4':
            ModeVector[3]->setActive(!ModeVector[3]->getActive());
            break;

        case '5':
            ModeVector[4]->setActive(!ModeVector[4]->getActive());
            break;
        case '6':
            ModeVector[5]->setActive(!ModeVector[5]->getActive());
            camera.reset();
            break;

        case '-':

            if (!animationIsActive){
                if (depth > 0){
                depth -= 1;}
            }
            break;

        case '=':
            
            if (!animationIsActive){
            depth += 1;
            }
            break;

        case ' ':
            
            if(animationIsActive){
                depth = 5;
                animationIsActive = false;
                break;
            }

            if(!animationIsActive){
                depth = 0;
                animationIsActive = true;
                framesSinceAnimationWasActive = 0;
            }

            break;
        
        case 's':
            if (animationIsActive){
                if (animSpeed < 3){
                animSpeed++;
                }
                else {animSpeed = 1;}
            }
            break;
            
        case '0':
            
            if (!omegaAnimationIsPlaying) {

                song.load("song.wav");
                song.play();
            depth = 0;
            frameCount = 25;
            omegaFrames = -6;
            omegaAnimationIsPlaying =true;

            }
            else {
            depth = 5;
            omegaFrames = 0;
            omegaAnimationIsPlaying = false;
            song.unload();

            }
            break;


    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){




}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}