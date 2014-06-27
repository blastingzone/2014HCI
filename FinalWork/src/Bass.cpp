#include "Bass.h"

void Bass::Init()
{
	m_PictureImg.loadImage("Bass.png");

// 	m_C.loadSound("sounds/BassC.mp3");
// 	m_C.setMultiPlay(true);
// 
// 	m_CSharp.loadSound("sounds/BassCSharp.mp3");
// 	m_CSharp.setMultiPlay(true);
// 
// 	m_D.loadSound("sounds/BassD.mp3");
// 	m_D.setMultiPlay(true);
// 
// 	m_DSharp.loadSound("sounds/BassDSharp.mp3");
// 	m_DSharp.setMultiPlay(true);
// 
// 	m_E.loadSound("sounds/BassE.mp3");
// 	m_E.setMultiPlay(true);
// 
// 	m_F.loadSound("sounds/BassF.mp3");
// 	m_F.setMultiPlay(true);
// 
// 	m_FSharp.loadSound("sounds/BassFSharp.mp3");
// 	m_FSharp.setMultiPlay(true);
// 
// 	m_G.loadSound("sounds/BassG.mp3");
// 	m_G.setMultiPlay(true);
// 
// 	m_GSharp.loadSound("sounds/BassGSharp.mp3");
// 	m_GSharp.setMultiPlay(true);
// 
// 	m_A.loadSound("sounds/BassA.mp3");
// 	m_A.setMultiPlay(true);
// 
// 	m_ASharp.loadSound("sounds/BassASharp.mp3");
// 	m_ASharp.setMultiPlay(true);

	m_C.loadSound("sounds/GuitarC_A.mp3");
	m_C.setMultiPlay(true);

	m_CSharp.loadSound("sounds/GuitarCSharp_A.mp3");
	m_CSharp.setMultiPlay(true);

	m_D.loadSound("sounds/GuitarD_A.mp3");
	m_D.setMultiPlay(true);

	m_DSharp.loadSound("sounds/GuitarDSharp_A.mp3");
	m_DSharp.setMultiPlay(true);

	m_E.loadSound("sounds/GuitarE_A.mp3");
	m_E.setMultiPlay(true);

	m_F.loadSound("sounds/GuitarF_A.mp3");
	m_F.setMultiPlay(true);

	m_FSharp.loadSound("sounds/GuitarFSharp_A.mp3");
	m_FSharp.setMultiPlay(true);

	m_G.loadSound("sounds/GuitarG_A.mp3");
	m_G.setMultiPlay(true);

	m_GSharp.loadSound("sounds/GuitarGSharp_A.mp3");
	m_GSharp.setMultiPlay(true);

	m_A.loadSound("sounds/GuitarA_A.mp3");
	m_A.setMultiPlay(true);

	m_ASharp.loadSound("sounds/GuitarASharp_A.mp3");
	m_ASharp.setMultiPlay(true);

	m_B.loadSound("sounds/GuitarB_A.mp3");
	m_B.setMultiPlay(true);
}

void Bass::Update( float dt )
{

}

void Bass::Play( MajorChordType chord, float volume )
{
	UpdateChord(chord);

	for(auto &iter : m_ToPlaySoundList)
	{
		iter->setVolume(volume);
		iter->play();
	}
}

void Bass::Play( MinorChordType chord, float volume )
{
	UpdateChord(chord);

	for(auto &iter : m_ToPlaySoundList)
	{
		iter->setVolume(volume);
		iter->play();
	}
}

void Bass::Render()
{
	//m_PictureImg.draw(m_Position.x, m_Position.y, 0, 400, 300);
	m_PictureImg.draw(m_Position.x, m_Position.y, 0, 600, 450);

	ofCircle(m_CollisionBox.maxCoordinate, RADIUS);
}

bool Bass::IsInBass( float x, float y )
{
	float dist = ofDist(x, y, m_CollisionBox.maxCoordinate.x, m_CollisionBox.maxCoordinate.y);

	if (dist < RADIUS)
		return true;
	else
		return false;
}

void Bass::UpdateChord( MajorChordType chord )
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

void Bass::UpdateChord( MinorChordType chord )
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
