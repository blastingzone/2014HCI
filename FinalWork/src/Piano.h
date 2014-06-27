#pragma once
#include "GameObject.h"
#include "ofSoundPlayer.h"
#include "Config.h"
#include <list>
#include "ofImage.h"

class Piano : public GameObject
{
public:
	Piano() {};
	virtual ~Piano() {};
	
	void Init();
	void Play(MajorChordType chord, float volume, int keyNum);
	void Play(MinorChordType chord, float volume, int keyNum);

	void UpdateChord(MajorChordType chord);
	void UpdateChord(MinorChordType chord);

	virtual void Render();
	virtual void Update(float dt);

private:
	ofSoundPlayer m_C;
	ofSoundPlayer m_CSharp;
	ofSoundPlayer m_D;
	ofSoundPlayer m_DSharp;
	ofSoundPlayer m_E;
	ofSoundPlayer m_F;
	ofSoundPlayer m_FSharp;
	ofSoundPlayer m_G;
	ofSoundPlayer m_GSharp;
	ofSoundPlayer m_A;
	ofSoundPlayer m_ASharp;
	ofSoundPlayer m_B;

	ofImage m_PictureImg;

	std::list<ofSoundPlayer*> m_ToPlaySoundList;
};