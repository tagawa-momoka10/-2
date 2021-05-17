#include "CEnemyAttack.h"
#include "SampleProperty.h"
#include "CPlayer.h"
#include "CKey.h"

#define GRAVITY 1				//重力
#define ENEMY_BULLET_SPEED 10	//ザコの弾のスピード
#define BOSS_BULLET_SPEED 1		//ボスの弾のスピード
#define JUMPPOWER 25			//ジャンプ力
#define ERASELAG 60				//消えるまでのラグ

extern CTexture TextureEnemy1;
extern CTexture TextureEnemy2;
//extern CTexture TextureBoss1;
//extern CTexture TextureBoss2;
//extern CTexture TextureBoss3;

CEnemyAttack::CEnemyAttack()
: mLandingPoint_EA(0)
, mEraseLag(ERASELAG)
{
	m_Draw.RegistDraw(this, (DrawFunc)&CEnemyAttack::Render, DrawPriority::Transparent, "CEnemyAttack");
}

void CEnemyAttack::Update(){

	//////////////////////////////////////////////////////////////////////////

	//ボスの近距離攻撃
	if (mTag == EBOSSATTACK_S){
		mAttackTime--;
		//攻撃判定の出現終了
		if (mAttackTime <= 0){
			Kill();
		}
	}

	//////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////



	//////////////////////////////////////////////////////////////////////////

	//近距離型のザコ敵の攻撃
	if (mTag == EENEMYATTACK_F){
		mAttackTime--;
		//攻撃判定の出現終了
		if (mAttackTime <= 0){
			Kill();
		}
	}

	//////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////
}

void CEnemyAttack::Render(){
	
}

void CEnemyAttack::Collision(CBase *i, CBase *y) {
	//プレイヤーと衝突したら
	if (y->mTag == EPLAYER){
		if (y->mEnabled){
			if (mRect.Collision(y->mRect)){
			
				return;
			}
		}
	}
	//プレイヤーの攻撃を受けたら
	if (y->mTag == EPLAYERATTACK){
		if (y->mEnabled){
			if (mRect.Collision(y->mRect)){
				
				return;
			}
		}
	}

}