#ifndef CENEMYBOSS_H
#define CENEMYBOSS_H

#include "CBase.h"

class CEnemyBoss : public CBase
{
private:
	bool mAttack_S;			//�U���t���O(�ߋ����U��)
	int mAttackLag_S;		//�U���t���O����������̍U���J�n�܂ł̃��O(�ߋ����U��)

	bool mAttack_L;			//�U���t���O(�������U��)
	int mAttackLag_L;		//�U���J�n�܂ł̃��O(�������U��)

	bool mAttack_A;			//�U���t���O(�S�̍U��)
	int mAttackLag_A;		//�U���t���O����������̍U���J�n�܂ł̃��O(�S�̍U��)

	int mAniAttack_S;		//�U��(�ߋ���)�̃A�j���[�V�����p�ϐ�
	int mAniAttack_L;		//�U��(������)�̃A�j���[�V�����p�ϐ�
	int mAniAttack_A;		//�U��(�S�̋���)�̃A�j���[�V�����p�ϐ�
	int mAniStopMove;		//�Î~��Ԃ̃A�j���[�V�����p�ϐ�

	int mRandom;			//�����_���Ȓl�����Ă����ϐ�
	bool mStopRandom;		//�����_���ɏo���l���Œ肵�Ă����ϐ�

	bool mInvincibleFlag;	//���G��Ԃ̃t���O
	int mInvincibleTime;	//���G����

	bool mDeath;			//���S�t���O
	int mDeathCount;		//���S�t���O�������ď�����܂ł̃J�E���g

	int mY1, mY2;			//Y���W�̍������߂�p
	int mX1, mX2;			//X���W�̍������߂�p
	int mDifferenceY;		//�v���C���[�Ƃ�Y���W�̍�
	int mDifferenceX;		//�v���C���[�Ƃ�X���W�̍�
	void Update();
	void Render();
	void Collision(CBase *i, CBase *y); //�Փˏ���
	DrawTask m_Draw; //�`��^�X�N
public:
	CEnemyBoss();
	int mHp;
};

#endif