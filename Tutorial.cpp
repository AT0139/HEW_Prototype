//-------------------------------
//	[Tutorial.cpp]	
//-------------------------------
//	create -> ���V�D��
//	change -> ����
//	
//-------------------------------
#include "Tutorial.h"
#include "input.h"
#include "Texture.h"

void Tutorial::TutorialTextureLoad()
{
	m_TexIndex_001 = LoadTexture(m_TexName_001);
}

void Tutorial::Init()
{
	//�e�N�X�`�����[�h
	TutorialTextureLoad();

	//���̒��ɂ͏����������Ȃ��ł�������
	//�֐��̒��ɏ����Ă�������
	switch (m_nowPage)
	{
	case TUTORIAL_001:
		TutorialInit_001();
		break;
	case TUTORIAL_002:
		TutorialInit_002();
		break;
	case TUTORIAL_003:
		TutorialInit_003();
		break;
	case TUTORIAL_004:
		TutorialInit_004();
		break;
	default:
		break;
	}
}

void Tutorial::Uninit()
{
	//���̒��ɂ͏����������Ȃ��ł�������
	//�֐��̒��ɏ����Ă�������
	
	//�����͂���Ȃ������H

}

void Tutorial::Update()
{
	//���̒��ɂ͏����������Ȃ��ł�������
	//�֐��̒��ɏ����Ă�������


	//	���̃y�[�W��
	if (GetKeyboardTrigger(DIK_RETURN) ||
		GetKeyboardTrigger(DIK_SPACE) ||
		IsMouseLeftTriggered())
	{
		m_nowPage++;
	}

	switch (m_nowPage)
	{
	case TUTORIAL_001:
		TutorialUpdate_001();
		break;
	case TUTORIAL_002:
		TutorialUpdate_002();
		break;
	case TUTORIAL_003:
		TutorialUpdate_003();
		break;
	case TUTORIAL_004:
		TutorialUpdate_004();
		break;
	default:
		break;
	}
}

void Tutorial::Draw()
{
	//���̒��ɂ͏����������Ȃ��ł�������
	//�֐��̒��ɏ����Ă�������
	switch (m_nowPage)
	{
	case TUTORIAL_001:
		TutorialDraw_001();
		break;
	case TUTORIAL_002:
		TutorialDraw_002();
		break;
	case TUTORIAL_003:
		TutorialDraw_003();
		break;
	case TUTORIAL_004:
		TutorialDraw_004();
		break;
	default:
		break;
	}
}



//-------------------------------
//	Init
//-------------------------------
void Tutorial::TutorialInit_001()
{
}

void Tutorial::TutorialInit_002()
{
}

void Tutorial::TutorialInit_003()
{
}

void Tutorial::TutorialInit_004()
{
}


//-------------------------------
//	Update
//-------------------------------
void Tutorial::TutorialUpdate_001()
{
}

void Tutorial::TutorialUpdate_002()
{
}

void Tutorial::TutorialUpdate_003()
{
}

void Tutorial::TutorialUpdate_004()
{
	//�����ŃQ�[���V�[���֑J��
}

//-------------------------------
//	Draw
//-------------------------------
void Tutorial::TutorialDraw_001()
{
}

void Tutorial::TutorialDraw_002()
{
}

void Tutorial::TutorialDraw_003()
{
}

void Tutorial::TutorialDraw_004()
{
}


