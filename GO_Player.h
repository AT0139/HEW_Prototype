#pragma once
#include "GameObject.h"

struct VERTEX_T {
	D3DXVECTOR2		pos;	//�ʒu�x�N�g��
	D3DXVECTOR2		vel;	//���x�x�N�g��
	D3DXCOLOR		color;	//���_�J���[
};

class GO_Player :public GameObject
{
public:
	// GameObject ����Čp������܂���
	virtual void Initialize(void) override;

	virtual void Finalize(void) override;

	virtual void Update(void) override;

	virtual void Draw(void) override;

private:
	//�e�N�X�`���̃C���f�b�N�X
	int Player_Texture;

	//�e�N�X�`���̖��O
	char PLAYER_TEX_NAME[128] = "data/TEXTURE/player.png";

	//�p�����[�^��� -> VertexInf.h
	VERTEX_T Player_Vertex;
};

