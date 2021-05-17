#ifndef CBASE_H
#define CBASE_H

#include "CRectangle.h"
#include "TaskInclude.h"

class CBase :public Task
{
public:
	CBase();
	static int mFx, mFy;	//���ړ�,���s���ړ�
	CRectangle mRect;
	bool mEnabled;
	virtual void Collision(CBase *i,CBase *y){}
	enum ETag{
		EITEM1,
		EITEM2,
		EITEM3,
		EITEM4,
		EHARPOON,
		EPLAYER,			//��l��
		EPLAYERATTACK,	//�U��
		EENEMY_F,
		EENEMYATTACK_F,
		EENEMY_S,
		EENEMYATTACK_S,
		EBOSS,
		EBOSSATTACK_S,		//�{�X�̍U��(�ߋ���)
		EBOSSATTACK_A,
		EBOSSHP,
		EITEM,
		EICON1,
		EICON2,
		EPLAYERHP,
		EKIHOU,
		EWAKAME,
		
	};
	ETag mTag;
};

#endif