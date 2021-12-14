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

	m_Gravity = DEFAULT_GRAVITY;
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

	
}
/*---------------------------------------------
*				�`�揈��
---------------------------------------------*/
void GO_SS_Player::Draw(void)
{
	DrawSprite(Player_Texture, Player_Vertex.pos.x, Player_Vertex.pos.y,
		Player_Vertex.size.x, Player_Vertex.size.y, 1.0f, 1.0f, 1.0f, 1.0f);
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

	m_Gravity += GRAVITY_ACCELERATION * m_TimeDelay;
	Player_Vertex.pos.y += m_Gravity * m_TimeDelay;
}

void GO_SS_Player::PlayerJumpMove(void)
{
	if (!IsJump)return;
	m_Gravity = DEFAULT_GRAVITY * m_Jump;
	IsJump = false;
}

