#include "Piano.h"
#include "ofAppRunner.h"

void Piano::Init()
{
	m_PictureImg.loadImage("Keyboard.png");

	m_C.loadSound("sounds/PianoC.mp3");
	m_C.setMultiPlay(true);

	m_CSharp.loadSound("sounds/PianoCSharp.mp3");
	m_CSharp.setMultiPlay(true);

	m_D.loadSound("sounds/PianoD.mp3");
	m_D.setMultiPlay(true);

	m_DSharp.loadSound("sounds/PianoDSharp.mp3");
	m_DSharp.setMultiPlay(true);

	m_E.loadSound("sounds/PianoE.mp3");
	m_E.setMultiPlay(true);

	m_F.loadSound("sounds/PianoF.mp3");
	m_F.setMultiPlay(true);

	m_FSharp.loadSound("sounds/PianoFSharp.mp3");
	m_FSharp.setMultiPlay(true);

	m_G.loadSound("sounds/PianoG.mp3");
	m_G.setMultiPlay(true);

	m_GSharp.loadSound("sounds/PianoGSharp.mp3");
	m_GSharp.setMultiPlay(true);

	m_A.loadSound("sounds/PianoA.mp3");
	m_A.setMultiPlay(true);

	m_ASharp.loadSound("sounds/PianoASharp.mp3");
	m_ASharp.setMultiPlay(true);

	m_B.loadSound("sounds/PianoB.mp3");
	m_B.setMultiPlay(true);
}

void Piano::Update(float dt)
{

}

void Piano::Play( MajorChordType chord, float volume, int keyNum )
{
	UpdateChord(chord);

	for(auto &iter : m_ToPlaySoundList)
	{
		iter->setVolume(volume);
	}

	auto &sound = m_ToPlaySoundList.begin();

	for(int i = 0; (i < keyNum) && (i < m_ToPlaySoundList.size()); ++i)
	{
		(*sound)->play();
		++sound;
	}
}

void Piano::Play( MinorChordType chord, float volume, int keyNum )
{
	UpdateChord(chord);

	for(auto &iter : m_ToPlaySoundList)
	{
		iter->setVolume(volume);
	}

	auto &sound = m_ToPlaySoundList.begin();

	for(int i = 0; (i < keyNum) && (i < m_ToPlaySoundList.size()); ++i)
	{
		(*sound)->play();
		++sound;
	}
}

void Piano::Render()
{
	m_PictureImg.draw(0, WINDOW_HEIGHT-150, 0, WINDOW_WIDTH, 150);
}

void Piano::UpdateChord( MajorChordType chord )
{
	m_ToPlaySoundList.clear();

	switch(chord)
	{
	case C_MAJOR:
		m_ToPlaySoundList.push_back(&m_C);
		m_ToPlaySoundList.push_back(&m_E);
		m_ToPlaySoundList.push_back(&m_G);
		break;
	case C_SHARP_MAJOR:
		m_ToPlaySoundList.push_back(&m_CSharp);
		m_ToPlaySoundList.push_back(&m_F);
		m_ToPlaySoundList.push_back(&m_GSharp);
		break;
	case D_MAJOR:
		m_ToPlaySoundList.push_back(&m_D);
		m_ToPlaySoundList.push_back(&m_FSharp);
		m_ToPlaySoundList.push_back(&m_A);
		break;
	case D_SHARP_MAJOR:
		m_ToPlaySoundList.push_back(&m_DSharp);
		m_ToPlaySoundList.push_back(&m_G);
		m_ToPlaySoundList.push_back(&m_ASharp);
		break;
	case E_MAJOR:
		m_ToPlaySoundList.push_back(&m_E);
		m_ToPlaySoundList.push_back(&m_GSharp);
		m_ToPlaySoundList.push_back(&m_B);
		break;
	case F_MAJOR:
		m_ToPlaySoundList.push_back(&m_F);
		m_ToPlaySoundList.push_back(&m_A);
		m_ToPlaySoundList.push_back(&m_C);
		break;
	case F_SHARP_MAJOR:
		m_ToPlaySoundList.push_back(&m_FSharp);
		m_ToPlaySoundList.push_back(&m_ASharp);
		m_ToPlaySoundList.push_back(&m_CSharp);
		break;
	case G_MAJOR:
		m_ToPlaySoundList.push_back(&m_G);
		m_ToPlaySoundList.push_back(&m_B);
		m_ToPlaySoundList.push_back(&m_D);
		break;
	case G_SHARP_MAJOR:
		m_ToPlaySoundList.push_back(&m_GSharp);
		m_ToPlaySoundList.push_back(&m_C);
		m_ToPlaySoundList.push_back(&m_DSharp);
		break;
	case A_MAJOR:
		m_ToPlaySoundList.push_back(&m_A);
		m_ToPlaySoundList.push_back(&m_CSharp);
		m_ToPlaySoundList.push_back(&m_E);
		break;
	case A_SHARP_MAJOR:
		m_ToPlaySoundList.push_back(&m_ASharp);
		m_ToPlaySoundList.push_back(&m_D);
		m_ToPlaySoundList.push_back(&m_F);
		break;
	case B_MAJOR:
		m_ToPlaySoundList.push_back(&m_B);
		m_ToPlaySoundList.push_back(&m_DSharp);
		m_ToPlaySoundList.push_back(&m_FSharp);
		break;
	}
}

void Piano::UpdateChord( MinorChordType chord )
{
	m_ToPlaySoundList.clear();
	
	switch(chord)
	{
	case C_MINOR:
		m_ToPlaySoundList.push_back(&m_C);
		m_ToPlaySoundList.push_back(&m_DSharp);
		m_ToPlaySoundList.push_back(&m_G);
		break;
	case C_SHARP_MINOR:
		m_ToPlaySoundList.push_back(&m_CSharp);
		m_ToPlaySoundList.push_back(&m_E);
		m_ToPlaySoundList.push_back(&m_G);
		break;
	case D_MINOR:
		m_ToPlaySoundList.push_back(&m_D);
		m_ToPlaySoundList.push_back(&m_F);
		m_ToPlaySoundList.push_back(&m_A);
		break;
	case D_SHARP_MINOR:
		m_ToPlaySoundList.push_back(&m_DSharp);
		m_ToPlaySoundList.push_back(&m_FSharp);
		m_ToPlaySoundList.push_back(&m_ASharp);
		break;
	case E_MINOR:
		m_ToPlaySoundList.push_back(&m_E);
		m_ToPlaySoundList.push_back(&m_G);
		m_ToPlaySoundList.push_back(&m_B);
		break;
	case F_MINOR:
		m_ToPlaySoundList.push_back(&m_F);
		m_ToPlaySoundList.push_back(&m_GSharp);
		m_ToPlaySoundList.push_back(&m_C);
		break;
	case F_SHARP_MINOR:
		m_ToPlaySoundList.push_back(&m_FSharp);
		m_ToPlaySoundList.push_back(&m_A);
		m_ToPlaySoundList.push_back(&m_CSharp);
		break;
	case G_MINOR:
		m_ToPlaySoundList.push_back(&m_G);
		m_ToPlaySoundList.push_back(&m_ASharp);
		m_ToPlaySoundList.push_back(&m_D);
		break;
	case G_SHARP_MINOR:
		m_ToPlaySoundList.push_back(&m_GSharp);
		m_ToPlaySoundList.push_back(&m_B);
		m_ToPlaySoundList.push_back(&m_DSharp);
		break;
	case A_MINOR:
		m_ToPlaySoundList.push_back(&m_A);
		m_ToPlaySoundList.push_back(&m_C);
		m_ToPlaySoundList.push_back(&m_E);
		break;
	case A_SHARP_MINOR:
		m_ToPlaySoundList.push_back(&m_ASharp);
		m_ToPlaySoundList.push_back(&m_CSharp);
		m_ToPlaySoundList.push_back(&m_F);
		break;
	case B_MINOR:
		m_ToPlaySoundList.push_back(&m_B);
		m_ToPlaySoundList.push_back(&m_D);
		m_ToPlaySoundList.push_back(&m_FSharp);
		break;
	}

}
