#ifndef CSCENETUTORIAL_H
#define CSCENETUTORIAL_H

#include "CScene.h"
#include "CText.h"

class CSceneTutorial : public CScene {
public:
	int m_Line;
	CSceneTutorial();
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//���̃V�[���̎擾
	EScene GetNextScene();
};

#endif
