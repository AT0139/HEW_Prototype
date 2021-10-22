#pragma once
//---------------------------
//	[GameScene.h]
//	Yuta Yanagisawa 
//---------------------------

//�Q�[�����ł̃V�[���J�ڂ��Ǘ����܂��B


enum GAMESCENE{
    GAMESCENE_VORTEX,       //�[��������V�[��
    GAMESCENE_BUNGEE_JUMP,  //�o���W�[�W�����v�̃V�[��
    GAMESCENE_MAX
};

class GameScene
{
public:

    //�Q�[���I�u�W�F�N�g�̃��W�X�^���Ő�����B
    //GAMESCENE�ɂ����GameObject��Update��Draw�͈̔͂�ݒ肷��
    //[GameScene][�ŏ��Ȃ�0,��Ȃ�1]
    const int GameSceneSelect[GAMESCENE_MAX][2] = {
        {0,3},          //�[��������
        {4,10},         //�o���W�[�W�����v
    };

    //������BUNGEE_JUMP�ɕς���GameFramework�̃��W�X�^�Ɍ�납��l�ߍ��߂�4����10�Ԗڂ̃I�u�W�F�N�g������
    //Update��Draw���s���܂��B
    int m_GameScene = GAMESCENE_VORTEX;
};

/*
*   GameSceneSelect�͂킩��Ȃ������畷���Ă��������B
* 
*   0����3�܂ł͔[��������V�[���p�̃Q�[���I�u�W�F�N�g
*   4����10�܂ł̓o���W�[�W�����v�p�̃Q�[���I�u�W�F�N�g
*   �i���������ς��\��������B�j
* 
*/