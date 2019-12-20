#pragma once

#include "ofMain.h"

class WunderClass {
public:
	void setup();
	void update();
	void draw();

	ofParameterGroup planetGroup;
	ofParameter<float> rotateSpeed;
	ofParameter<float> posX;
	ofParameter<float> posY;
	ofParameter<float> posZ;
	ofParameter<int> red;
	ofParameter<int> green;
	ofParameter<int> blue;
	ofParameter<int> mass;

	ofParameter<int> size;
	float rotation = 0.0;
	//ofParameter<int> mass;
	ofVec3f position;
};