#ifndef CENEMYATTACK_H
#define CENEMYATTACK_H

#include "CBase.h"

class CEnemyAttack : public CBase
{
private:
	int mLandingPoint_EA;	//�U������̒��n�_(�U�R�U���p)
	int mEraseLag;			//���ł���܂ł̃��O
	void Update();
	void Render();
	void Collision(CBase *i, CBase *y); //�Փ˔���
	DrawTask m_Draw;		//�`��^�X�N
public:
	CEnemyAttack();
	int mAttackTime;		//�U������̏o������
};
#endif