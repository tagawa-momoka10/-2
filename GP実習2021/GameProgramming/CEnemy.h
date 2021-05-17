#ifndef CENEMY_H
#define CENEMY_H

#include "CBase.h"

class CEnemy : public CBase
{
private:
	bool mAttack;			//攻撃フラグ
	int mAttackLag;			//攻撃フラグが立った後の攻撃開始までのラグ

	bool mInvincibleFlag;	//無敵状態のフラグ
	int mInvincibleTime;	//無敵時間

	bool mMoving;			//移動状態かどうか返すフラグ

	bool mDeath;			//死亡フラグ
	int mDeathCount;		//HPが0になってから消えるまでの時間差をつける用

	int mAniAttack;			//攻撃アニメーション用
	int mAniMoving;			//移動アニメーション用
	void Update();
	void Render();
	DrawTask m_Draw; //描画タスク
	void Collision(CBase *i, CBase *y); //衝突判定
public:
	CEnemy();
	int mHp;					//体力
	static CEnemy*spInstance;	//敵の座標を取得
};

#endif
