#include "GO_SS_Collision.h"
#include "GO_SS_BackGround.h"
#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"
#include "GO_SS_Target.h"
#include "GO_SS_Wall.h"
#include "GO_SS_Goal.h"
#include "GO_SS_Fan.h"
#include "game.h"
#include "main.h"
#include "input.h"
#include "fade.h"
#include "GO_SS_KitchenTimer.h"
#include "GO_SS_Timer.h"


void GO_SS_Collision::CollisionUpdate(void)
{
	playerPos = m_pPlayer->GetPos();
	playerSize = m_pPlayer->GetSize();

	m_FanInfo = m_pFan->GetFan();

	m_pPlayer->IsCollSide = CJ_PWSide();

	Goal_Vertex = m_pGoal->GetGoal();

	//KitchenTimer_Vertex = m_pKitchenTimer->GetKitchenTimer();

	//�v���C���[�ƕǂ̏Փˏ���
	if (collTemp = CJ_PlayerWall() >= 0)
		m_pPlayer->IsColl = true;
	else m_pPlayer->IsColl = false;

	//�v���C���[�Ɖғ������C��Փ˔���
		//************************************
		//���̊֐��Ȃ��ɒǉ�
		//************************************
	CJ_PlayerFan();

	CJ_GoalPlayer();

	PlayerYCorrection(collTemp);
	CJ_KitchenTimerPlayer();

	//DebugOut();

	DebugOut();
}

// ----------------------------------------------------------------
//						�v���C���[�ƕ�
// ----------------------------------------------------------------
//	�ߒl�F	�������Ă�����A���̕ǂ̃C���f�b�N�X���B
//			�������Ă��Ȃ�������A-1��Ԃ�
// ----------------------------------------------------------------
int GO_SS_Collision::CJ_PlayerWall(void)
{
	for (int i = 0; i < m_pWall->GetWallNumMax(); i++) {
		VERTEX_WALL vwall = m_pWall->GetvWall(i);
		if (!vwall.use)continue;
		if (BBCollision_LeftTop2(m_pPlayer->GetPos(), m_pPlayer->GetSize(), vwall.pos, vwall.size)) {
			return i;
		}
	}
	return -1;
}

//�v���C���[�̉��ƕ�
//�߂�l -1:�������ĂȂ��@1:�� 2:�E
int GO_SS_Collision::CJ_PWSide(void)
{
	for (int i = 0; i < m_pWall->GetWallNumMax(); i++) 
	{
		VERTEX_WALL vwall = m_pWall->GetvWall(i);
		if (!vwall.use)continue;
		//��
		if (BBCollision_LeftTop2(D3DXVECTOR2(playerPos.x, playerPos.y),
			D3DXVECTOR2(playerSize.x, playerSize.y*0.8f), vwall.pos, vwall.size))
		{
			return 1;
		}
		//�E
		if (BBCollision_LeftTop2(D3DXVECTOR2(playerPos.x + playerSize.x * 0.5f, playerPos.y),
			D3DXVECTOR2(playerSize.x * 0.001f, playerSize.y*0.8f), vwall.pos, vwall.size))
		{
			return 2;
		}
	}
	return -1;
}

void GO_SS_Collision::CJ_PlayerFan(void)
{
	for (int i = 0; i < m_pFan->FANS_MAX; i++)
	{
		if (m_FanInfo[i].use) {
			if (m_FanInfo[i].isWork)
			{
				//�����
				if (!m_FanInfo[i].isLeft)
				{
					if (BBCollision(playerPos, playerSize,
						D3DXVECTOR2(m_FanInfo[i].fanB_Pos.x + WALL_WIDTH / 2,
							m_FanInfo[i].fanB_Pos.y - WALL_HEIGHT + WALL_HEIGHT / 2), m_FanInfo[i].size))
					{
						/*����������蔻�菈��*/
						m_pFan->SetCollisionNum(FAN_COLL_UP);
					}
					else
					{
						m_pFan->SetCollisionNum(FAN_COLL_NONE);
					}
				}
				//���ނ�
				else
				{
					if (BBCollision(playerPos, playerSize,
						D3DXVECTOR2(m_FanInfo[i].fanB_Pos.x - WALL_WIDTH + WALL_WIDTH / 2,
							m_FanInfo[i].fanB_Pos.y + WALL_HEIGHT / 2), m_FanInfo[i].size))
					{
						/*�����������蔻��̏���*/
						m_pFan->SetCollisionNum(FAN_COLL_LEFT);

					}
					else {
						m_pFan->SetCollisionNum(FAN_COLL_NONE);
					}

				}
			}
			else {
				m_pFan->SetCollisionNum(FAN_COLL_NONE);
			}
		}
	}
}

bool GO_SS_Collision::BBCollision(D3DXVECTOR2 pos1, D3DXVECTOR2 size1, D3DXVECTOR2 pos2, D3DXVECTOR2 size2)
{
	D3DXVECTOR2 min1, max1;
	D3DXVECTOR2 min2, max2;

	min1.x = pos1.x - size1.x / 2;
	min1.y = pos1.y - size1.y / 2;
	max1.x = pos1.x + size1.x / 2;
	max1.y = pos1.y + size1.y / 2;

	min2.x = pos2.x - size2.x / 2;
	min2.y = pos2.y - size2.y / 2;
	max2.x = pos2.x + size2.x / 2;
	max2.y = pos2.y + size2.y / 2;

	//X���̔���
	if (min1.x < max2.x && max1.x > min2.x)
	{
		//Y���̔���
		if (min1.y < max2.y && max1.y > min2.y)
		{
			//�S�Ă̏�����TRUE�Ȃ�q�b�g����
			return true;
		}
	}
	return false;
}

bool GO_SS_Collision::BBCollision_LeftTop2(D3DXVECTOR2 pos1, D3DXVECTOR2 size1, D3DXVECTOR2 pos2, D3DXVECTOR2 size2)
{
	D3DXVECTOR2 min1, max1;
	D3DXVECTOR2 min2, max2;

	min1.x = pos1.x - size1.x / 2;
	min1.y = pos1.y - size1.y / 2;
	max1.x = pos1.x + size1.x / 2;
	max1.y = pos1.y + size1.y / 2;

	min2.x = pos2.x;
	min2.y = pos2.y;
	max2.x = pos2.x + size2.x;
	max2.y = pos2.y + size2.y;

	//X���̔���
	if (min1.x < max2.x && max1.x > min2.x)
	{
		//Y���̔���
		if (min1.y < max2.y && max1.y > min2.y)
		{
			//�S�Ă̏�����TRUE�Ȃ�q�b�g����
			return true;
		}
	}
	return false;
}

void GO_SS_Collision::DebugOut(void)
{
#ifdef _DEBUG	// �f�o�b�O�ł̎�����Angle��\������
	wsprintf(GetDebugStr(), WINDOW_CAPTION);
	//wsprintf(&GetDebugStr()[strlen(GetDebugStr())], " test:%d",);

	SetWindowText(GethWnd()[0], GetDebugStr());
#endif
}

void GO_SS_Collision::CJ_GoalPlayer(void)
{
	if (BBCollision_LeftTop2(m_pPlayer->GetPos(), m_pPlayer->GetSize(), Goal_Vertex.pos, Goal_Vertex.size))
	{
		SceneTransition(SCENE_RESULT);
	}
}

void GO_SS_Collision::PlayerYCorrection(int index)
{
	for (int i = 0; i < m_pWall->GetWallNumMax(); i++) {

		VERTEX_WALL vwall = m_pWall->GetvWall(i);
		if (!vwall.use)continue;

		if (BBCollision_LeftTop2(D3DXVECTOR2(playerPos.x, playerPos.y + playerSize.y * 0.5f - 15.0f),
			D3DXVECTOR2(playerSize.x * 0.8f, 8), vwall.pos, vwall.size))
		{
			if (playerPos.y + playerSize.y * 0.5f >= vwall.pos.y)
				m_pPlayer->SetPosY(vwall.pos.y - playerSize.y * 0.5f);
		}
	}
}

void GO_SS_Collision::CJ_KitchenTimerPlayer(void)
{
	if (BBCollision_LeftTop2(m_pPlayer->GetPos(), m_pPlayer->GetSize(), m_pKitchenTimer->GetKitchenTimer().pos, m_pKitchenTimer->GetKitchenTimer().size))
	{
		m_pKitchenTimer->SetUse(false);
	}
}