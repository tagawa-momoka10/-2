#ifndef CSCENETITLE_H
#define CSCENETITLE_H

#include "CScene.h"
#include "CText.h"
#include"CRectangle.h"

class CSceneTitle : public CScene, CRectangle{
public:
	//���i�ڂ�
	int m_Line;
	int m_Score;
	bool mGame;
	float mFadeout;
	char buf[10];

	CRectangle mRect;
	DrawTask mDraw;

	CSceneTitle();

	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

	//���̃V�[���̎擾
	EScene GetNextScene();

};

#endif
