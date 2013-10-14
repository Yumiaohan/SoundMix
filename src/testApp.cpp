
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofBackground(0);
    ofEnableSmoothing();
    
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
    
    
	sequence1.loadSequence("wings", "png", 1, 18, 2);
    sequence1.preloadAllFrames();
    sequence1.setFrameRate(10);
    
    sequence.loadSequence("wings-", "png", 1, 45, 2);
	sequence.preloadAllFrames();	//this way there is no stutter when loading frames
	sequence.setFrameRate(10); //set to ten frames per second for Muybridge's horse.
	
	playing = false; //controls if playing automatically, or controlled by the mouse


    
    

}

//---------------------------- ----------------------------------
void testApp::update(){
   ofSoundUpdate(); 
}

//--------------------------------------------------------------
void testApp::draw(){
	
    //ofSeedRandom(0);
    //Triangles............
    
    ofNoFill();
	ofSetColor(255, 255, 255, 255);
    
    float tl=300;// ofRandom(290,300);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateZ(ofGetElapsedTimef()/5*RAD_TO_DEG);
   
     ofTriangle(0, -sqrt(3)*2*tl/3, -tl, sqrt(3)*tl/3, tl, sqrt(3)*tl/3);
    ofTriangle(0, -sqrt(3)*2*tl/3, -tl, sqrt(3)*tl/3, tl, sqrt(3)*tl/3);
    
    ofPushMatrix();
    ofRotateZ(ofNoise(ofGetElapsedTimef())*5);
    ofTriangle(0, -sqrt(3)*2*tl/3, -tl, sqrt(3)*tl/3, tl, sqrt(3)*tl/3);
    ofPopMatrix();

    ofPopMatrix();

    
    
    //ImageSequence............
    
    if(playing){
		//get the frame based on the current time and draw it
		
        sequence.getFrameForTime(ofGetElapsedTimef())->draw(0,0);
 
	}
	else {
		//get the sequence frame that maps to the mouseX position
		float percent = ofMap(mouseX, 0, ofGetHeight(), 0, 1.0, true);
		//draw it.
		sequence.getFrameAtPercent(percent)->draw(ofGetWidth()/2-400, ofGetHeight()/2-320, 800, 640);
	}
    
    if(playing){
		//get the frame based on the current time and draw it
		
        sequence1.getFrameForTime(ofGetElapsedTimef())->draw(0,0);
	}
	else {
		//get the sequence frame that maps to the mouseX position
		float percent1 = ofMap(mouseY, 0, ofGetHeight(), 0, 1.0, true);
		//draw it.
		sequence1.getFrameAtPercent(percent1)->draw(ofGetWidth()/2-400, ofGetHeight()/2-320, 800, 640);
        
	}

   //Sound............
    
    float pitch = ofMap(mouseY-200, 0, (float)ofGetHeight(), 1.2, 0.5);
    sound1.setSpeed(pitch);
    }

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	//hit any key to toggle playing
	playing = !playing;
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
    ofSeedRandom(0);
    if (mouseY<300) {
        sound1.play();
    }
    if (mouseY>500, mouseX<200) {
        sound9.play();
        sound9.setSpeed(1);
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

