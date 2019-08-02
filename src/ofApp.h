#pragma once

#include "ofMain.h"
#include "ofxToolkit.h"
// Uncomment the foloowing line to enbale midi - Input
//#define KORG_ENABLED

#ifdef KORG_ENABLED
#include "ofxKorgNanoKontrol.h"
#endif

#include "ofxGui.h"
#include "ofxPostGlitch.h"
#include "ofxCameraMove.h"
#include "ofxMotionBlurCamera.h"
#include "ofxProcessFFT.h"

class ofApp : public ofBaseApp{
public:
    
    enum MODES{VIDEO=1, CAM, IMAGE};
    
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // CUSTOM METHODS
    void setupCameraSaveLoad();
    void setupVideos(string _folder);
    void setupImages(string _folder);
    
    // SETTERS & GETTERS
    float getMappedFreqResponse(int _f, int _inMin, int _inMax, int _outMin, int _outMax);
    
    // FRAME BOX
    void drawFrameBox(int _x, int _y, int _z, int _w, int _h, int _d);
    
    // GUI
    ofxPanel gui;
    ofParameter<int> pLineThickness;
    ofParameterGroup fxTypes;
    ofParameter<bool> converge;
    ofParameter<bool> glow;
    ofParameter<bool> shaker;
    ofParameter<bool> cut;
    ofParameter<bool> twist;
    ofParameter<bool> outline;
    ofParameter<bool> noise;
    ofParameter<bool> slitscan;
    ofParameter<bool> swell;
    ofParameter<bool> invert;
    ofParameter<bool> highContrast;
    ofParameter<bool> blueish;
    ofParameter<bool> greenish;
    ofParameter<bool> redish;
    ofParameter<bool> redInv;
    ofParameter<bool> blueInv;
    ofParameter<bool> greenInv;
    
    // Sound Player Parameters
    ofParameterGroup soundGUI;
    ofParameter<bool> isSoundReactive;
    ofParameter<bool> isSoundEnabled;
    ofParameter<float> soundLevel;
    
    // Mesh Parameters
    ofParameter<bool> isShowFrame;
    ofParameter<bool> isPointMode;
    ofParameter<bool> isWhiteColor;
    
    ofParameter<int> yStep;
    ofParameter<int> xStep;
    ofParameter<float> zMult;
    ofParameter<float> soundThresMult;
    
    // Glow FX GUI
    ofParameter<int> glowAmount;
    
#ifdef KORG_ENABLED
    // Korg GUI
    ofParameterGroup KorgGui;
    ofParameter<bool> KorgDebug;
    
    
    // Korg midi Controller
    ofxKorgNanoKontrol nano;
    void korgSliderChanged(int & _val);
    void korgButtonPressed(int & _val);
    void korgPotChanged(int & _val);
    void sceneButtonPressed(int & _val);
#endif
    // OFX TOOLKIT
    ofxToolKit tools;
    
    // FX
    ofxPostGlitch fx;
    ofFbo fbo;
    void updateFXParameters();
    
    // Video Player
    vector<ofVideoPlayer> vidPlayer;
    
    // Still Image
    vector<ofImage> images;
    ofPixels vidPlayerPx;
    
    // Video Grabber
    ofVideoGrabber 		vidGrabber;
    int 				camWidth;
    int 				camHeight;
    
    

    
    // Main Scene Mesh
    ofMesh mesh;
    ofColor meshColor;
    
    // Cameras
    ofxCameraMove saveCam;
    
    // Video Directory
    ofDirectory dirVid;
    
    
    
    // Random rotation variables
    ofColor color;
    
    ofVec3f pos;
    ofQuaternion rot;
    ofMatrix4x4 mat;
    ofVec3f rotationAxis;
    
    ofVec3f defCamPos;
    ofVec3f contTrans;
    ofVec3f contRot;
    ofVec3f camPos;
    
    int idVid;               // Video id
    int bufferCounter;
    int drawCounter;
    int curTransX;
    int curTransY;
    int curTransZ;
    
    float velocity;
    float size;
    
    int mode;
    string dirVidStr;
    
    // Global Light Options
    ofLight             light;
    
    // Scene Camera
    ofEasyCam cam;

    bool isDebug;
    bool isSaveEnabled;
    
    
    // Sound Player Analysis Parameters
    ProcessFFT fft;
    ofSoundPlayer 		mp3;
    
    float prevx, prevy;
    
    string folderPath;

};
