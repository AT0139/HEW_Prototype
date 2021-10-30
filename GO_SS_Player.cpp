#include "GO_SS_Player.h"
#include "GO_SS_Wall.h"

/*---------------------------------------------
*				初期化処理
---------------------------------------------*/
void GO_SS_Player::Initialize(void)
{
	Player_Texture = LoadTexture(TEX_NAME);

	Player_Vertex.pos = D3DXVECTOR2(SCREEN_WIDTH / 4, -100.0f);
	Player_Vertex.size = D3DXVECTOR2(200.0f, 200.0f);
	Player_Vertex.delay = 1.0f;

	m_Gravity = DEFAULT_GRAVITY;
	IsJump = false;
}
/*---------------------------------------------
*				終了処理
---------------------------------------------*/
void GO_SS_Player::Finalize(void)
{

}
/*---------------------------------------------
*				更新処理
---------------------------------------------*/
void GO_SS_Player::Update(void)
{
	
	if (GetKeyboardTrigger(DIK_SPACE) && Player_Vertex.pos.y >= SCREEN_HEIGHT / 4) {
		IsJump = true;
		m_Gravity = DEFAULT_GRAVITY * m_Jump;
	}
	
	m_Gravity += GRAVITY_ACCELERATION;
	Player_Vertex.pos.y += m_Gravity;
}
/*---------------------------------------------
*				描画処理
---------------------------------------------*/
void GO_SS_Player::Draw(void)
{
	DrawSprite(Player_Texture, Player_Vertex.pos.x, Player_Vertex.pos.y,
		Player_Vertex.size.x, Player_Vertex.size.y, 1.0f, 1.0f, 1.0f, 1.0f);
}





