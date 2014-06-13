#pragma once
#include "GameObject.h"
#include "Config.h"
#include "ofImage.h"

class Pictures : public GameObject
{
public:
	Pictures();
	virtual ~Pictures();

	void Init(std::string fileName);
	void TapEventHandler();
	void PinchOrSpreadEventHandler(float distance);
	void SetScale(float scale);
	void SetStatus(PICTURE_STATUS status) { m_PictureStatus = status; };
	void SetRotate(float angle);

	void SmartSetPosition( float x, float y );

	void DragEventHandler(float x, float y);

	bool IsTouchedMe(float x, float y);

	virtual void Render();
	virtual void Update( float dt );

private:
	PICTURE_STATUS m_PictureStatus;
	ofImage m_PictureImg;

	float m_ImgWidth;
	float m_ImgHeight;
	float m_RotationAngle;


	float m_PreviousDistance;
};