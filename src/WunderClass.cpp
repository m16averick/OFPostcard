#include "WunderClass.h"

void WunderClass::setup() {
	planetGroup.add(rotateSpeed.set("speed", 0.02, 0.0, 1.0));
	//planetGroup.add(posX.set("X", 0, 0, 600));
	planetGroup.add(posY.set("R", ofRandom(300)+100, 0, 600));
	planetGroup.add(size.set("Size", ofRandom(5)+5, 0, 120));
	planetGroup.add(red.set("red", ofRandom(255), 0, 255));
	planetGroup.add(green.set("green", ofRandom(255), 0, 255));
	planetGroup.add(blue.set("blue", ofRandom(255), 0, 255));

	posX.set("X", 0, 0, 600);
	posY.set("Y", 0, 0, 600);
}

void WunderClass::update() {
	rotation+=0.1;
	position = ofVec3f(posX, posY, posZ);
	std::cout << position << endl;
}

void WunderClass::draw() {
	//ofSetColor(red, green, blue);
	ofRotate(rotation * rotateSpeed);
	ofCircle(posX, posY, size);
}
