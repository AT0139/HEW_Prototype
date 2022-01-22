#pragma once
#include "GameObject.h"
#include "E_Circle.h"

class GO_SS_Karashi :
    public GameObject
{
private:
    static const int KARASHI_MAX = 30;
public:
    // GameObject ����Čp������܂���
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override;

    //	�L�b�`���^�C�}�[�̏��擾
    VERTEX_T* GetKarashi(int index) { return &m_Karashi[index]; }

    //	�L�b�`���^�C�}�[�̍ő吔�擾
    int GetNegiMax() { return KARASHI_MAX; }

    //	Use�t���O�̃Z�b�^�[
    void SetUse(int index, bool flag) { m_Karashi[index].use = flag; }

    //	����
    void AddX(FLOAT x);

    void SetEffect(D3DXVECTOR2 pos) {
        m_Circle.SetEffectNoMouse(pos, 100.0f);
        m_Circle_001.SetEffectNoMouse(pos, 0.0f);
    }

private:

    E_Circle m_Circle;
    E_Circle m_Circle_001;

    //  ���_���
    VERTEX_T m_Karashi[KARASHI_MAX];

    //  �e�N�X�`���p
    int m_TexIndex;
    char* m_pTexName = "data/TEXTURE/tube_karashi.png";
};

