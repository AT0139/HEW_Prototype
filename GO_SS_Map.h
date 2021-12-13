#pragma once
#include "GameObject.h"
#include <iostream>
#include <vector>

class GO_SS_FileLoad;
class GO_SS_Wall;
class GO_SS_Target;
//class GO_SS_ZipLine;

//�}�b�v�`�b�v�̗񋓌^
typedef enum{
	WALL_NUM = 1,
	TARGET_NUM,
	ZIPLINE_A_NUM,
	ZIPLINE_B_NUM
}MAP_CHIP_NO;

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
	void SetTarget(GO_SS_Target* p) { m_pTarget = p; }
	//void SetZipline(GO_SS_ZipLine* p) { m_pZipLine = p; }

	virtual int GetGameScene(void) override { return GAME_SCENE; }

	void ResetOnce(void) { once = true; }

private:
	//bool SeekZipLineB(int CurrentNum, int CurrentNumY);

	int GAME_SCENE = GAMESCENE_GAME_TEST;
	int MapData[STAGE_WALL_NUM_Y][STAGE_WALL_NUM_X];//�܂��ՂŁ[��
	static const int SEEK_ZIP_MAX = 5;	//B��T���Ƃ��̍ő勗��

	GO_SS_FileLoad* m_pFileLoad;	//FileLoad�|�C���^
	GO_SS_Wall* m_pWall;			//Wall�|�C���^
	GO_SS_Target* m_pTarget;		//target�|�C���^
	//GO_SS_ZipLine* m_pZipLine;		//ZipLine�|�C���^

	MAP_CHIP_NO mapChipNo;

	bool once;

};