#pragma once
#include "GameObject.h"
#include "ofSoundPlayer.h"
#include "Config.h"
#include "ofImage.h"
#include <list>

class Guitar : public GameObject
{
public:
	Guitar() {};
	virtual ~Guitar() {};
	
	void Init();
	void Play(MajorChordType chord, float volume);
	void Play(MinorChordType chord, float volume);

	virtual void Render();
	virtual void Update(float dt);

	void UpdateChord(MajorChordType chord);
	void UpdateChord(MinorChordType chord);

	bool IsInGuitar(float x, float y);

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