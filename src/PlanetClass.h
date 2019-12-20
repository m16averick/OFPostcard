#pragma once

#include "ofMain.h"

class PlanetClass {
public:
	void setup();
	void update();
	void draw();

	ofParameterGroup planetGroup;
	ofParameter<float> rotateSpeed;
	ofParameter<float> posX;
	ofParameter<float> posY;
	ofParameter<int> red;
	ofParameter<int> green;
	ofParameter<int> blue;
	ofParameter<int> mass;

	ofParameter<int> size;
	float rotation = 0.0;
	//ofParameter<int> mass;
	
};