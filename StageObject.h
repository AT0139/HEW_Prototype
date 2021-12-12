#pragma once
#include "SelectStage.h"
#include "Texture.h"
#include "sprite.h"
class StageObject
{
public:
	StageObject() {};


	virtual ~StageObject() {}

	virtual HRESULT Init(void) = 0;
	virtual void Uninit(void) = 0;
	virtual void Update(void) = 0;
	virtual void Draw(void) = 0;

	//�N���b�N����
	virtual bool IsClick(void) = 0;
	virtual void ClickUpdate(void) = 0;

	//�}�E�X�I�[�o�[����
	virtual bool IsMouseOver(void) = 0;
	virtual void MouseOverUpdate(void) = 0;

protected:

	VERTEX_SELECT_STAGE m_Vertex;
};

