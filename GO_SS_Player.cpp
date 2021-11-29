#include "GO_SS_Player.h"
#include "GO_SS_Wall.h"
#include "fade.h"
#include <cmath>
/*---------------------------------------------
*				����������
---------------------------------------------*/
void GO_SS_Player::Initialize(void)
{
	Player_Texture = LoadTexture(TEX_NAME);

	Player_Vertex.pos = D3DXVECTOR2(SCREEN_WIDTH / 4, 100.0f);
	Player_Vertex.size = D3DXVECTOR2(200.0f, 200.0f);
	Player_Vertex.delay = 1.0f;

	RunFlameSkip = 0;
	Run_Tex_Pattern = 0;

	m_Gravity = DEFAULT_GRAVITY;
	IsTurn = false;
	IsJump = false;
	IsColl = false;
	OkJump = true;
}
/*---------------------------------------------
*				�I������
---------------------------------------------*/
void GO_SS_Player::Finalize(void)
{

}
/*---------------------------------------------
*				�X�V����
---------------------------------------------*/
void GO_SS_Player::Update(void)
{
	//�v���C���[����ʉ��ɗ�������Gameover��
	SceneToGameOver();

	if (IsColl) {
		OkJump = true;
	}

	//�L�[�{�[�h�E�}�E�X����̓��͂�������ăv���C���[�̓�������������
	InputPlayerMove();

	//�v���C���[�̃W�����v�̓���
	PlayerJumpMove();

	//�v���C���[�̏d�͏���
	PlayerGravity();

	//RunFlameSkip++;
	if (RunFlameSkip >= RUN_FLAMESKIPNUM)
	{
		Run_Tex_Pattern++;
		RunFlameSkip = 0;
	}
	if (Run_Tex_Pattern >= 5)
		Run_Tex_Pattern = 1;
}
/*---------------------------------------------
*				�`�揈��
---------------------------------------------*/
void GO_SS_Player::Draw(void)
{
	u = (Run_Tex_Pattern % TEX_WIDTH_DIV) * U_ADDITION;
	v = (Run_Tex_Pattern / TEX_HEIGHT_DIV) * V_ADDITION;
	
	DrawSprite(Player_Texture, Player_Vertex.pos.x, Player_Vertex.pos.y,
		Player_Vertex.size.x, Player_Vertex.size.y,
		(IsTurn ? u : u), v, (IsTurn ? U_ADDITION : -U_ADDITION), V_ADDITION);
}



//	�N���b�N�����Ƃ��̃v���C���[�̋���
//	�J�[�\�����v���C���[���E�̂Ƃ��̏���
void GO_SS_Player::WavePosPlus(FLOAT angle)
{
	FLOAT posx = Player_Vertex.pos.x;
	FLOAT posy = Player_Vertex.pos.y;
	FLOAT centerx = (SCREEN_WIDTH / 4.0f - posx);

	Player_Vertex.pos.y -= (posy / 5.0f) * sinf(angle);
	Player_Vertex.pos.x += (centerx / 10.0f) * cosf(angle);
}

//	�N���b�N�����Ƃ��̃v���C���[�̋���
//	�J�[�\�����v���C���[��荶�̂Ƃ��̏���
void GO_SS_Player::WavePosMinus(FLOAT angle)
{
	FLOAT posx = Player_Vertex.pos.x;
	FLOAT posy =  Player_Vertex.pos.y;
	FLOAT centerx = (SCREEN_WIDTH / 4.0f - posx);

	Player_Vertex.pos.y -= (posy / 5.0f) * sinf(angle);
	Player_Vertex.pos.x -= (centerx / 10.0f) * cosf(angle);
}

//�v���C���[����ʉ��ɗ�������Gameover��
void GO_SS_Player::SceneToGameOver(void)
{
	//�v���C���[����ʂ����ɂ���A�t�F�[�h�������ł͂Ȃ��Ƃ�
	if (GetPos().y >= SCREEN_HEIGHT && GetFadeState() == FADE_NONE) {

		//GAMEOVER�ֈڍs����
		SceneTransition(SCENE_GAMEOVER);
	}
}

//�L�[�{�[�h�E�}�E�X����̓��͂�������ăv���C���[�̓�������������
void GO_SS_Player::InputPlayerMove(void)
{

	if (GetKeyboardTrigger(DIK_SPACE) && OkJump) {
		IsJump = true;
		OkJump = false;
	}
}

//�v���C���[�̏d�͏���
void GO_SS_Player::PlayerGravity(void)
{
	if (IsColl && m_Gravity >= 5.0f)return;

	m_Gravity += GRAVITY_ACCELERATION;
	Player_Vertex.pos.y += m_Gravity;
}

void GO_SS_Player::PlayerJumpMove(void)
{
	if (!IsJump)return;
	m_Gravity = DEFAULT_GRAVITY * m_Jump;
	IsJump = false;
}

