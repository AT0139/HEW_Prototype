#pragma once
#include "GameObject.h"
class GO_SS_NattoRotate :
    public GameObject
{
private:
    static const int NATTO_MAX = 50;
    static const int FIRST_NATTO = 10;

    const FLOAT ANGLE_MIN = 0.0f;
    const FLOAT ANGLE_MAX = 0.1f;
public:
    // GameObject を介して継承されました
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override;

    void SetPos(D3DXVECTOR2 pos) { m_PlayerPos = pos; }
    void SetNatto(void);

private:
    char m_TexName[64] = "data/TEXTURE/納豆.png";
    int  m_TexIndex;

    VERTEX_NATTO m_Vertex[NATTO_MAX];

    D3DXVECTOR2 m_PlayerPos = D3DXVECTOR2(0.0f,0.0f);

//  メンバ関数
    void Rotation(int index);

    FLOAT frand();
    FLOAT frand_r();
};

