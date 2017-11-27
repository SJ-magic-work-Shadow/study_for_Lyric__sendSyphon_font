/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle("Test : Syphon Font");
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetWindowShape(WIDTH, HEIGHT);
	ofSetEscapeQuitsApp(false);
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	// ofEnableSmoothing();
	
	/********************
	bool loadFont(string filename, int fontsize, bool bAntiAliased=true, bool makeContours=false, float simplifyAmt=0.3, int dpi=0);
		in order to drawStringAsShapes(), you need to set makeContours = true.
	********************/
	font[0].loadFont("RictyDiminished-Regular.ttf", 50);
	font[1].loadFont("RictyDiminished-Regular.ttf", 50, true, true, 0.3, 96);
	
	/********************
	********************/
	fbo[0].allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	fbo[1].allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	
	mainOutputSyphonServer.setName("Screen Output"); // server name
	
	b_smooth = false;
	
	/********************
	********************/
	gui.setup();
	gui.add(gui_alpha.setup("alpha", 255, 0, 255));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

#if (CHECK == CHECK__DRAWFONR_AS_SHAPE)
	/********************
	********************/
	fbo[0].begin();
	
	ofDisableAlphaBlending();
	ofDisableSmoothing();
	
	ofClear(0, 0, 0, 0);
	ofSetColor(255, 255, 255, gui_alpha);
	
	font[0].drawString("Rolling my sleeves up in here", 200, 200);
	font[1].drawStringAsShapes("Rolling my sleeves up in here", 200, 300);
	
	fbo[0].end();
	
	/********************
	********************/
	cam.begin();
	ofPushStyle();
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	// ofDisableAlphaBlending();
	
	if(b_smooth)	ofEnableSmoothing();
	else			ofDisableSmoothing();
	
	ofBackground(0, 0, 0, 0);
	ofSetColor(255, 255, 255, 255);
	
	fbo[0].setAnchorPercent(0.5, 0.5);
	fbo[0].draw(0, 0, ofGetWidth(), ofGetHeight());
	
	ofSetColor(255, 255, 255, gui_alpha);
	ofDrawRectangle(0, -200, 100, 100);
	
	ofDisableSmoothing();
	ofPopStyle();
	cam.end();
	
	/********************
	********************/
	mainOutputSyphonServer.publishScreen();
	
	gui.draw();
	
#elif (CHECK == CHECK__AVOID_DOUBLE_ALPHA)

	/********************
	********************/
	fbo[0].begin();
	
	ofDisableAlphaBlending();
	ofDisableSmoothing();
	
	ofClear(0, 0, 0, 0);
	ofSetColor(255, 255, 255, gui_alpha);
	font[1].drawStringAsShapes("Rolling my sleeves up in here", 200, 200);
	
	fbo[0].end();
	
	/********************
	********************/
	fbo[1].begin();
	
	ofDisableAlphaBlending();
	ofDisableSmoothing();
	
	ofClear(0, 0, 0, 0);
	
	int alpha = int(sqrt(double(gui_alpha) / 255) * 255);
	ofSetColor(255, 255, 255, alpha);
	font[1].drawStringAsShapes("Rolling my sleeves up in here", 200, 300);
	
	fbo[1].end();
	
	/********************
	********************/
	cam.begin();
	ofPushStyle();
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	// ofDisableAlphaBlending();
	
	if(b_smooth)	ofEnableSmoothing();
	else			ofDisableSmoothing();
	
	ofBackground(0, 0, 0, 0);
	ofSetColor(255, 255, 255, 255);
	
	fbo[0].setAnchorPercent(0.5, 0.5);
	fbo[1].setAnchorPercent(0.5, 0.5);
	
	fbo[0].draw(0, 0, ofGetWidth(), ofGetHeight());
	fbo[1].draw(0, 0, ofGetWidth(), ofGetHeight());
	
	ofDisableSmoothing();
	ofPopStyle();
	cam.end();
	
	/********************
	********************/
	mainOutputSyphonServer.publishScreen();
	
	gui.draw();

#endif
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
		case ' ':
			b_smooth = !b_smooth;
			printf("smooth:%d\n", b_smooth);
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
