#pragma once
#include "main.h"

struct VERTEX_T {
	D3DXVECTOR2		pos;	//�ʒu�x�N�g��
	D3DXVECTOR2		vel;	//���x�x�N�g��
	D3DXCOLOR		color;	//���_�J���[
	D3DXVECTOR2 size;
};

struct VERTEX_A :public VERTEX_T {
	
	INT frame;
	FLOAT angle;
};