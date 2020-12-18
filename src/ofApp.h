#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include <vector>
#include "RingClass.h"

#include "WunderClass.h"
#include "Particle.h"

using namespace std;

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	int amount;

	ofEasyCam cam;

	ofxPanel gui;
	ofParameterGroup planetGroups;
	RingClass rings[20];
	WunderClass wunder;

	ofSoundPlayer sound;
	float* fft;
	float* soundSpectrum;
	float decay;
	int bands;
	float sum1, sum2, sum3;
	ofVec3f newPosition, newPosition2, newPosition3;
	//ParticleSystem ps;
	vector<Particle> particles;
	bool snow = false;
};