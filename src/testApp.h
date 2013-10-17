#ifndef _TEST_APP
#define _TEST_APP

/**
 *  testApp.h
 *
 *	ofxImageSequence example project
 *
 *  Created by James George ( http://www.jamesgeorge.org ) on 6/15/10.
 *  In collaboration with FlightPhase ( http://www.flightphase.com )
 *
 *  Copyright (c) 2010 
 */

#include "ofMain.h"
#include "ofxImageSequence.h"

class testApp : public ofBaseApp
{

  public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	
	ofxImageSequence sequence, sequence1;
	ofImage sun, sun1;
	bool playing;
    float n, time, al, almapped, angle, angle1;
    ofPoint  pos, prevPos;
    ofSoundPlayer sound1, sound2, sound3, sound4, sound5, sound6, sound7, sound8, sound9, sound10;
    
    

};

#endif
