#pragma once
#include "GameObject.h"
class GO_Fall :
    public GameObject
{
public:


    // GameObject を介して継承されました
    virtual void Initialize(void) override;

    virtual void Finalize(void) override;

    virtual void Update(void) override;

    virtual void Draw(void) override;

    virtual int GetGameScene(void) { return GAMESCENE_FALL; }

private:

};

