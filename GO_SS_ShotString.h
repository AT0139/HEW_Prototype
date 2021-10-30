#pragma once
#include "GameObject.h"

class GO_SS_Player;

class GO_SS_ShotString :public GameObject
{
public:
	// GameObject����Čp������܂���
	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;
	virtual int GetGameScene(void) override { return GAME_SCENE; }

	//�Q�b�^�[
	FLOAT GetAngle(void) { return String_Vertex.angle; }

	//�Z�b�^�[
	void SetPos(D3DXVECTOR2 pos) { String_Vertex.pos = pos; }

	//public �ϐ�
	bool IsClick = false;

private:
	//�Q�[���V�[���p
	const int GAME_SCENE = GAMESCENE_GAME_TEST;

	//�e�N�X�`���p
	char TEX_NAME[64] = "data/TEXTURE/String.png";
	int String_Texture;

	//���_�p�����[�^
	VERTEX_SHOOTSTIRNG String_Vertex;

	//�J�[�\���|�W�V����
	D3DXVECTOR2 CursorPos;
	
	//�J�[�\���ƃv���C���[�̋����擾
	FLOAT GetDistance(D3DXVECTOR2 p1, D3DXVECTOR2 p2);
};