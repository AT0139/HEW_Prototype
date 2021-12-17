//=============================================================================
//
// �X�e�[�W�I����ʏ��� [SelectStage.h]
// Author :	yuta yanagisawa 
//
//=============================================================================
#pragma once



#include "StageObectFactory.h"
#include "EffectFactory.h"


//*****************************************************************************
// �}�N����`
//*****************************************************************************




//*****************************************************************************
// �N���X
//*****************************************************************************

class StageObject;
class Effect;

class SelectStage {
public:
	SelectStage();
	~SelectStage();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void Create(void);

	void Click(void);
	void MouseOver(void);

private:
	static const int STAGE_OBJECT_MAX = 3;

	StageObject* m_pStageObjects[STAGE_OBJECT_MAX];

	static const int EFFECT_MAX = 3;

	Effect* m_effect[EFFECT_MAX];


	StageObectFactory m_SOF;
	EffectFactory m_EF;
};