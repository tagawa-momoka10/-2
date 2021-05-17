#ifndef CENEMY_H
#define CENEMY_H

#include "CBase.h"

class CEnemy : public CBase
{
private:
	bool mAttack;			//�U���t���O
	int mAttackLag;			//�U���t���O����������̍U���J�n�܂ł̃��O

	bool mInvincibleFlag;	//���G��Ԃ̃t���O
	int mInvincibleTime;	//���G����

	bool mMoving;			//�ړ���Ԃ��ǂ����Ԃ��t���O

	bool mDeath;			//���S�t���O
	int mDeathCount;		//HP��0�ɂȂ��Ă��������܂ł̎��ԍ�������p

	int mAniAttack;			//�U���A�j���[�V�����p
	int mAniMoving;			//�ړ��A�j���[�V�����p
	void Update();
	void Render();
	DrawTask m_Draw; //�`��^�X�N
	void Collision(CBase *i, CBase *y); //�Փ˔���
public:
	CEnemy();
	int mHp;					//�̗�
	static CEnemy*spInstance;	//�G�̍��W���擾
};

#endif
