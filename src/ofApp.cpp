#include "ofApp.h"
// https://en.wikipedia.org/wiki/Numerical_model_of_the_Solar_System#Modern_method
//--------------------------------------------------------------
void ofApp::setup() {
	ofEnableDepthTest();
	ofSetVerticalSync(true);

	cam.setAutoDistance(false);
	cam.setPosition(2.78648, -1066.77, 284.686);
	cam.setOrientation(ofQuaternion(0.665425, -0.00915969, 0.00816628, 0.746365));
	// d a b c
	ofBackground(0);

	sound.load("snow.wav");
	sound.setLoop(true);
	sound.setVolume(0.5);
	decay = 0.5;

	newPosition2.x = 0;
	newPosition2.y = 0;

	fft = new float[128];
	for (int i = 0; i < 128; i++)
	{
		fft[i] = 0;
	}
	bands = 64;

	amount = 3;
	wunder.setup();
	rings[0].position.set(0, 0, 40);
	rings[0].setup(500, 540, 148, 0, 211);
	//520, 560, 148, 0, 211
	rings[1].position.set(0, 0, 70);
	rings[1].setup(400, 450, 35, 75, 234);
	rings[2].position.set(0, 0, 90);
	rings[2].setup(270, 330, 255, 215, 0);
}

//--------------------------------------------------------------
void ofApp::update() {
	ofSoundUpdate();
	soundSpectrum = ofSoundGetSpectrum(bands);
	for (int i = 0; i < bands; i++)
	{
		fft[i] *= decay;
		if (fft[i] < soundSpectrum[i]) fft[i] = soundSpectrum[i];
	}

	for (int i = 0; i < particles.size(); i++)
	{
		particles.at(i).update();
		if (particles.at(i).lifespan < 0)	particles.erase(particles.begin() + i);
	}

	wunder.update();
	for (int i = 0; i < amount; i += 1)
	{
		rings[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();
	wunder.draw();


	sum1 = 0;
	for (int i = 0; i < 16; i++)
	{
		sum1 += fft[i];
	}
	if (sum1 > 0.9) rings[0].musicPower = sum1 * 100;
	//else rings[0].musicPower = 0;
	rings[0].draw();




	sum2 = 0;
	for (int i = 14; i <= 34; i++)
	{
		sum2 += fft[i];
	}
	rings[1].musicPower = sum2 * 3000;
	rings[1].draw();


	sum3 = 0;
	for (int i = 50; i <= 64; i++)
	{
		sum3 += fft[i];
	}
	if (sum3 > 0.005) rings[2].musicPower = sum3 * 20000;
	else rings[2].musicPower = 0;
	rings[2].draw();
	
	for (int i = 0; i < particles.size(); i++)
	{
		particles.at(i).draw();
	}

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (key) {
	case '1':
		sound.play();
		break;
	case '2':
		sound.stop();
		break;
	case '3':
		std::cout << cam.getPosition() << endl << cam.getOrientationQuat() << endl;
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}