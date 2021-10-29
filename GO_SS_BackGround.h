#pragma once
#include "GameObject.h"
class GO_SS_BackGround :
    public GameObject
{
public:


    // GameObject ����Čp������܂���
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override {  return GAME_SCENE;  }

private:
    //�e�N�X�`���p�ϐ�
    int BackGround_Texture;
    char TEX_NAME[128] = "data/TEXTURE/mati.png";

    //�Q�[���V�[���p�ϐ�
    const int GAME_SCENE = GAMESCENE_BUNGEE_JUMP;

    VERTEX_BACKGROUND BackGround_Vertex;

    const FLOAT UC_SCROLL = 0.001f;
};

