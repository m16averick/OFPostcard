#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include <vector>
#include "PlanetClass.h"

#include "WunderClass.h"
#include "Particle.h"

using namespace std;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
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
		PlanetClass planets[20];
		WunderClass wunder[100];

		ofSoundPlayer beat;
		float* fftSmooth;
		int bands;
		int bandtwidth;
		//ParticleSystem ps;
		vector<Particle> particles;
		
};