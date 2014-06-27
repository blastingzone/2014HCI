#pragma once
#include "of3dGraphics.h"
#include "Config.h"
#include "ofSoundPlayer.h"

class Guitar;
class Piano;
class Bass;

class MusicManager
{
public:
	MusicManager() {};
	~MusicManager();
	
	void Init();
	void Update();
	void RenderInstruments();

	void PlayGuitar(float volume);
	void PlayPiano(float volume, int keyNum);
	void PlayBass(float volume);

	void UpdateGuitarPosition(float x, float y);
	void UpdateBassPosition(float x, float y);
	bool IsGuitarInOutState(float x, float y);
	bool IsBassInOutState(float x, float y);

	void ChangeChord(MajorChordType chord) { m_CurrentMajChord = chord; }
	void ChangeChord(MinorChordType chord) { m_CurrentMinChord = chord; }

	ofPoint GetGuitarCollisionBoxCenter();

private:
	Guitar* m_Guitar;
	Piano* m_Piano;
	Bass* m_Bass;

	MajorChordType m_CurrentMajChord;
	MinorChordType m_CurrentMinChord;
};