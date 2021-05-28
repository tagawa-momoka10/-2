#ifndef CHARPOON_H
#define CHARPOON_H

#include "CRectangle.h"
#include "TaskInclude.h"
#include "CBase.h"


class CHarpoon : public CBase {
private:
	float md;		//�_�b�V���p�ϐ�
	int mDashPosition;		//�_�b�V���ʒu�L��
	float mj;		//�W�����v�p�ϐ�
	int mJump;		//�W�����v�ʒu�L��
	bool mdflag;	//�_�b�V���t���O(false�Ȃ�\,true�Ȃ�s��)
	bool mJflag;	//�W�����v�t���O(false�Ȃ�\,true�Ȃ�s��)

	void Update();
	void Render();
	int mInvincibleTime;
	int mAniMoving;	//���s�A�j���[�V�����p�̕ϐ�
	int mChara2Die;	//�v���C���[���S������A�j���[�V����
	bool mChara2DieFlg;	//�󎀖S����t���O
	int mAniCnt;
	int mAniDash;
	int mAniJump;	//�W�����v�A�j���[�V�����p�̕ϐ�

public:
	CHarpoon();
	DrawTask mDraw;		//�`��^�X�N����
	void Collision(CBase *i, CBase *y);
	static CHarpoon*spInstance;
	static int mAttackCount;
	static bool CHarpoon::mJumping;	//�v���C���[�W�����v���t���O

};

#endif