#ifndef CENEMY2_H
#define CENEMY2_H

#include "CBase.h"

class CEnemy2 : public CBase{
private:
	bool mAttack;			//攻撃フラグ
	int mAttackLag;			//攻撃フラグが立った後の攻撃開始までのラグ

	bool mInvincibleFlag;	//無敵状態のフラグ
	int mInvincibleTime;	//無敵時間

	bool mMoving;			//移動状態かどうかを返す	

	bool mDeath;			//死亡フラグ
	int mDeathCount;		//HPが0になってから消えるまでの時間差をつける用

	int mAniMoving;			//移動アニメーション用
	int mAniAttack;			//攻撃アニメーション用
	void Update();
	void Render();
	DrawTask m_Draw; //描画タスク
	void Collision(CBase *i, CBase *y); //衝突判定
public:
	CEnemy2();
	int mHp;					//体力
	static CEnemy2*spInstance;	//敵2の座標を取得
};

#endif