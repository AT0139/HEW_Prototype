#pragma once
//---------------------------
//	[GameFramework.h]
//	Yuta Yanagisawa 
//---------------------------
#include "GameScene.h"

//------�O���錾
class GameObject;
class Enemy;
class GO_Player;
class Collision;
class GO_Vortex;
class GO_VortexRotation;

//�N���X�@�Q�[���t���[�����[�N
class GameFramework {
public:
	GameFramework();
	~GameFramework();

	void Initialize(void);
	void Finalize(void);
	void Update(void);
	void Draw(void);

	//m_pGameObjects[]��GameObject���l�ߍ���
	void Register(GameObject* pGameObject);

private:
	static const int GAME_OBJECT_MAX = 100;

	//GameObject�̃|�C���^
	GameObject* m_pGameObjects[GAME_OBJECT_MAX];

	GO_Player* mp_player;
	GO_Vortex* mp_vortex;
	GO_VortexRotation* mp_VoRot;

	//GameScene
	GameScene m_GameScene;

	//nullptr����[��new�œ��I�����[��Register�o�^���܂Ƃ߂Ă��ꏊ�B
	//�R���X�g���N�^�Ŏg�p
	void Create();

	//���̃Q�[���t���[�����[�N�Ɋ��������ꍇ�g�p
	void SetGameObject();
};
