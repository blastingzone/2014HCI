#include "Guitar.h"
#include "ofMath.h"

void Guitar::Init()
{
	m_PictureImg.loadImage("Guitar.png");

	m_C.loadSound("sounds/GuitarC.mp3");
	m_C.setMultiPlay(true);

	m_CSharp.loadSound("sounds/GuitarCSharp.mp3");
	m_CSharp.setMultiPlay(true);

	m_D.loadSound("sounds/GuitarD.mp3");
	m_D.setMultiPlay(true);

	m_DSharp.loadSound("sounds/GuitarDSharp.mp3");
	m_DSharp.setMultiPlay(true);

	m_E.loadSound("sounds/GuitarE.mp3");
	m_E.setMultiPlay(true);

	m_F.loadSound("sounds/GuitarF.mp3");
	m_F.setMultiPlay(true);

	m_FSharp.loadSound("sounds/GuitarFSharp.mp3");
	m_FSharp.setMultiPlay(true);

	m_G.loadSound("sounds/GuitarG.mp3");
	m_G.setMultiPlay(true);

	m_GSharp.loadSound("sounds/GuitarGSharp.mp3");
	m_GSharp.setMultiPlay(true);

	m_A.loadSound("sounds/GuitarA.mp3");
	m_A.setMultiPlay(true);

	m_ASharp.loadSound("sounds/GuitarASharp.mp3");
	m_ASharp.setMultiPlay(true);

	m_B.loadSound("sounds/GuitarB.mp3");
	m_B.setMultiPlay(true);
}

void Guitar::Update(float dt)
{

}

void Guitar::Play( MajorChordType chord, float volume )
{
	UpdateChord(chord);

	for(auto &iter : m_ToPlaySoundList)
	{
		iter->setVolume(volume);
		iter->play();
	}
}

void Guitar::Play( MinorChordType chord, float volume )
{
	UpdateChord(chord);

	for(auto &iter : m_ToPlaySoundList)
	{
		iter->setVolume(volume);
		iter->play();
	}
}

void Guitar::Render()
{
	//m_PictureImg.draw(m_Position.x, m_Position.y, 0, 400, 300);
	m_PictureImg.draw(m_Position.x, m_Position.y, 0, 600, 450);

	ofCircle(m_CollisionBox.maxCoordinate, RADIUS);
}

bool Guitar::IsInGuitar( float x, float y )
{
	float dist = ofDist(x, y, m_CollisionBox.maxCoordinate.x, m_CollisionBox.maxCoordinate.y);

	if (dist < RADIUS)
		return true;
	else
		return false;
}

void Guitar::UpdateChord( MajorChordType chord )
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

void Guitar::UpdateChord( MinorChordType chord )
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
