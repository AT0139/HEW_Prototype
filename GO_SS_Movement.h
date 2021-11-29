//---------------------------------------------
//	オブジェクト間通信をここでやる	[GO_SS_Movement.h]	
//                          Author: Yanagisawa
//---------------------------------------------
// GameSceneTestのオブジェクト（GO_SS_Managerにあるポインタ）を
// ここで使って、値をいじり合う
//  
// 自分自身が他のオブジェクトの情報をしる必要がない。
//      
// こいつだけがすべてを知っている
//
//---------------------------------------------
#include "GameObject.h"
#include "GO_SS_Collision.h"

class GO_SS_BackGround;
class GO_SS_Player;
class GO_SS_Wall;
class GO_SS_ShotString;
class GO_SS_Target;
class GO_SS_Map;
class GO_SS_Effect_Wind;

enum PlayerMove {
    PLAYERMOVE_NONE,
    PLAYERMOVE_LINEAR,
    PLAYERMOVE_CURVE,
    PLAYERMOVE_PENDULUM,
    PLAYERMOVE_MAX,
};

class GO_SS_Movement :
    public GameObject
{
public:
    // GameObject を介して継承されました
    virtual void Initialize(void) override {};
    virtual void Finalize(void) override {};
    virtual void Update(void) override;
    virtual void Draw(void) override {};
    virtual int GetGameScene(void) override { return GAME_SCENE; }

    //セッター
    void SetBackGround(GO_SS_BackGround* p_BackGround) {
        m_pBackGround = p_BackGround;
        m_ssCollision.SetBackGround(p_BackGround);
    }
    void SetPlayer(GO_SS_Player* p_Player) { 
        m_pPlayer = p_Player; 
        m_ssCollision.SetPlayer(p_Player);
    }
    void SetWall(GO_SS_Wall* pWall) { 
        m_pWall = pWall; 
        m_ssCollision.SetWall(pWall);
    }
    void SetShotString(GO_SS_ShotString* p) { 
        m_pShotString = p; 
        m_ssCollision.SetShotString(p);
    }
    void SetTarget(GO_SS_Target* pTarget) {
        m_pTarget = pTarget; 
        m_ssCollision.SetTarget(pTarget);
    }
    void SetMap(GO_SS_Map* p) { m_pMap = p; }
    void SetEffWind(GO_SS_Effect_Wind* p) { m_pEffectWind = p; }
    
private:
    //ゲームシーン
    const int GAME_SCENE = GAMESCENE_GAME_TEST;

    GO_SS_BackGround* m_pBackGround;
    GO_SS_Player* m_pPlayer;
    GO_SS_Wall* m_pWall;
    GO_SS_ShotString* m_pShotString;
    GO_SS_Target* m_pTarget;
    GO_SS_Map* m_pMap;
    GO_SS_Effect_Wind* m_pEffectWind;

    //メンバ変数
    int JumpCounter = 0;
    int JumpCountMax = 60;

    GO_SS_Collision m_ssCollision;      //当たり判定を司る者

//メンバ関数

//-----------------------------------------------------------------------------------------
//	JumpMove_Liner()
//-----------------------------------------------------------------------------------------
//	直線的な動き
//	ターゲットまで直で向かう
//-----------------------------------------------------------------------------------------
    void JumpMove_Liner();

//-----------------------------------------------------------------------------------------
//	JumpMove_Curve()
//-----------------------------------------------------------------------------------------
//	プロトタイプのときの動き
//-----------------------------------------------------------------------------------------
    void JumpMove_Curve();

//-----------------------------------------------------------------------------------------
//	JumpMove_Pendulum()
//-----------------------------------------------------------------------------------------
//	振り子のような動き
//	下に動いてから、上に上がる
//-----------------------------------------------------------------------------------------
    void JumpMove_Pendulum();

    void PlayerMove_Pendulum();

    int Pendulum_Counter = 0;

    const int PENDULUM_COUNTER_MAX = 100;

//-----------------------------------------------------------------------------------------
//    PlayerMoveSwitch(PlayerMove index);
//-----------------------------------------------------------------------------------------
//	プライヤーの挙動	-> 切り替え(PlayerMove　index)
//    PLAYERMOVE_LINEAR,
//    PLAYERMOVE_CURVE,
//    PLAYERMOVE_PENDULUM,
//-----------------------------------------------------------------------------------------
    void PlayerMoveSwitch(PlayerMove index);


    //移動
    void MovementManager(void);

    void FromAbyss();

   
    //デバッグ用
    void DebugOut(int i);

    //========================================
    //定数
    //========================================
    const FLOAT BG_SCROLL_SPEED = 0.001f;
    const FLOAT TARGET_MOVING_SPEED = 5.0f;
    const FLOAT WALL_MOVING_SPEED = 5.0f;
    const int PLAYER_ANIME_ADDITION = 1;
};


