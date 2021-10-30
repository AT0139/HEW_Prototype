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


  

    void AddU(FLOAT add) { BackGround_Vertex.u += add; }
    void SubU(FLOAT sub) { BackGround_Vertex.u -= sub; }

private:
    void AddU(void) { BackGround_Vertex.u += UV_SCROLL; }
    void SubU(void) { BackGround_Vertex.u -= UV_SCROLL; }

    //�e�N�X�`���p�ϐ�
    int BackGround_Texture;
    char TEX_NAME[128] = "data/TEXTURE/mati.png";

    //�Q�[���V�[���p�ϐ�
    const int GAME_SCENE = GAMESCENE_BUNGEE_JUMP;

    //���_���W
    VERTEX_BACKGROUND BackGround_Vertex;

    const FLOAT UV_SCROLL = 0.001f;
};

