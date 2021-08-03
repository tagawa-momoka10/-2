#ifndef CBASE_H
#define CBASE_H

#include "CRectangle.h"
#include "TaskInclude.h"

class CBase :public Task
{
public:
	CBase();
	static int mFx, mFy;	//‰¡ˆÚ“®,‰œs‚«ˆÚ“®
	CRectangle mRect;
	CRectangle mRect1;


	bool mEnabled;
	virtual void Collision(CBase *i,CBase *y){}
	enum ETag{
		EITEM1,
		EITEM2,
		EITEM3,
		EITEM4,
		EMINE,
		EENEMYATTACK_F,
		EENEMMY_SS,
		EENEMY_S,
		EENEMYATTACK_S,
		EWAKAME,
		EITEM,
		EICON1,
		EICON2,
		EKIHOU,
		EHARPOON,
		EPLAYERHP,
		EPLAYER,			//ålŒö
		EPLAYERATTACK,	//UŒ‚
	};
	ETag mTag;
};

#endif