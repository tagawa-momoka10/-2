#ifndef CHARPOON_H
#define CHARPOON_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"


class CHarpoon : public CBase {
private:
	float md;		//�_�b�V���p�ϐ�
	int mDashPosition;		//�_�b�V���ʒu�L��
	bool mdflag;	//�_�b�V���t���O(false�Ȃ�\,true�Ȃ�s��)
	void Update();
	void Render();
	int mInvincibleTime;
	int mAniMoving;	//���s�A�j���[�V�����p�̕ϐ�
	int mChara2Die;	//�v���C���[���S������A�j���[�V����
	bool mChara2DieFlg;	//�󎀖S����t���O
	int mAniCnt;
	int mAniDash;

public:
	CHarpoon();
	DrawTask mDraw;		//�`��^�X�N����
	void Collision(CBase *i, CBase *y);
	static CHarpoon*spInstance;
	static int mAttackCount;
};

#endif