#ifndef CSSEARCH_H
#define CSSEARCH_H

#include "CBase.h"

class CSSearch : public CBase
{
private:
	bool mAttack;			//攻撃フラグ
	int mAttackLag;			//攻撃フラグが立った後の攻撃開始までのラグ

	bool mMoving;			//移動状態かどうか返すフラグ

	int mAniAttack;			//攻撃アニメーション用
	int mAniMoving;			//移動アニメーション用
	void Update();
	void Render();
	DrawTask m_Draw; //描画タスク
	void Collision(CBase *i, CBase *y); //衝突判定
public:
	CSSearch();
	static CSSearch*spInstance;	//敵の座標を取得
};

#endif