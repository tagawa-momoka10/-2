#ifndef CSCENEOPTION_H
#define CSCENEOPTION_H

#include "CScene.h"
#include "CText.h"

class CSceneOption : public CScene {
public:
	int m_Line;

	CSceneOption();
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//���̃V�[���̎擾
	EScene GetNextScene();
};

#endif
