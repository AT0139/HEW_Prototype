#pragma once

enum GAMESCENE{
    GAMESCENE_VORTEX,
    GAMESCENE_BUNGEE_JUMP,
    GAMESCENE_MAX
};

class GameScene
{
public:

    //�Q�[���I�u�W�F�N�g�̃��W�X�^���Ő�����B
    //GAMESCENE�ɂ����GameObject��Update��Draw�͈̔͂�ݒ肷��
    //[GameScene][�ŏ��Ȃ�0,��Ȃ�1]
    const int GameSceneSelect[GAMESCENE_MAX][2] = {
        {0,3},
        {4,10},
    };

    //������BUNGEE_JUMP�ɕς���GameFramework�̃��W�X�^�Ɍ�납��l�ߍ��߂�4����10�Ԗڂ̃I�u�W�F�N�g������
    //Update��Draw���s���܂��B
    int m_GameScene = GAMESCENE_VORTEX;
};

