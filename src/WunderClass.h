  
#pragma once

#include "ofMain.h"

class WunderClass {
public:
	void setup();
	void update();
	void draw();
	bool isInside(ofVec3f point);
	bool collision = true;


	ofCylinderPrimitive pniak;
	ofConePrimitive drzewo1, drzewo2, drzewo3, drzewo4;

};