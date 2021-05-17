#ifndef CENEMYATTACK_H
#define CENEMYATTACK_H

#include "CBase.h"

class CEnemyAttack : public CBase
{
private:
	int mLandingPoint_EA;	//攻撃判定の着地点(ザコ攻撃用)
	int mEraseLag;			//消滅するまでのラグ
	void Update();
	void Render();
	void Collision(CBase *i, CBase *y); //衝突判定
	DrawTask m_Draw;		//描画タスク
public:
	CEnemyAttack();
	int mAttackTime;		//攻撃判定の出現時間
};
#endif