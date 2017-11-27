/************************************************************
参考URL
	syphon : send
		https://github.com/SJ-magic-study-oF/study__syphon_send
		
	【openFrameworks】ofFBOのアンチエイリアス
		http://yumataesu.hatenablog.com/entry/2015/11/03/182931
			contents
				第4引数は、サンプル数らしい。大きくすればするほど綺麗になる。
				fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB, 4);
				
				と、あるが、西条が実際に手元で試した所、特に効果が感じられなかった...

contents
	1.	drawString/drawStringAsShapesにおけるalphaの掛かり方の違い
		conclusion
			alphaを下げていくと、drawStringは(図形と比べて)先に消えていく.
			図形と同様のalpha効果を期待するなら、drawStringAsShapes を使用すること
			
	2.	fbo -> display -syphon-> disp:receiver でのdouble alphaを避ける
		conclution
			src側のalphaをsqrt(0 - 1)によって持ち上げる.

setting of unity syphon
	shaderは、unlit/Transparent : not transparent cutoff(on/off)
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxSyphon.h"
#include "ofxTrueTypeFontUC.h"

/************************************************************
************************************************************/
#define CHECK__DRAWFONR_AS_SHAPE	0
#define CHECK__AVOID_DOUBLE_ALPHA	1
	#define CHECK CHECK__AVOID_DOUBLE_ALPHA

/************************************************************
************************************************************/
class ofApp : public ofBaseApp{
private:
	/****************************************
	****************************************/
	enum{
		WIDTH = 1280,
		HEIGHT = 720,
	};
	
	/****************************************
	****************************************/
	/********************
	********************/
	bool b_smooth;
	
	ofEasyCam cam;
	
	ofxTrueTypeFontUC font[2];
	ofFbo fbo[2];
	
	ofxSyphonServer mainOutputSyphonServer;
	
	/********************
	********************/
	ofxPanel gui;
	ofxFloatSlider gui_alpha;
	
public:
	/****************************************
	****************************************/
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
};
