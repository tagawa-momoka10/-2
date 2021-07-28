#include "CMine.h"
#include "CTexture.h"
#include "SampleProperty.h"
#include "CPlayer.h"
#include "CEnemyAttack.h"
#include "CSceneGame.h"
#include "DrawTaskManager.h"
#include "CScore.h"

#define SPEED 0				//移動速度
#define ATTACKLAG 120		//攻撃開始までのラグ
#define INVINCIBLETIME 60	//無敵時間
#define HP 1				//体力
#define ANIATTACK 120		//攻撃アニメーション用
#define SCORE 150			//スコア

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture TextureMine1;
extern CTexture TextureMine2;
extern CTexture TextureMine3;

CMine::CMine()
:mAttackLag(ATTACKLAG)
, mHp(HP)
, mInvincibleTime(0), mInvincibleFlag(false)
, mAniAttack(0)
, mAttack(false)
, mMoving(false)
, mAniMoving(0)
, mDeath(false)
, mDeathCount(0)
, ReduCnt(180)

{
	m_Draw.RegistDraw(this, (DrawFunc)&CMine::Render, DrawPriority::Transparent, "CMine");
	mRect.x = 500;
	mRect.y = 500;
	mRect.w = 250;
	mRect.h = 250;

	mTag = EENEMY_M;
	spInstance = this;
}

void CMine::Update() {

	if (mRect.y > CPlayer::spInstance->mRect.y){
		DrawTaskManager::GetInstance()->ChangePriority(&m_Draw);
	}

	//HPが0を切ると死亡フラグが立つ
	if (mHp <= 0 && mDeath == false){
		mDeath = true;
		mDeathCount = 60;
		CScore::mScore += SCORE;
	}

	if (mDeath == true && mDeathCount > 0){
		mDeathCount--;
		if (mDeathCount == 30){
			if (mRect.x > CPlayer::spInstance->mRect.x){
				mRect.x += 30;
			}
			else{
				mRect.x -= 30;
			}
			mRect.y -= 30;
			mRect.w = 80;
			mRect.h = 55;
		}
		if (mDeathCount == 0){
			//死亡
			Kill();
		}
	}
	//死亡フラグが立つとリターン
	if (mDeath)return;

	////無敵時間が0になるまでカウントダウン
	//if (mInvincibleTime > 0){
	//	mInvincibleTime--;
	//}
	////無敵時間が0になると無敵状態解除
	//if (mInvincibleTime <= 0){
	//	mInvincibleFlag = false;
	//}

	if (mRect.y == CPlayer::spInstance->mRect.y&&mAttack == false){
		mAttack = true;
		mMoving = false;
		//攻撃フラグが立って120フレーム後に攻撃するための値を設定
		mAttackLag = ATTACKLAG;
	}

	//0になるまで減らす
	if (mAttackLag > 0){
		mAttackLag--;
	}

	//攻撃
	if (mAttack == true && mAttackLag == 0){
		if (mRect.x < CPlayer::spInstance->mRect.x){
			CEnemyAttack *EnemyAttack = new CEnemyAttack();
			EnemyAttack->mRect.x = mRect.x + 20;
			mAniAttack = ANIATTACK;
			//攻撃フラグが立って180フレーム後に攻撃するための値を設定
			mAttackLag = ATTACKLAG;
		}
		else{
			CEnemyAttack *EnemyAttack = new CEnemyAttack();
			EnemyAttack->mRect.x = mRect.x - 20;
			mAniAttack = ANIATTACK;
			//攻撃フラグが立って180フレーム後に攻撃するための値を設定
			mAttackLag = ATTACKLAG;
		}
	}

	if (mAniAttack > 0){
		mAniAttack--;
		if (mAniAttack == 0){
			//攻撃フラグをfalseにする
			mAttack = false;
		}
	}


	if (mAttack == false){
		mMoving = true;
		mAniMoving++;

	}

}

void CMine::Render() {
	////右向き
	//if (mRect.x < CPlayer::spInstance->mRect.x){
	//	//死亡フラグが立っていないとき
	//	if (mDeath == false){
	//		//無敵フラグが立っていないとき
	//		if (mInvincibleFlag == false){
	//			//移動していないとき
	//			if (mMoving == false){
	//				if (mAniAttack == 0){
	//					mRect.Render(TextureMine1, 0, 600, 600, 0);
	//				}
	//				//攻撃時のアニメーション
	//				if (mAniAttack > 180){
	//					mRect.Render(TextureMine2, 0, 600, 600, 0);
	//				}
	//				else if (mAniAttack > 0){
	//					mRect.Render(TextureMine2, 0, 600, 600, 0);
	//				}
	//			}
	//		}
	//		//無敵フラグが立っていないとき
	//		else{
	//			//点滅する
	//			if (mInvincibleTime % 10 < 5){
	//				mRect.Render(TextureMine2, 0, 0, 0, 0);
	//			}
	//			else{
	//				//移動していないとき
	//				if (mMoving == false){
	//					if (mAniAttack == 0){
	//						mRect.Render(TextureMine1, 0, 600, 600, 0);
	//					}
	//					//攻撃時のアニメーション
	//					if (mAniAttack > 180){
	//						mRect.Render(TextureMine3, 0, 600, 600, 0);
	//					}
	//					else if (mAniAttack > 0){
	//						mRect.Render(TextureMine3, 0, 600, 600, 0);
	//					}
	//				}
	//			}
	//		}
	//	}
	//}
	//左向き
	//else{
		//死亡フラグが立っていないとき
		if (mDeath == false){
			//無敵フラグが立っていないとき
			if (mInvincibleFlag == false){
				if (mMoving == false){
					if (mAniAttack == 0){
						mRect.Render(TextureMine1, 0, 600, 600, 0);
					}
					//攻撃時のアニメーション
					if (mAniAttack > 180){
						mRect.Render(TextureMine2, 0, 600, 600, 0);
					}
					else if (mAniAttack > 0){
						mRect.Render(TextureMine2, 0, 600, 600, 0);
					}
				}
				else{
					if (mAniMoving % 180 < 45){
						mRect.Render(TextureMine2, 0, 600, 600, 0);
					}
					else if (mAniMoving % 180 < 90){
						mRect.Render(TextureMine2, 0, 600, 600, 0);
					}
					else if (mAniMoving % 180 < 135){
						mRect.Render(TextureMine2, 0, 600, 600, 0);
					}
					else if (mAniMoving % 180 < 180){
						mRect.Render(TextureMine2, 0, 600, 600, 0);
					}
				}
			//}
			////無敵フラグが立っているとき
			//else{
			//	//点滅する
			//	if (mInvincibleTime % 10 < 5){
			//		mRect.Render(TextureEnemy2, 0, 0, 0, 0);
			//	}
			//	else{
			//		if (mMoving == false){
			//			if (mAniAttack == 0){
			//				mRect.Render(TextureEnemy2, 130, 254, 510, 313);
			//			}
			//			//攻撃時のアニメーション
			//			if (mAniAttack > 60){
			//				mRect.Render(TextureEnemy2, 3, 127, 766, 568);
			//			}
			//			else if (mAniAttack > 0){
			//				mRect.Render(TextureEnemy2, 131, 255, 766, 568);
			//			}
			//		}
			//		else{
			//			if (mAniMoving % 80 < 20){
			//				mRect.Render(TextureEnemy2, 2, 126, 510, 313);
			//			}
			//			else if (mAniMoving % 80 < 40){
			//				mRect.Render(TextureEnemy2, 130, 254, 510, 313);
			//			}
			//			else if (mAniMoving % 80 < 60){
			//				mRect.Render(TextureEnemy2, 259, 383, 510, 313);
			//			}
			//			else if (mAniMoving % 80 < 80){
			//				mRect.Render(TextureEnemy2, 130, 254, 510, 313);
			//			}
			//		}
			//	}
			//}
		}
		////死亡フラグが立っているとき
		//else{
		//	if (mDeathCount > 30){
		//		mRect.Render(TextureMine3, 0, 600, 600, 0);
		//	}
		//	else{
		//		mRect.Render(TextureMine3, 0, 600, 600, 0);
		//	}
		//}
	}
}

void CMine::Collision(CBase *i, CBase *y) {
	//if (mRect.y - CPlayer::spInstance->mRect.y < 20){
	//}

	//プレイヤーの攻撃に当たったとき
	if (mTag == EPLAYERATTACK){
		if (mRect.Collision(y->mRect)){
			//無敵状態で無ければ
			if (mInvincibleFlag == false){
				//体力が減る
				mHp -= 1;
			}
			return;
		}
	}

	//プレイヤーに当たったとき
	if (mTag == EPLAYER){
		if (mRect.Collision(y->mRect)){
			if (ReduCnt > 0){
				ReduCnt--;
			}
			if (ReduCnt == 0){
				mAttack = true;
				ReduCnt++;
				if (ATTACKLAG == 180){
					Kill();
				}
			}
		}
		return;
	}
}


CMine*CMine::spInstance = 0;