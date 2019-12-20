#include "Particle.h"
#include <cmath>


void Particle::setup() {
	size = 1;
	lifespan = 370;
	location = ofVec3f(ofRandom(1200) - 600, ofRandom(1200) - 600, 900);
	acceleration = (ofVec3f(0,0,-0.05));
	velocity = (ofVec3f(0,0,0));
}


void Particle::update(WunderClass wunder[100]) {
	velocity += acceleration;
#pragma once  
	for (int i = 0; i < 65; i++)
	{
		if ( sqrt ( location.x * location.x + location.y * location.y) < 0.70 * sqrt ( (wunder[i].posX + wunder[i].size) * (wunder[i].posX + wunder[i].size )+ (wunder[i].posY + wunder[i].size) * (wunder[i].posY + wunder[i].size )) && location.z <= wunder[i].posZ ) check = true;
	}
	if (check == false) location += velocity;
	else lifespan = 1000;

	lifespan -= 2.0;
}

void Particle::draw() {
	ofSetColor(255);
	ofSphere(location, size);
}

bool Particle::isDead() {
	if (lifespan < 0.0) return true;
	else return false;
}