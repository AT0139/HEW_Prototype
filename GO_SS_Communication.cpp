
#include "GO_SS_Communication.h"
#include "GO_SS_BackGround.h"
#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"


void GO_SS_Communication::Update(void)
{
	SetShotStringPlayer(); 
	JumpMoveBackGround();
}

void GO_SS_Communication::SetShotStringPlayer()
{
	m_pShotString->SetPos(m_pPlayer->GetPos());
}

//	�A���O����cos�ƕ��A�w�i�𓮂���
//	�Ȃ�t���[���H		�[��120���炢
//	�ǂ̃^�C�~���O�H	�[���W�����v(space key )�������ꂽ��
//	�K�v�Ȃ��̂́H		�[���W�����v�����Ƃ��̃t���O�A�t���[���𑪂�ϐ�(int)
//							angle
//	�ǂ��������H		�[���W�����v�t���O���オ���Đ��t���[���ԁAAddU(cosf(angle));
void GO_SS_Communication::JumpMoveBackGround()
{
	if (!m_pPlayer->IsJump)return;

	if (JumpCounter >= JumpCountMax) {
		m_pPlayer->IsJump = false;
		JumpCounter = 0;
	}
	else {
		m_pBackGround->AddU(cosf(m_pShotString->GetAngle()) / 100.0f);
		JumpCounter++;
	}

	if (JumpCounter <= 1) {
		JumpCountMax = (int)(cosf(cosf(m_pShotString->GetAngle())) * 60.0f);
	}

}

