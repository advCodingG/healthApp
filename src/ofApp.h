#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "CreditCard.h"
#include "CreditCardScanner.h"
//#include "CreditCardScannerSimulator.h"
#include "CreditCardScannerUtils.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxJSONElement countyResult;
        ofxJSONElement summaryResult;
        ofxJSONElement RHIResult;
        ofxJSONElement vulnerableResult;
        ofxJSONElement demographicResult;
        ofxJSONElement riskFactorResult;
    
        CreditCardScanner ccScan;
        ofTrueTypeFont Bariol;
        ofTrueTypeFont BariolBig;
        ofTrueTypeFont BariolSmall;
        private:
            ofRectangle                     mToggleDebugBtn;
    std::string url;
};
