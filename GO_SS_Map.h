#pragma once
#include "GameObject.h"
#include <iostream>
#include <vector>

class GO_SS_FileLoad;
class GO_SS_Wall;

class GO_SS_Map :public GameObject
{
public:
	// GameObject ����Čp������܂���
	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual void Update(void) override;
	virtual void Draw(void) override;

	void SetFileLoad(GO_SS_FileLoad* p) { m_pFileLoad = p; }
	void SetWall(GO_SS_Wall* p) { m_pWall = p; }

	virtual int GetGameScene(void) override { return GAME_SCENE; }

	void ResetOnce(void) { once = true; }

private:
	int GAME_SCENE = GAMESCENE_GAME_TEST;	
	int MapData[WALL_NUM_Y][WALL_NUM_X];//�܂��ՂŁ[��

	GO_SS_FileLoad* m_pFileLoad;	//FileLoad�|�C���^
	GO_SS_Wall* m_pWall;			//Wall�|�C���^

	//�萔
	static const int WALL_NUM = 1;	//�ǂ̔ԍ�

	bool once;

};