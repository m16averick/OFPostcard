#include "PlanetClass.h"

void PlanetClass::setup() {
	planetGroup.add(rotateSpeed.set("speed", 0.02, 0.0, 1.0));
	//planetGroup.add(posX.set("X", 0, 0, 600));
	planetGroup.add(posY.set("R", ofRandom(250)+250, 0, 600));
	planetGroup.add(size.set("Size", ofRandom(5)+7, 0, 120));
	planetGroup.add(red.set("red", ofRandom(255), 0, 255));
	planetGroup.add(green.set("green", ofRandom(255), 0, 255));
	planetGroup.add(blue.set("blue", ofRandom(255), 0, 255));

	posX.set("X", 0, 0, 600);
}

void PlanetClass::update() {
	rotation+=0.1;
}

void PlanetClass::draw() {
	ofSetColor(red, green, blue);
	ofRotate(rotation * rotateSpeed);
	ofCircle(posX, posY, size);

}