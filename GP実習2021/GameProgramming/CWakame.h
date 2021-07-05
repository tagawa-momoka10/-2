#ifndef CWAKAME_H
#define CWAKAME_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"

class CWakame : public CBase {
private:
	DrawTask mDraw;		//�`��^�X�N����
	int mAniCnt;	//�A�j���[�V�����J�E���g
	void Collision(CBase *i, CBase *y);		//�Փ˔���
	int mAniMoving;	//���s�A�j���[�V�����p�̕ϐ�
	void Update();
	void Render();
	static bool mMoving;	//true(���s��)	false(�Î~���)
public:
	CWakame();
	CRectangle m_RectW;
};
#endif 
