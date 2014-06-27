#pragma once

const unsigned short FRAME_RATE = 60;
const unsigned short PQLAB_PORT = 3334;

const unsigned short WINDOW_WIDTH = 1980;
const unsigned short WINDOW_HEIGHT = 1080;

const float RADIUS = 75.f;

const float CHORD_MAJOR_KEY_WIDTH = WINDOW_WIDTH / 12;

const bool IsFullScreen = true;

const bool IsMajorChord = true;

enum MajorChordType
{
	MAJOR_NOTHING,
	C_MAJOR,
	C_SHARP_MAJOR,
	D_MAJOR,
	D_SHARP_MAJOR,
	E_MAJOR,
	F_MAJOR,
	F_SHARP_MAJOR,
	G_MAJOR,
	G_SHARP_MAJOR,
	A_MAJOR,
	A_SHARP_MAJOR,
	B_MAJOR,
};

enum MinorChordType
{
	MINOR_NOTHING,
	C_MINOR,
	C_SHARP_MINOR,
	D_MINOR,
	D_SHARP_MINOR,
	E_MINOR,
	F_MINOR,
	F_SHARP_MINOR,
	G_MINOR,
	G_SHARP_MINOR,
	A_MINOR,
	A_SHARP_MINOR,
	B_MINOR,
};
