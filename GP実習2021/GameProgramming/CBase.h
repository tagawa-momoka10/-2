#ifndef CBASE_H
#define CBASE_H

#include "CRectangle.h"
#include "TaskInclude.h"

class CBase :public Task
{
public:
	CBase();
	static int mFx, mFy;	//横移動,奥行き移動
	CRectangle mRect;
	bool mEnabled;
	virtual void Collision(CBase *i,CBase *y){}
	enum ETag{
		EITEM1,
		EITEM2,
		EITEM3,
		EITEM4,
		EHARPOON,
		EPLAYER,			//主人公
		EPLAYERATTACK,	//攻撃
		EENEMY_F,
		EENEMYATTACK_F,
		EENEMY_S,
		EENEMYATTACK_S,
		EBOSS,
		EBOSSATTACK_S,		//ボスの攻撃(近距離)
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