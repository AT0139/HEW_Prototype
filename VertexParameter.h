#pragma once
#include "main.h"

struct VERTEX_T {
	D3DXVECTOR2		pos;	//�ʒu�x�N�g��
	D3DXVECTOR2		vel;	//���x�x�N�g��
	D3DXCOLOR		color;	//���_�J���[
};

struct VERTEX_A :public VERTEX_T {
	D3DXVECTOR2 size;
	INT frame;
	FLOAT angle;
};