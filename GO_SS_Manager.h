#pragma once
#include "GameObject.h"
class GO_ShootString;
class GO_SS_Player;
class GO_SS_Wall;
class GO_SS_BackGround;

class GO_SS_Manager :
    public GameObject
{
public:
    GO_SS_Manager();
    ~GO_SS_Manager();

    // GameObject ����Čp������܂���
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override { return GAME_SCENE; }

    void Register(GameObject* pSSObject);

private:
    //�Q�[���V�[��
    const int GAME_SCENE = GAMESCENE_GAME_TEST;

    static const int SS_GAMEOBJECT_MAX = 50;

    GameObject* m_ssGameObject[SS_GAMEOBJECT_MAX];
    GO_SS_Player* mp_ssPlayer;
    GO_SS_Wall* mp_ssWall;
    GO_SS_BackGround* mp_ssBackGround;

    //nullptr����[��new�œ��I�����[��Register�o�^���܂Ƃ߂Ă��ꏊ�B
    //�R���X�g���N�^�Ŏg�p
    void Create();

    //���̃Q�[���t���[�����[�N�Ɋ��������ꍇ�g�p
    void SetGameObject();
};

