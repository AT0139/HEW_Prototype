#include "GO_VortexRotation.h"
#include "GO_Player.h"
#include "GO_Vortex.h"

void GO_VortexRotation::Update(void)
{
	//�����炢���ǁA�p�x����ăZ�b�g���Ă邾���B
	mp_vortex->SetVortexAngle(atan2((double)mp_player->GetPos().x - (double)mp_vortex->GetVortexPos().x,
		(double)mp_player->GetPos().y - (double)mp_vortex->GetVortexPos().y));
}


