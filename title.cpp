//=============================================================================
//
// �^�C�g����ʏ��� [title.cpp]
// Author : 
//
//=============================================================================
#include "title.h"
#include "input.h"
#include "texture.h"
#include "sprite.h"
#include "fade.h"
#include "GO_SS_Player.h"


//*****************************************************************************
// �}�N����`
//*****************************************************************************


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static int				g_TextureNo[5] = { 0,0,0,0,0 };	// �e�N�X�`�����
static VERTEX_TITLE_PLAYER g_Player;

int i = 0;

static const FLOAT GRAVITY_ACCELERATION = 0.3f;

static FLOAT m_Jump = -10.75f;
static FLOAT g_gravity = 1.0f;


//=============================================================================
// ����������
//=============================================================================
HRESULT InitTitle(void)
{
	TO_Init();

	//�e�N�X�`������
	g_TextureNo[0] = LoadTexture("data/TEXTURE/title.png");
	g_TextureNo[1] = LoadTexture("data/TEXTURE/mati1.png");//�r���Q
	g_TextureNo[2] = LoadTexture("data/TEXTURE/target.png");//�t�b�N
	g_TextureNo[3] = LoadTexture("data/TEXTURE/jump2.png");//
	g_TextureNo[4] = LoadTexture("data/TEXTURE/title.png");

	g_Player.angle = 0.0f;
	g_Player.frame = 0;
	g_Player.pos = D3DXVECTOR2(-80.0f, SCREEN_HEIGHT/7.5f);
	g_Player.size = D3DXVECTOR2(0.0f, 0.0F);
	g_Player.u = 0.0f;
	g_Player.v = 0.0f;
	g_Player.use = true;

	g_gravity *= m_Jump;

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void UninitTitle(void)
{
	TO_Uninit();
}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateTitle(void)
{
	//�A�j���[�V�����̃t���[������
	if (g_Player.frame >= PLAYER_X_NUM * PLAYER_Y_NUM)
	{
		g_Player.frame = 0;
	}
	else {
		if (i == 20) {
			g_Player.frame++;
			i = 0;
		}
		else
			i++;
	}
	if (g_Player.use) {
		g_Player.u = g_Player.frame % PLAYER_X_NUM * PLAYER_WIDTH;
		g_Player.v = g_Player.frame / PLAYER_Y_NUM * PLAYER_HEIGHT;
	}


	TO_Update();

	//�V�[���J��
	if (GetKeyboardTrigger(DIK_RETURN) && GetFadeState() == FADE_NONE)
	{
		SceneTransition(SCENE_SELECT_STAGE);
	}


	//�v���C���[��x�����̓���
	if (g_Player.pos.x >= SCREEN_WIDTH/ 2.0f + 200.0f) {
		g_Player.pos.x = SCREEN_WIDTH / 2.0f + 200.0f;
	}
	else {
		g_Player.pos.x += 11.0f;
	}
	
	//�v���C���[y�����̓���
	if (g_Player.pos.y >= SCREEN_HEIGHT / 2.0f + 75.0f) {
		g_Player.pos.y = SCREEN_HEIGHT / 2.0f + 75.0f;


	}
	else {
		g_gravity += GRAVITY_ACCELERATION;
		g_Player.pos.y += g_gravity;
	}
	
}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawTitle(void)
{
	TO_Draw();

	// �P���̃|���S���̒��_�ƃe�N�X�`�����W��ݒ�
	DrawSprite(g_TextureNo[1], SCREEN_WIDTH / 2, SCREEN_HEIGHT * 0.75,
		SCREEN_WIDTH, 749.6727f,
		0.0f, 0.0f, 1.0f, 1.0f);

	DrawSpriteLeftTop(g_TextureNo[2], SCREEN_WIDTH * 0.7, 0.0f,
		400, 400,
		0.0f, 0.0f, 0.8f, 1.0f);

	//�v���C���[
	DrawSpriteLeftTop(g_TextureNo[3], g_Player.pos.x, g_Player.pos.y,
		186, 223,
		g_Player.u, g_Player.v, PLAYER_WIDTH, PLAYER_HEIGHT);


}


