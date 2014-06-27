#include "MusicManager.h"
#include "Guitar.h"
#include "Bass.h"
#include "Piano.h"


void MusicManager::Init()
{
	m_Guitar = new Guitar();
	m_Piano = new Piano();
	m_Bass = new Bass();

	m_CurrentMajChord = C_MAJOR;
	m_CurrentMinChord = C_MINOR;

	m_Guitar->Init();
	m_Piano->Init();
	m_Bass->Init();
}

void MusicManager::Update()
{
	ofSoundUpdate();
}

MusicManager::~MusicManager()
{
	delete m_Guitar;
	delete m_Piano;
	delete m_Bass;
}

void MusicManager::PlayGuitar(float volume)
{
	if (IsMajorChord)
	{
		m_Guitar->Play(m_CurrentMajChord, volume);
	}
	else
	{
		m_Guitar->Play(m_CurrentMinChord, volume);
	}
}

void MusicManager::PlayPiano(float volume, int keyNum)
{
	m_Piano->Play(m_CurrentMajChord, volume, keyNum);
}

void MusicManager::PlayBass(float volume)
{
	if (IsMajorChord)
	{
		m_Bass->Play(m_CurrentMajChord, volume);
	}
	else
	{
		m_Bass->Play(m_CurrentMinChord, volume);
	}
}

void MusicManager::RenderInstruments()
{
	m_Guitar->Render();
	m_Piano->Render();
	m_Bass->Render();
}

void MusicManager::UpdateGuitarPosition( float x, float y )
{
	m_Guitar->SetPosition(x, y);
	//m_Guitar->UpdateCollisionBox(x + 320, y + 210, 0.f, 0.f);
	m_Guitar->UpdateCollisionBox(x + 480, y + 315, 0.f, 0.f);

}

void MusicManager::UpdateBassPosition( float x, float y )
{
	m_Bass->SetPosition(x, y);
	//m_Bass->UpdateCollisionBox(x + 320, y + 210, 0.f, 0.f);
	m_Bass->UpdateCollisionBox(x + 480, y + 315, 0.f, 0.f);
}

bool MusicManager::IsGuitarInOutState( float x, float y )
{
	return m_Guitar->IsInGuitar(x, y);
}

bool MusicManager::IsBassInOutState( float x, float y )
{
	return m_Bass->IsInBass(x, y);
}

ofPoint MusicManager::GetGuitarCollisionBoxCenter()
{
	return m_Guitar->m_CollisionBox.maxCoordinate;
}
