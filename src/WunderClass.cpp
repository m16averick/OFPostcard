#include "WunderClass.h"

void WunderClass::setup() {
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	pniak.set(70, 100);
	pniak.rotateDeg(90, -1, 0, 0);
	pniak.setPosition(0, 0, pniak.getHeight()/2);

	drzewo1.set(220, 300, 30, 10);
	drzewo1.rotateDeg(90, -1, 0, 0);
	drzewo1.setPosition(0, 0, 240);

	drzewo2 = drzewo1;
	drzewo2.setScale(0.9, 0.9, 0.9);
	drzewo2.setPosition(0, 0, 330);

	drzewo3 = drzewo2;
	drzewo3.setScale(0.8, 0.8, 0.8);
	drzewo3.setPosition(0, 0, 420);

	drzewo4 = drzewo3;
	drzewo4.setScale(0.65, 0.75, 0.65);
	drzewo4.setPosition(0, 0, 520);
}

void WunderClass::update() {

}

void WunderClass::draw() {
	ofSetColor(43, 21, 0);
	pniak.draw();

	ofSetColor(0, 75, 0);
	drzewo1.draw();
	ofSetColor(0, 80, 0);
	drzewo2.draw();
	ofSetColor(0, 85, 0);
	drzewo3.draw();
	ofSetColor(0, 90, 0);
	drzewo4.draw();
}
