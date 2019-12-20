#include "ofApp.h"
// https://en.wikipedia.org/wiki/Numerical_model_of_the_Solar_System#Modern_method
//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableDepthTest();
	ofSetVerticalSync(true);

	//cam.setDistance(1500);
	cam.setAutoDistance(false);
	cam.setPosition(513.114, -746.695, 643.732);
	cam.setOrientation(ofQuaternion(0.587453, 0.00165523, -0.00120164, 0.809256));


	//cam.tilt(45);
	//cam.setDistance(769.645);

	amount = 5;
	ofBackground(0);

	bandtwidth = 8192;
	beat.loadSound("snow.wav");
	fftSmooth = new float[bandtwidth];
	for (int i = 0; i < bandtwidth; i++)
	{
		fftSmooth[i] = 0;
	}

	bands = 128;


	beat.setLoop(true);
	beat.setVolume(0.2);




	for (int i = 0; i < amount; i += 1)
	{
		planets[i].setup();
		planetGroups.add(planets[i].planetGroup);
		planets[i].size = ofRandom(30);
	}

	for (int i =0; i < 100; i++)			wunder[i].setup();
	//		wunder[i].size = 50;


	planets[0].posY.set("X", 0, 0, 600);

	gui.setup(planetGroups);

	//ps = new ParticleSystem();
	/*
	for (int i = 0; i < 500; i++)
	{
		Particle p0;
		particles.push_back(p0);
	}

	for (int i = 0; i < particles.size(); i++)
	{
		particles.at(i).setup();
	}

	*/
}

//--------------------------------------------------------------
void ofApp::update(){

	ofSoundUpdate();
#pragma once  
	float* value = ofSoundGetSpectrum(bands);
	for (int i = 0; i < bands; i++)
	{
		fftSmooth[i] *= 0.95f;
		if (fftSmooth[i] < value[i]) {
			fftSmooth[i] = value[i];
		}
	}

	for (int i = 0; i < amount; i += 1)
	{
		planets[i].update();
		wunder[i].update();
	}

	for (int i = 0; i < particles.size(); i++)
	{
		particles.at(i).update(wunder);
		if (particles.at(i).lifespan < 0)	particles.erase(particles.begin()+i);
	}



	std::cout << particles.size() << endl;

}

//--------------------------------------------------------------
void ofApp::draw(){

//	gui.draw();


	cam.begin();

	//ofSetColor(255, 0, 150);
	//ofFill();
	//ofDrawBox(30);

	
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	//planets[0].draw();
/*
	for (int i = 0; i < 500; i += 1)
	{
		snow[i].draw();
	}
	*/


	for (int i = 0; i < particles.size(); i++)
	{
		particles.at(i).draw();
	}

	for (int i = 0; i < 5; i++)
	{
		wunder[i].size = 50;
		ofTranslate(0, 0, 10.0f);
		ofSetColor(43, 21, 0);
		wunder[i].draw();
		wunder[i].posZ = 30 + 10*i;
	}

	for (int i = 5; i < 15; i++)
	{
		wunder[i].size = 250 - i * 5;
		ofTranslate(0, 0, 10.0f);
		ofSetColor(0, 75, 0);
		wunder[i].draw();
		wunder[i].posZ =  30 + 10 * i;
	}

	for (int i = 15; i < 25; i++)
	{
		wunder[i].size = 275 - i * 5;
		ofTranslate(0, 0, 10.0f);
		ofSetColor(0, 75, 0);
		wunder[i].draw();
		wunder[i].posZ = 30 + 10 * i;
	}

	for (int i = 25; i < 35; i++)
	{
		wunder[i].size = 300 - i * 5;
		ofTranslate(0, 0, 10.0f);
		ofSetColor(0, 75, 0);
		wunder[i].draw();
		wunder[i].posZ = 30 + 10 * i;
	}

	for (int i = 35; i < 45; i++)
	{
		wunder[i].size = 320 - i * 5;
		ofTranslate(0, 0, 10.0f);
		ofSetColor(0, 75, 0);
		wunder[i].draw();
		wunder[i].posZ = 30 + 10 * i;
	}

	for (int i = 45; i < 55; i++)
	{
		wunder[i].size = 340 - i * 5;
		ofTranslate(0, 0, 10.0f);
		ofSetColor(0, 75, 0);
		wunder[i].draw();
		wunder[i].posZ = 30 + 10 * i;
	}

		for (int i = 55; i < 65; i++)
	{
		wunder[i].size = 340 - i * 5;
		ofTranslate(0, 0, 10.0f);
		ofSetColor(0, 75, 0);
		wunder[i].draw();
		wunder[i].posZ = 30 + 10 * i;
	}


	//680 czubek
	ofTranslate(0, 0, -680.0f);

	for (int i = 1; i < amount; i += 1)
	{
		for (int j = 0; j < bands; j++)
		{
			//planets[i].size = (-fftSmooth[j] * 1000);
			ofTranslate(planets[0].posX, planets[0].posY, i / 5 + 10 * (fftSmooth[j]));
			planets[i].draw();
		}

	}

//	ofTranslate(0, 0, 0);

	for (int j = 0; j < bands; j++)
	{
		//std::cout << fftSmooth[j] << endl;
		if (fftSmooth[j] > 0.05)
		{
				Particle p0;
				p0.setup();
				particles.push_back(p0);
			
		}
	}

	//ofSphere(0, 0, 700, 10);
	// 680 - czubek

	//ofTranslate(planet01.posX, planet01.posY);
	cam.end();


	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case '1':
		beat.play();
		break;
	case '2':
		beat.stop();
		break;
	case '3':
		std::cout << cam.getPosition() << endl << cam.getOrientationQuat() << endl;
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
