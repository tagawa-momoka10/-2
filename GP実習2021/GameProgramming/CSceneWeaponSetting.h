#ifndef CSCENEWEAPONETTING_H
#define CSCENEWEAPONETTING_H

#include "CScene.h"
#include "CText.h"

class CSceneWeaponSetting : public CScene {
public:
	int m_Line;
	int m_Score;
	CSceneWeaponSetting();

	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//���̃V�[���̎擾
	EScene GetNextScene();
};

#endif
