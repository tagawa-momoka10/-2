#ifndef CBUBBLE_H
#define CBUBBLE_H

#include "TaskInclude.h"
#include "CBase.h"

class CBubble : public CBase{
private:
	void Update();
	void Render();
	void Collision(CBase *i, CBase *y);		//�Փ˔���
	DrawTask mDraw;		//�`��^�X�N����
	int mAniMoving;	//���s�A�j���[�V�����p�̕ϐ�

public:
	CBubble();
};


#endif