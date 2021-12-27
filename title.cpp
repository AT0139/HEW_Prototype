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
//�t�b�N�̈ʒu
#define Target_x SCREEN_WIDTH * 0.7
#define Target_y 250.0f

//�r���̔{������
#define Bxs 0.05f
#define Bys 0.20f
#define Bxg 0.49f
#define Byg 0.52f

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
static int g_TextureNo[5] = { 0,0,0,0,0 };	// �e�N�X�`�����
static int g_AdvertisementNo[5] = { 0,0,0,0,0 };	// �e�N�X�`�����

static int g_String_Texture;	// �e�N�X�`�����

static VERTEX_TITLE_PLAYER g_Player;

static float g_natto = 1200.0f;

static int g_i = 0;
static int g_count = 0;

static const FLOAT GRAVITY_ACCELERATION = 0.3f;

static FLOAT m_Jump = -10.75f;
static FLOAT g_gravity = 1.0f;
static int g_Action = 0;

static VERTEX_SHOOTSTIRNG	g_String_Vertex;



float biruk[4] = { 0.0f,0.0f,1.0f,1.0f };
float g_U = 0.0f;

D3DXVECTOR2 Target_pos = D3DXVECTOR2(Target_x, Target_y);



//=============================================================================
// ����������
//=============================================================================
HRESULT InitTitle(void)
{
	TO_Init();

	//�e�N�X�`������
	g_TextureNo[0] = LoadTexture("data/TEXTURE/haikei2.png");
	g_TextureNo[1] = LoadTexture("data/TEXTURE/mati3.png");//�r���Q
	g_TextureNo[2] = LoadTexture("data/TEXTURE/target.png");//�t�b�N
	g_TextureNo[3] = LoadTexture("data/TEXTURE/jump2.png");//�v���C���[
	g_TextureNo[4] = LoadTexture("data/TEXTURE/mati3-1.png");//���C�g



	g_Player.angle = 0.0f;
	g_Player.frame = 4;
	g_Player.pos = D3DXVECTOR2(-100.0f, SCREEN_HEIGHT / 5);
	g_Player.size = D3DXVECTOR2(0.0f, 0.0F);
	g_Player.u = 0.0f;
	g_Player.v = 0.0f;
	g_Player.use = true;

	g_gravity *= m_Jump;

	g_String_Texture = LoadTexture("data/TEXTURE/String1.png");
	g_String_Vertex.angle = 0.0f;
	g_String_Vertex.pos = D3DXVECTOR2(0.0f, 0.0f);
	g_String_Vertex.size = D3DXVECTOR2(0.0f, 5.0f);


	g_natto = 1200.0f;
	g_i = 0;
	g_count = 0;

	m_Jump = -10.75f;
	g_gravity = 1.0f;
	g_Action = 0;

	biruk[0] = 0.0f;
	biruk[1] = 0.0f;
	biruk[2] = 1.0f;
	biruk[3] = 1.0f;

	g_U = 0.0f;

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
	//�w�i�̈ړ�
	g_U += 0.0000001f;

	//�A�j���[�V�����̃t���[������
	if (g_Player.use) {
		if (g_Player.frame >= PLAYER_X_NUM * PLAYER_Y_NUM)
		{
			g_Player.frame = 0;
		}
		else {
			if (g_i == 10) {
				g_Player.frame++;
				g_i = 0;
			}
			else
				g_i++;
		}
		if (g_Player.use) {
			g_Player.u = g_Player.frame % PLAYER_X_NUM * PLAYER_WIDTH;
			g_Player.v = g_Player.frame / PLAYER_Y_NUM * PLAYER_HEIGHT;
		}

	}

	//�A�N�V�����̍Đ�
	Action(g_Action);

	//�V�[���J��
	if (GetKeyboardTrigger(DIK_RETURN) ||
		IsMouseLeftPressed() &&
		GetFadeState() == FADE_NONE)
		g_Action = 9;

	Action(g_Action);


}

//=============================================================================
// �`�揈��
//=============================================================================
void DrawTitle(void)
{
	TO_Draw();

	// �P���̃|���S���̒��_�ƃe�N�X�`�����W��ݒ�

	DrawSpriteLeftTop(g_TextureNo[0], 0, 0,
		SCREEN_WIDTH * 36, SCREEN_HEIGHT,
		g_U, g_U, 1.0f + g_U, 1.0f + g_U);


	//�r���Q
	DrawSprite(g_TextureNo[1], SCEREN_WIDTH_HURF, SCEREN_HEIGHT_HURF,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		biruk[0], biruk[1], biruk[2], biruk[3]);


	//���C�g
	DrawSprite(g_TextureNo[4], SCEREN_WIDTH_HURF, SCEREN_HEIGHT_HURF,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		0.0f, 0.0f, 1.0f, 1.0f);


	//�t�b�N	
	DrawSprite(g_TextureNo[2], Target_x, Target_y,
		400, 400,
		0.0f, 0.0f, 0.8f, 1.0f);

	if (g_Player.use)
	{
		//�v���C���[
		DrawSprite(g_TextureNo[3], g_Player.pos.x, g_Player.pos.y,
			186, 223,
			g_Player.u, g_Player.v, PLAYER_WIDTH, PLAYER_HEIGHT);

		//�[���̎�
		DrawSpriteColorRotate(g_String_Texture, g_String_Vertex.pos.x, g_String_Vertex.pos.y,
			g_String_Vertex.size.x, g_String_Vertex.size.y,
			0.0f, 0.0f, 0.9f, 0.9f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), g_String_Vertex.angle);


	}


}


//�e�A�N�V���������蓖�Ă�
void Action(int ActionScene)//�����F�A�N�V�����i���o�[
{
	switch (ActionScene)
	{
	case 0:	//�W�����v���Ē��n����
		//�v���C���[��x�����̓���
		if (g_Player.pos.x >= SCREEN_WIDTH / 2.0f + 10.0f) {
			g_Player.pos.x = SCREEN_WIDTH / 2.0f + 10.0f;
			g_Action = 2;
		}
		else {
			g_Player.pos.x += 11.0f;
		}

		//�v���C���[y�����̓���
		if (g_Player.pos.y >= SCREEN_HEIGHT / 2.0f + 200.0f) {
			g_Player.pos.y = SCREEN_HEIGHT / 2.0f + 200.0f;
		}
		else {
			g_gravity += GRAVITY_ACCELERATION * 1.5;
			g_Player.pos.y += g_gravity;
		}
		break;


	case 1:		//(����L�΂���������)��ї���
		g_Player.pos.x += 11.0f;
		g_Player.pos.y -= 13.0f;
		if (g_Player.pos.y <= Target_y)
			g_String_Vertex.size.x = 0.0f;


	case 2:	//�^�[�Q�b�g�Ɏ���L�΂�
		g_count++;
		//�|�W�V�������v���C���[�̃|�W�V�����ɂ���
		g_String_Vertex.pos = g_Player.pos;


		//�v���C���[�ƃJ�[�\���̊p�x�擾
		g_String_Vertex.angle = atan2f(g_String_Vertex.pos.y - (Target_y + 100.0f),
			g_String_Vertex.pos.x - Target_x);


		//g_String_Vertex.size.x += 20.0f;

		if (g_String_Vertex.size.x >= g_natto) {
			g_String_Vertex.size.x = g_natto;
			g_Action = 1;
		}
		else {
			//���̒����L�΂�
			g_String_Vertex.size.x += 20.0f;
		}
		break;

	case 9://�V�[���ڍs�̃A�N�V����
		if (biruk[0] >= 0.05f)
		{
			g_Action = 0;
			SceneTransition(SCENE_SELECT_STAGE);
		}
		
		else
		{
			biruk[0] += 0.0016f;
			biruk[1] += 0.0066f;
			biruk[2] -= 0.0163f;
			biruk[3] -= 0.0173f;

		}
		break;
	default:
		break;
	}
}



