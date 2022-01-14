//=============================================================================
//
// ���U���g��ʏ��� [result.cpp]
// Author : 
//
//=============================================================================

#include "main.h"
#include "result.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include <cmath>
#include "sound.h"


//*****************************************************************************
// �}�N����`
//*****************************************************************************

#define SCREEN_WIDTH	(1920 )				// �E�C���h�E�̕�
#define SCREEN_HEIGHT	(1080 )				// �E�C���h�E�̍���

#define SCEREN_WIDTH_HURF SCREEN_WIDTH / 2
#define SCEREN_HEIGHT_HURF SCREEN_HEIGHT / 2

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************



//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static int	g_TextureNo;	// �e�N�X�`�����
static int Number_Texture;	// �ԍ�
static int g_cursor;		//�J�[�\��
static int g_UI[3];			//UI

struct VERTEX_NOMAL Result_Ui;

D3DXVECTOR2 Mouse_pos(0.0f, 0.0f);

float Result_Uipos1;
float Result_Uipos3;

//	�T�E���h�p�̃C���f�b�N�X
static int g_SoundIndex = 0;

//=============================================================================
// ����������
//=============================================================================
HRESULT InitResult(void)
{
	ShowCursor(false);

	//�e�N�X�`�����[�h----------------
	Number_Texture = LoadTexture("data/TEXTURE/number2.png");
	g_TextureNo = LoadTexture("data/TEXTURE/result.png");
	g_cursor = LoadTexture("data/TEXTURE/cursor.png");

	g_UI[0] = LoadTexture("data/TEXTURE/UI1.png");
	g_UI[1] = LoadTexture("data/TEXTURE/UI2.png");
	g_UI[2] = LoadTexture("data/TEXTURE/UI3.png");



	//-------------������-------------
	////////==����==////////
	//�P����
	{
		Timer_Vertex.alpha = 0.0f;
		Timer_Vertex.counter = 0;
		Timer_Vertex.pos = D3DXVECTOR2(SCREEN_WIDTH * 6.5 / 8, SCREEN_HEIGHT / 10);
		Timer_Vertex.size = D3DXVECTOR2(75, 75);
		Timer_Vertex.u = 0.0f;
		Timer_Vertex.v = 0.0f;
		Timer_Vertex.use = true;
	}

	//�����_��1��
	{
		Timer_Second.pos = D3DXVECTOR2(Timer_Vertex.pos.x + 100.0f, SCREEN_HEIGHT / 10);
		Timer_Second.size = D3DXVECTOR2(75, 75);
		Timer_Second.u = 0.0f;
		Timer_Second.v = 0.0f;
	}

	//�����_��2��
	{
		Timer_Third.pos = D3DXVECTOR2(Timer_Vertex.pos.x + 200.0f, SCREEN_HEIGHT / 10);
		Timer_Third.size = D3DXVECTOR2(75, 75);
		Timer_Third.u = 0.0f;
		Timer_Third.v = 0.0f;
	}

	////////==UI==////////
	Result_Ui.pos = D3DXVECTOR2(SCEREN_WIDTH_HURF, SCREEN_HEIGHT * 0.75);
	Result_Ui.size = D3DXVECTOR2(300.0f, 300.0f);

	Result_Uipos1 = Result_Ui.pos.x - 500.0f;
	Result_Uipos3 = Result_Ui.pos.x + 500.0f;

	//BGM����
	g_SoundIndex = LoadSound("data/BGM/mega.wav");

	//	�������[���O���[�o���ϐ��A�������[��0�`1�܂ł̐��l
	//�ŉ��ʂ��ݒ�ł��܂�
	SetVolume(g_SoundIndex, 0.5f);

	PlaySound(g_SoundIndex, 256);


	return S_OK;

}

//=============================================================================
// �I������
//=============================================================================
void UninitResult(void)
{
	ShowCursor(true);

	StopSound(g_SoundIndex);
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateResult(void)
{
	Mouse_pos.x = GetMousePosX();
	Mouse_pos.y = GetMousePosY();

	if (IsMouseLeftPressed())
	{
		if (Mouse_pos.y >= Result_Ui.pos.y - Result_Ui.size.y / 2 &&
			Mouse_pos.y <= Result_Ui.pos.y + Result_Ui.size.y / 2)
		{
			if (Mouse_pos.x >= Result_Uipos1 - Result_Ui.size.x / 2 &&
				Mouse_pos.x <= Result_Uipos1 + Result_Ui.size.x / 2)
			{
				SceneTransition(SCENE_TITLE);

			}

			if (Mouse_pos.x >= Result_Ui.pos.x - Result_Ui.size.x / 2 &&
				Mouse_pos.x <= Result_Ui.pos.x + Result_Ui.size.x / 2)
			{
				SceneTransition(SCENE_TITLE);

			}

			if (Mouse_pos.x >= Result_Uipos3 - Result_Ui.size.x / 2 &&
				Mouse_pos.x <= Result_Uipos3 + Result_Ui.size.x / 2)
			{

			}

		}

	}

	//if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
	//{
	//	SceneTransition(SCENE_TITLE);
	//}
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawResult(void)
{
	//�P���̃|���S���̒��_�ƃe�N�X�`�����W��ݒ�
	DrawSpriteLeftTop(g_TextureNo, 0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, 0.0f, 1.0f, 1.0f);

	//////�P����
	DrawSprite(Number_Texture, Timer_Vertex.pos.x, Timer_Vertex.pos.y,
		Timer_Vertex.size.x, Timer_Vertex.size.y,
		Timer_Vertex.u, Timer_Vertex.v, NUMBER_WIDTH, NUMBER_HEIGHT);

	////�����_��1��
	DrawSprite(g_TextureNo, Timer_Second.pos.x, Timer_Second.pos.y,
		Timer_Second.size.x, Timer_Second.size.y,
		Timer_Second.u, Timer_Second.v, NUMBER_WIDTH, NUMBER_HEIGHT);

	////�����_��2��
	DrawSprite(g_TextureNo, Timer_Third.pos.x, Timer_Third.pos.y,
		Timer_Third.size.x, Timer_Third.size.y,
		Timer_Third.u, Timer_Third.v, NUMBER_WIDTH, NUMBER_HEIGHT);

	////UI
	DrawSprite(g_UI[0], Result_Uipos1, Result_Ui.pos.y,
		Result_Ui.size.x, Result_Ui.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);


	DrawSprite(g_UI[1], Result_Ui.pos.x, Result_Ui.pos.y,
		Result_Ui.size.x + 100.0f, Result_Ui.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);

	DrawSprite(g_UI[2], Result_Uipos3, Result_Ui.pos.y,
		Result_Ui.size.x, Result_Ui.size.y,
		0.0f, 0.0f, 1.0f, 1.0f);

	//// �}�E�X�J�[�\��
	DrawSprite(g_cursor, Mouse_pos.x, Mouse_pos.y,
		75.0f, 75.0f,
		0.0f, 0.0f, 1.0f, 1.0f);



}