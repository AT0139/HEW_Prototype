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
	m_RunIndex = LoadTexture(RUN_NAME);

	Player_Vertex.pos = D3DXVECTOR2(SCREEN_WIDTH / 4, 100.0f);
	Player_Vertex.size = D3DXVECTOR2(200.0f, 200.0f);
	Player_Vertex.delay = 1.0f;
	Player_Vertex.frame = 0;
	Player_Vertex.u = 0.0f;
	Player_Vertex.v = 0.0f;

	Player_Vertex.width = PLAYER_WIDTH;
	Player_Vertex.height = PLAYER_HEIGHT;

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

	//�v���C���[�̃A�j���[�V�����t���[���X�V����
	if (Player_Vertex.frame >= PLAYER_X_NUM * PLAYER_Y_NUM) {
		Player_Vertex.frame = 0;
	}
	else {
		if (m_delay >= 30) {
			Player_Vertex.frame++;
			m_delay = 0;
		}
		else {
			m_delay++;
		}
		
		/*if (GetKeyboardTrigger(DIK_D)) {
			Player_Vertex.frame++;
		}*/
	}

	PlayerState();

	DebugOut();
}
/*---------------------------------------------
*				�`�揈��
---------------------------------------------*/
void GO_SS_Player::Draw(void)
{
	DrawSprite(m_RunIndex, Player_Vertex.pos.x, Player_Vertex.pos.y,
		Player_Vertex.size.x, Player_Vertex.size.y,
		Player_Vertex.u,
		Player_Vertex.v,
		Player_Vertex.width, Player_Vertex.height);
	//DrawSprite(m_RunIndex, Player_Vertex.pos.x, Player_Vertex.pos.y,
	//	Player_Vertex.size.x, Player_Vertex.size.y,
	//	(Player_Vertex.frame % PLAYER_X_NUM )* PLAYER_WIDTH,
	//	(Player_Vertex.frame / PLAYER_Y_NUM )* PLAYER_HEIGHT,
	//	PLAYER_WIDTH, PLAYER_HEIGHT);
}

void GO_SS_Player::PlayerState(void)
{
	//����������Ă��Ȃ���
	if(!GetKeyboardPress(DIK_D) &&
		!GetKeyboardPress(DIK_A)){
		//Player_Vertex.frame = 0;
	}

	//D�L�[�������ꂽ��
	if (GetKeyboardPress(DIK_D)) {
		Player_Vertex.width = PLAYER_WIDTH;
		Player_Vertex.u = (Player_Vertex.frame % PLAYER_X_NUM+1) * PLAYER_WIDTH;
		Player_Vertex.v = (Player_Vertex.frame / PLAYER_Y_NUM) * PLAYER_HEIGHT;
			
	}

	//A�L�[�������ꂽ��
	if (GetKeyboardPress(DIK_A)) {
		Player_Vertex.u = -1.0f + Player_Vertex.frame % PLAYER_X_NUM * PLAYER_WIDTH * -1.0f;
		Player_Vertex.v = -1.0f + Player_Vertex.frame / PLAYER_Y_NUM * PLAYER_HEIGHT * -1.0f;
		Player_Vertex.width = PLAYER_WIDTH * -1.0f;
	}


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

void GO_SS_Player::DebugOut(void)
{
#ifdef _DEBUG	// �f�o�b�O�ł̎�����Angle��\������
	wsprintf(GetDebugStr(), WINDOW_CAPTION);
	wsprintf(&GetDebugStr()[strlen(GetDebugStr())],"%d",Player_Vertex.frame);

	SetWindowText(GethWnd()[0], GetDebugStr());
#endif
}

