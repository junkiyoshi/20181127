#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofEnableDepthTest();
	ofSetLineWidth(2);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(90);

	float big_radius = 300;
	for (int big_deg = 100; big_deg < 270; big_deg += 10) {

		float radius = big_radius * cos(big_deg * DEG_TO_RAD);
		float big_y = big_radius * sin(big_deg * DEG_TO_RAD);

		ofPushMatrix();
		ofTranslate(glm::vec2(0, big_y));
		ofRotateX(90);

		int start_deg = ofGetFrameNum() * 2 + big_y;
		int deg = start_deg;

		ofNoFill();
		ofBeginShape();
		for (; deg < start_deg + 200; deg++) {

			ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		}
		ofEndShape();

		ofFill();
		ofDrawSphere(radius * cos(deg  * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 6);

		ofPopMatrix();
	}

	ofTranslate(0, 450, 0);

	big_radius = 150;
	for (int big_deg = 100; big_deg < 270; big_deg += 10) {

		float radius = big_radius * cos(big_deg * DEG_TO_RAD);
		float big_y = big_radius * sin(big_deg * DEG_TO_RAD);

		ofPushMatrix();
		ofTranslate(glm::vec2(0, big_y));
		ofRotateX(90);

		int start_deg = ofGetFrameNum() * 2 + big_y - 300;
		int deg = start_deg;

		ofNoFill();
		ofBeginShape();
		for (; deg < start_deg + 200; deg++) {

			ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		}
		ofEndShape();

		ofFill();
		ofDrawSphere(radius * cos(deg  * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 3);

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}