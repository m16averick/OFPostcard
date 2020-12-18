#include "RingClass.h"

void RingClass::setup(float radius1, float radius2, int red, int green, int blue) {
	circle.setCircleResolution(100);
	circle.arc(position, radius1, radius1, 0, 360);
	circle.close();
	circle.arc(position, radius2, radius2, 0, 360);
	circle.close();
	circle.setFillColor(ofColor(red, green, blue));
	k = 7;
	mass = 60;
	gravity = 15;
	damping = 12;
}

void RingClass::update() {
	if (musicPower < 0.001)
	{
		acceleration.z = 0;
		velocity.z = 0;
	}
	springForce = -k * distance.z;
	dampingForce = damping * velocity.z;
	force = springForce + musicPower - mass * gravity - dampingForce;
	acceleration.z = force/mass;
	velocity += acceleration;
	distance += velocity;
	circle.translate(velocity);
}

void RingClass::draw() {
	circle.draw();
}