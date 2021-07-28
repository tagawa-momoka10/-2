#ifndef CMINE_H
#define CMINE_H

#include "CBase.h"

class CMine : public CBase{
private:
	bool mAttack;			//�U���t���O
	int mAttackLag;			//�U���t���O����������̍U���J�n�܂ł̃��O
	int ReduCnt;

	bool mInvincibleFlag;	//���G��Ԃ̃t���O
	int mInvincibleTime;	//���G����

	bool mMoving;			//�ړ���Ԃ��ǂ�����Ԃ�	

	bool mDeath;			//���S�t���O
	int mDeathCount;		//HP��0�ɂȂ��Ă��������܂ł̎��ԍ�������p

	int mAniMoving;			//�ړ��A�j���[�V�����p
	int mAniAttack;			//�U���A�j���[�V�����p
	void Update();
	void Render();
	DrawTask m_Draw; //�`��^�X�N
	void Collision(CBase *i, CBase *y); //�Փ˔���
public:
	CMine();
	int mHp;					//�̗�
	static CMine*spInstance;	//�G2�̍��W���擾
};

#endif