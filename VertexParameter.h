//---------------------------
//	[VertexParameter.h]
//	Yuta Yanagisawa 
//---------------------------

//�����Ńp�����[�^�H�̐������Ă��������B�B�B

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

//��{���̉�����I�ԁ@����������NOMAL���p�����č��
struct VERTEX_NOMAL {
	D3DXVECTOR2 pos;
	D3DXVECTOR2 size;
};

//use
struct VERTEX_USE :public VERTEX_NOMAL{
	bool use;
};

//animation ( uv & counter)
struct VERTEX_ANIMATION :public VERTEX_NOMAL {
	FLOAT u;
	FLOAT v;
	int counter;
};

//use & animation
struct VERTEX_ANIMATION_USE :public VERTEX_NOMAL {
	bool use;

	FLOAT u;
	FLOAT v;
	int counter;
};

//alphsa��use
struct VERTEX_ALPHA_USE :public VERTEX_NOMAL {
	bool use;

	FLOAT alpha;
};

//alpha & use & animation
struct VERTEX_ALPHA_ANIMATION_USE :public VERTEX_NOMAL {
	bool use;
	FLOAT alpha;

	FLOAT u;
	FLOAT v;
	int counter;
};