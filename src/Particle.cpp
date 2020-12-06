#include "Particle.h"
#include <cmath>


void Particle::setup() {
	size = 1;
	lifespan = 370;
	location = ofVec3f(ofRandom(1200) - 600, ofRandom(1200) - 600, 900);
	acceleration = (ofVec3f(0, 0, -0.05));
	velocity = (ofVec3f(0, 0, 0));
}


void Particle::update() {
	velocity += acceleration;
	location += velocity;
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