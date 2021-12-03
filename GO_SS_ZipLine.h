#pragma once

#include "GameObject.h"

//zipline�\����
struct VERTEX_ZIPLINE :public VERTEX_NOMAL
{
	bool use;
};

class GO_SS_ZipLine :public GameObject
{
public:
	// GameObject ����Čp������܂���
	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;
	virtual int GetGameScene(void) { return GAME_SCENE; }

	void SetZipLine(D3DXVECTOR2 pos);
	void AddX(FLOAT x);

private:
	const int GAME_SCENE = GAMESCENE_GAME_TEST;

	int poleTex;

	static const int ZIPLINE_MAX = 5;		//�W�b�v���C����΂̍ő吔
	const int POLE_MAX = ZIPLINE_MAX * 2;	//���̍ő吔 **�ύX���Ȃ�**
	VERTEX_ZIPLINE ziplineInfo[ZIPLINE_MAX];

	const int POLE_WALL_HEIGHT = 3;			//���̏c�}�X��
};