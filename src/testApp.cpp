
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(500);
    
    sound1.loadSound("sound1.mp3");
    sound2.loadSound("sound2.mp3");
    sound3.loadSound("sound3.mp3");
    sound4.loadSound("sound4.mp3");
    sound5.loadSound("sound5.mp3");
    sound6.loadSound("sound6.mp3");
    sound7.loadSound("sound7.mp3");
    sound8.loadSound("sound8.mp3");
    sound9.loadSound("sound9.mp3");
    sound10.loadSound("sound10.mp3");
    
    sound1.setLoop(false);
    sound1.setVolume(0.5);
	sound1.play();
    
    sun.loadImage("sun.png");
    sun1.loadImage("sun1.png");
	sequence1.loadSequence("wings", "png", 1, 18, 2);
    sequence1.preloadAllFrames();
    sequence1.setFrameRate(10);
    
    sequence.loadSequence("wings-", "png", 1, 45, 2);
	sequence.preloadAllFrames();	
	sequence.setFrameRate(10); 
	
	playing = false; 

    time=0.06;
    n=1;

}

//---------------------------- ----------------------------------
void testApp::update(){
    
    ofSoundUpdate();
    
    pos.x = (1-time) * pos.x + (time) * mouseX;
    pos.y = (1-time) * pos.y + (time) * mouseY;

    prevPos=pos;


}

//--------------------------------------------------------------
void testApp::draw(){
	
    ofSeedRandom(0);
    
    //Sun............
    
    al = sin(ofGetElapsedTimef()*2);
    almapped = ofMap(al, -1, 1, 0, 255);
    ofSetColor(255, 255, 255, 255);
    sun.draw(ofGetWidth()/2-400, ofGetHeight()/2-320, 800, 640);
    ofSetColor(255, 255, 255, 255-almapped);
    sun1.draw(ofGetWidth()/2-400, ofGetHeight()/2-320, 800, 640);
    
    //ImageSequence............

    ofSetColor(255, 255, 255, 200-(almapped/2.25));
    if(playing){
        sequence.getFrameForTime(ofGetElapsedTimef())->draw(0,0);
	}
	else {
        float percent = ofMap(mouseX, 0, ofGetWidth(), 0, 1.0, true);
        sequence.getFrameAtPercent(percent)->draw(ofGetWidth()/2-400, ofGetHeight()/2-320, 800, 640);
        
        for (int i=1; i<n; i++) {
            ofSetColor(255, 255, 255, 200-(almapped/2.25-i*200/10));
            float percent1 = ofMap(mouseX-i*100, 0, ofGetWidth(), 0, 1.0, true);
        //draw it.
            sequence.getFrameAtPercent(percent1)->draw(ofGetWidth()/2-400, i*ofRandom(i-100,ofGetHeight()), 800, 640);
            sequence.getFrameAtPercent(percent1-0.3)->draw(ofGetWidth()/2+400, i*ofRandom(i-100,ofGetHeight()), -800, 640);
        }
	}
    
    if(playing){
        sequence1.getFrameForTime(ofGetElapsedTimef())->draw(0,0);
	}
	else {
        float percent2 = ofMap(mouseY, 0, ofGetHeight(), 0, 1.0, true);
		//draw it.
		sequence1.getFrameAtPercent(percent2)->draw(ofGetWidth()/2-400, ofGetHeight()/2-320, 800, 640);
        for (int i=1; i<n/2; i++) {
            ofSetColor(255, 255, 255, 200-(almapped/2.25-i*200/10));
            float percent3 = ofMap(mouseY-i*50, 0, ofGetWidth(), 0, 1.0, true);
            sequence1.getFrameAtPercent(percent3)->draw(ofGetWidth()/2-400, i*ofRandom(i-100,ofGetHeight()), 800, 640);
            sequence1.getFrameAtPercent(percent3)->draw(ofGetWidth()/2+400,  i*ofRandom(i-100,ofGetHeight()), -800, 640);
        }
        
	}
    
    //SunShaddle............
    
    ofSetColor(0, 0, 0, almapped/2);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2-2, 198);
    
    
    //Mouse............
    
    ofSetColor(255, 255, 255, 200);
    float xorig = pos.x;
	float yorig = pos.y;
	float radius = 50;
	float angle = ofGetElapsedTimef()*2;
	float x = xorig + radius * cos(angle);
	float y = yorig + radius * sin(angle);
	ofCircle(x, y, 5);
    
   //Sound............
    
    float pitch = ofMap(mouseY-200, 0, (float)ofGetHeight(), 1.2, 0.5);
    sound1.setSpeed(pitch);
    
    
    for (int i=0; i<4; i++) {
        ofSetColor(255, 255, 255, 80-abs(mouseX-ofGetWidth()/2+360-i*240)/20);
        ofCircle(ofGetWidth()/2-360+i*240, 750, 3);
        }

    }

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
      
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    //ofSetFrameRate(1);
//    speed=0;
    if (mouseY<400) {
        sound1.play();

    }
    float widthStep = ofGetWidth() / 5.0f;
	if (x < widthStep){
		sound2.play();
		sound2.setSpeed( 0.2f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*3);
		sound2.setPan(ofMap(x, 0, widthStep, -1, 1, true));
	} else if (x >= widthStep && x < widthStep*2){
		sound3.play();
        sound3.setSpeed( 0.2f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*3);
		sound3.setPan(ofMap(x, widthStep, widthStep*2, -1, 1, true));
	} else if (x >= widthStep*2 && x < widthStep*3){
		sound4.play();
		sound4.setSpeed( 0.2f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*3);
		//map x within the last third of window to -1 to 1 ( for left / right panning )
		sound4.setPan( ofMap(x, widthStep*2, widthStep*3, -1, 1, true));
    } else if (x >= widthStep*3 && x < widthStep*4){
		sound5.play();
		sound5.setSpeed( 0.2f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*3);

		sound5.setPan( ofMap(x, widthStep*4, ofGetWidth(), -1, 1, true));
	} else if (x >= widthStep*4 && x < ofGetWidth()){
		sound6.play();
		sound6.setSpeed( 0.2f + ((float)(ofGetHeight() - y) / (float)ofGetHeight())*3);
		sound6.setPan( ofMap(x, widthStep*4, ofGetWidth(), -1, 1, true));
    }

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if (n<20) {
        n+=1;
    }
    else
        n=1;
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

