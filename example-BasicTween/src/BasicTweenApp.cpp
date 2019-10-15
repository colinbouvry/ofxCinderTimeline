#include "BasicTweenApp.h"

void BasicTweenApp::setup() {
    mTimeline = ofxCinderTimeline::Timeline::create();
    mTimeline->stepTo(ofGetElapsedTimef());

    mBlackPos = mWhitePos = ofGetWindowSize() / 2.0;
}

void BasicTweenApp::update() {
    mTimeline->stepTo(ofGetElapsedTimef());
}

void BasicTweenApp::draw() {
    ofSetColor(ofColor::black);
    ofFill();
	ofDrawCircle(mBlackPos.value().x, mBlackPos.value().y, 20.0f);

    ofSetColor(ofColor::white);
    ofFill();
	ofDrawCircle(mWhitePos.value().x, mWhitePos.value().y, 16.0f);
}

void BasicTweenApp::mousePressed(int x, int y, int button) {
    timeline().apply(&mBlackPos, ofPoint(x, y), 2.0f, ofxCinderTimeline::EaseInOutCubic());
    timeline().apply(&mWhitePos, ofPoint(x, y), 0.35f, ofxCinderTimeline::EaseOutQuint()).appendTo(&mBlackPos);
}
