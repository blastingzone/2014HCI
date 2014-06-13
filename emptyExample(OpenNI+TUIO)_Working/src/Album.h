#pragma once
#include "GameObject.h"
#include "Config.h"
#include "ofImage.h"

class Pictures;

class Album : public GameObject
{
public:
	Album();
	virtual ~Album();

	virtual void Render();
	virtual void Update(float dt);

	void Init();
	void TapEventHandler();
	void DoubleTapEventHandler();
	void DragEventHandler(float x, float y); // + multi finger drag + flick Event
	void UpdateChildDistance(float scale);

	void AddPicture(int id, Pictures* pic);

	bool IsTouchedMe(float x, float y);
	std::vector<Pictures*> m_PictureList;

	

private:
	void SpreadChildPictures();

	ALBUM_STATUS m_AlbumStatus;

	ofImage m_AlbumCoverImg;

	float m_previousTapTime;
};