#pragma once
#include "GameObject.h"
class GO_SS_Negi :
    public GameObject
{
private:
    static const int NEGI_MAX = 30;
public:
    // GameObject ����Čp������܂���
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) override;

    //	�L�b�`���^�C�}�[�̏��擾
    VERTEX_T* GetNegi(int index) { return &m_Negi[index]; }

    //	�L�b�`���^�C�}�[�̍ő吔�擾
    int GetNegiMax() { return NEGI_MAX; }

    //	Use�t���O�̃Z�b�^�[
    void SetUse(int index, bool flag) { m_Negi[index].use = flag; }

    //	����
    void AddX(FLOAT x);

private:
    
    //  ���_���
    VERTEX_T m_Negi[NEGI_MAX];

    //  �e�N�X�`���p
    int m_TexIndex;
    char* m_pTexName = "data/TEXTURE/negi.png";
};

