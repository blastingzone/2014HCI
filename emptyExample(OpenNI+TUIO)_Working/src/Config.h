#pragma once
#include <array>

//------------------------------- SHARED -------------------------------

const unsigned short WINDOW_WIDTH = 640;
const unsigned short WINDOW_HEIGHT = 480;



//------------------------------- KINECT -------------------------------

const unsigned int KINECT_BLOCK_WIDTH = 30;
const unsigned int KINECT_BLOCK_HEIGHT = 30;

const unsigned int KINECT_BLOCK_NUMBER = 30;

enum DIRECTION
{
	X_DIR,
	Y_DIR
};

const std::array<ofPoint, KINECT_BLOCK_NUMBER> KINECT_BLOCK_LOCATIONS =
{
	ofPoint(25, 30),
	ofPoint(55, 30),
	ofPoint(85, 30),
	ofPoint(115, 30),
	ofPoint(145, 30),
	ofPoint(175, 30),
	ofPoint(205, 30),
	ofPoint(235, 30),
	ofPoint(265, 30),
	ofPoint(295, 30),
	ofPoint(325, 30),
	ofPoint(355, 30),
	ofPoint(385, 30),
	ofPoint(415, 30),
	ofPoint(445, 30),
	ofPoint(475, 30),
	ofPoint(505, 30),
	ofPoint(535, 30),
	ofPoint(565, 30),
	ofPoint(595, 30),
	ofPoint(55, 60),
	ofPoint(85, 60),
	ofPoint(115, 60),
	ofPoint(175, 60),
	ofPoint(205, 60),
	ofPoint(235, 60),
	ofPoint(265, 60),
	ofPoint(295, 60),
	ofPoint(325, 60),
	ofPoint(355, 60)
};

//------------------------------- KINECT END -------------------------------



//------------------------------- PQLAB -------------------------------
enum ALBUM_STATUS 
{
	ALBUM_NORMAL,
	ALBUM_SELECTED,
	ALBUM_SPREAD,
	ALBUM_MOVING,
	ALBUM_SQUEEZE,
	ALBUM_SPLAY
};

enum PICTURE_STATUS
{
	PIC_HIDE,
	PIC_NORMAL,
	PIC_SELECTED,
	PIC_ROTATION,
	PIC_RESIZE,
	PIC_FLICK
};


const unsigned int ALBUM_WIDTH = 100;
const unsigned int ALBUM_HEIGHT = 150;

const unsigned int PICTURE_WIDTH = 120;
const unsigned int PICTURE_HEIGHT = 200;

const unsigned short PQLAB_WINDOW_WIDTH = 1280;
const unsigned short PQLAB_WINDOW_HEIGHT = 800;