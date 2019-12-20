#pragma once

#include "ofMain.h"
#include <iostream>
#include <vector>
#include "WunderClass.h"

class Particle {
public:
	void setup();
	void update(WunderClass wunder[100]);
	void draw();
	bool isDead();

	int size;
	ofVec3f location;
	ofVec3f velocity;
	ofVec3f acceleration;
	float lifespan;

	bool check = false;
	ofVec3f road;
};