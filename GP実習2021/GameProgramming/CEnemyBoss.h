#ifndef CENEMYBOSS_H
#define CENEMYBOSS_H

#include "CBase.h"

class CEnemyBoss : public CBase
{
private:
	bool mAttack_S;			//攻撃フラグ(近距離攻撃)
	int mAttackLag_S;		//攻撃フラグが立った後の攻撃開始までのラグ(近距離攻撃)

	bool mAttack_L;			//攻撃フラグ(遠距離攻撃)
	int mAttackLag_L;		//攻撃開始までのラグ(遠距離攻撃)

	bool mAttack_A;			//攻撃フラグ(全体攻撃)
	int mAttackLag_A;		//攻撃フラグが立った後の攻撃開始までのラグ(全体攻撃)

	int mAniAttack_S;		//攻撃(近距離)のアニメーション用変数
	int mAniAttack_L;		//攻撃(遠距離)のアニメーション用変数
	int mAniAttack_A;		//攻撃(全体距離)のアニメーション用変数
	int mAniStopMove;		//静止状態のアニメーション用変数

	int mRandom;			//ランダムな値を入れておく変数
	bool mStopRandom;		//ランダムに出た値を固定しておく変数

	bool mInvincibleFlag;	//無敵状態のフラグ
	int mInvincibleTime;	//無敵時間

	bool mDeath;			//死亡フラグ
	int mDeathCount;		//死亡フラグが立って消えるまでのカウント

	int mY1, mY2;			//Y座標の差を求める用
	int mX1, mX2;			//X座標の差を求める用
	int mDifferenceY;		//プレイヤーとのY座標の差
	int mDifferenceX;		//プレイヤーとのX座標の差
	void Update();
	void Render();
	void Collision(CBase *i, CBase *y); //衝突処理
	DrawTask m_Draw; //描画タスク
public:
	CEnemyBoss();
	int mHp;
};

#endif