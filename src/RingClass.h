#pragma once

#include "ofMain.h"

class RingClass {
public:
	void setup(float radius1, float radius2, int red, int green, int blue);
	void update();
	void draw();
	float musicPower;
	float springForce, dampingForce, force, k;
	int mass, gravity, damping;
	ofVec3f acceleration, velocity, position;
	ofVec3f distance;
	ofPath circle;
};