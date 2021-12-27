#pragma once
//-------------------------------
//	[Tutorial.cpp]	
//-------------------------------
//	create -> ���V�D��
//	change -> ����
//	
//-------------------------------

//	�y�[�W�Ǘ�
enum TUTORIAL {
	TUTORIAL_NONE,
	TUTORIAL_001,
	TUTORIAL_002,
	TUTORIAL_003,
	TUTORIAL_004,
	TUTORIAL_MAX,
};

class Tutorial
{
private:	
	//�y�[�W�Ǘ��ϐ�
	int m_nowPage = 0;

	char* m_TexName_001 = "data/TEXTURE/mati1.png";
	//const char* m_TexName_002 = "data/TEXTURE/mati1.png";
		//	������Ȋ����Œǉ����Ă����Ă���

public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
//	�����o�ϐ�	

	//	�e�N�X�`���[�̕ۑ��p�ϐ�
	int m_TexIndex_001;
	//int m_TexIndex_001_hoge;
	int m_TexIndex_002;
	int m_TexIndex_003;
	int m_TexIndex_004;

//	�����o�֐�

	//	�e�N�X�`�����[�h
	void TutorialTextureLoad();

//-------------------------------
//	Init
//-------------------------------
	void TutorialInit_001();
	void TutorialInit_002();
	void TutorialInit_003();
	void TutorialInit_004();

//-------------------------------
//	Update
//-------------------------------
	void TutorialUpdate_001();
	void TutorialUpdate_002();
	void TutorialUpdate_003();
	void TutorialUpdate_004();

//-------------------------------
//	Draw
//-------------------------------
	void TutorialDraw_001();
	void TutorialDraw_002();
	void TutorialDraw_003();
	void TutorialDraw_004();

};


