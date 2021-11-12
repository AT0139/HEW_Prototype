#include "GO_SS_ShotString.h"
#include "GO_SS_Player.h"
#include "GO_SS_Target.h"

void GO_SS_ShotString::Initialize(void)
{
	String_Texture = LoadTexture(TEX_NAME);

	String_Vertex.size.x = 0.0f;
	String_Vertex.size.y = 5.0f;
	String_Vertex.pos = D3DXVECTOR2(0.0f, 0.0f);
	String_Vertex.angle = 0.0f;

}

void GO_SS_ShotString::Finalize(void)
{

}

void GO_SS_ShotString::Update(void)
{
	DebugOut();

	//�|�W�V�������v���C���[�̃|�W�V�����ɂ���
	String_Vertex.pos = m_pPlayer->GetPos();

	//������Ă����
	if (IsMouseLeftPressed())
	{
		//�J�[�\���擾
		CursorPos.x = GetMousePosX();
		CursorPos.y = GetMousePosY();


		//�v���C���[�ƃJ�[�\���̊p�x�擾
		String_Vertex.angle = atan2f(String_Vertex.pos.y - CursorPos.y,
			String_Vertex.pos.x - CursorPos.x);

	}

	//�^�[�Q�b�g�ł͂Ȃ��ꏊ���N���b�N
	NoTargetClick();

	//�^�[�Q�b�g���N���b�N
	TargetClick();




	//���̒������J�[�\���Ƃ̋����܂łɐ���
	if (GetDistance(String_Vertex.pos, CursorPos) * 2.0f <= String_Vertex.size.x) {
		String_Vertex.size.x = GetDistance(String_Vertex.pos, CursorPos) * 2.0f;
	}
	else {
		//���̒����L�΂�
		String_Vertex.size.x += 20.0f;
	}

}

void GO_SS_ShotString::Draw(void)
{
	if (!IsClick)return;
	DrawSpriteColorRotate(String_Texture, String_Vertex.pos.x, String_Vertex.pos.y,
		String_Vertex.size.x, String_Vertex.size.y,
		0.0f, 0.0f, 0.9f, 0.9f, D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), String_Vertex.angle);
}



FLOAT GO_SS_ShotString::GetDistance(D3DXVECTOR2 p1, D3DXVECTOR2 p2)
{
	return sqrtf(powf(p1.x - p2.x, 2) + powf(p1.y - p2.y, 2));
}

void GO_SS_ShotString::DebugOut(void)
{
#ifdef _DEBUG	// �f�o�b�O�ł̎�����Angle��\������
	wsprintf(GetDebugStr(), WINDOW_CAPTION);
	wsprintf(&GetDebugStr()[strlen(GetDebugStr())], " angle:%d",
		(int)(String_Vertex.angle * (FLOAT)180.0f / (FLOAT)PI));

	SetWindowText(GethWnd()[0], GetDebugStr());
#endif
}

//�^�[�Q�b�g�ł͂Ȃ��ꏊ���N���b�N
void GO_SS_ShotString::NoTargetClick(void)
{
	//�����ꂽ��
	if (IsMouseLeftTriggered()) {
		String_Vertex.size.x = 0.0f;
	}

	//�����Ă�����
	if (IsMouseLeftPressed()) {

		IsClick = true;

	}
	//�����ꂽ��
	else {
		IsClick = false;
	}
}

//�^�[�Q�b�g���N���b�N����
void GO_SS_ShotString::TargetClick(void)
{
	IsInsideTarget = IsMouseInsideTarget();

	//���T�C�Y���Z�b�g
	if (IsMouseLeftTriggered() && IsInsideTarget) {
		String_Vertex.size.x = 0.0f;
		m_jumpCounter = 0;
		IsClickTarget = true;
	}

	if (IsMouseLeftPressed() && IsClickTarget){
		if (m_jumpCounter >= 120) {
			IsClickTarget = false;
			m_pPlayer->SetGravityDefault();
		}
		else {
			m_jumpCounter++;
			IsClickTarget = true;
		}
	}
	else {
		IsClickTarget = false;
	}
}


bool GO_SS_ShotString::IsMouseInsideTarget(void)
{	
	for (int i = 0; i < m_pTarget->GetTargetNumMax(); i++) {
		VERTEX_TARGET vt = m_pTarget->GetTarget()[i];
		if (!vt.use)continue;
		/*if (CursorPos.x > vt.pos.x - vt.size.x / 4 &&
			CursorPos.x < vt.pos.x + vt.size.x / 4 &&
			CursorPos.y > vt.pos.y - vt.size.y / 2 &&
			CursorPos.y < vt.pos.y + vt.size.y / 2) {
			return true;
		}*/

		FLOAT x = powf(CursorPos.x - vt.pos.x, 2.0f);
		FLOAT y = powf(CursorPos.y - vt.pos.y, 2.0f);
		FLOAT dist = sqrtf(x + y);

		if (dist <= vt.size.x - 100.0f) {
			return true;
		}
	}
	
	return false;
}
