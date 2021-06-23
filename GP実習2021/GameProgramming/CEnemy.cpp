#include "CEnemy.h"
#include "CTexture.h"
#include "SampleProperty.h"
#include "CPlayer.h"
#include "CEnemyAttack.h"
#include "CSceneGame.h"
#include "DrawTaskManager.h"
#include "CScore.h"
#include "CScene.h"
#include "CSSearch.h"

#define SPEED 1				//移動速度
#define INVINCIBLETIME 60	//無敵時間
#define ATTACKSIZE 55		//攻撃判定の大きさ
#define HP 2				//体力
#define ANIATTACK 20		//攻撃アニメーション用
#define SCORE 100			//ざこ敵撃破時のスコア
#define POSITION 100		//位置

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture TextureEnemy;
int CEnemy::mEnemyPosition;
CEnemy*CEnemy::spInstance = 0;

CEnemy::CEnemy()
:mAttackLag(90)
, mHp(HP)
, mAttack(false)
, mInvincibleTime(0)
, mInvincibleFlag(false)
, mMoving(true)
, mAniAttack(-10)
, mAniMoving(0)
, mDeath(false)
, mDeathCount(0)

{
	m_Draw.RegistDraw(this, (DrawFunc)&CEnemy::Render, DrawPriority::Transparent, "CEnemy");
	mRect.x = 300;
	mRect.y = 200;
	mRect.w = 150;
	mRect.h = 100;

	mTag = EENEMY_S;
	spInstance = this;
}

void CEnemy::Update() {

	//HPが0を切ると死亡フラグが立つ、スコア加算
	if (mHp <= 0 && mDeath == false){
		mDeath = true;
		mDeathCount = 60;
		//CScore::mScore += SCORE;
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
			mRect.h = 50;
		}
		if (mDeathCount == 0){
			//死亡
			Kill();
		}
	}

	//死亡フラグが立つとリターン
	if (mDeath)return;

	//無敵時間が0になるまでカウントダウン
	if (mInvincibleTime > 0){
		mInvincibleTime--;
	}
	//無敵時間が0になると無敵状態解除
	if (mInvincibleTime <= 0){
		mInvincibleFlag = false;
	}

	//0になるまで減らす
	if (mAttackLag > 0){
		mAttackLag--;
		if (mAttackLag == 20){
			mAniAttack = ANIATTACK;
		}
	}

	//if (mMoving = true){
	//	mRect.x -= 4;
	//	CBase::mFx = -1;
	//	mMoving = true;
		//本体に追尾して移動する
	//if (mMoving = true){
	//		mRect.x < CSSearch::spInstance->mRect.x + mEnemyPosition;
	//		mMoving = true;
	//	}

	//else if (mMoving = true){
	//		CSSearch::spInstance->mRect.x < mRect.x + mEnemyPosition;
	//		mMoving = true;

	//	}

	//if (mMoving = true){
	//		mRect.y < CSSearch::spInstance->mRect.y + mEnemyPosition;
	//		mMoving = true;

	//	}

	//else if (mMoving = true){
	//		CSSearch::spInstance->mRect.y < mRect.y + mEnemyPosition;
	//		mMoving = true;

	//	}
	//}

	//CEnemy::spInstance->mRect1.x = mRect1.x + CEnemy::mEnemyPosition;



	//攻撃
	if (mAttack == true && mAttackLag == 0){
		if (mRect.x < CPlayer::spInstance->mRect.x){
			CEnemyAttack *EnemyAttack = new CEnemyAttack();
			EnemyAttack->mRect.x = mRect.x + 30;
			EnemyAttack->mRect.y = mRect.y;
			EnemyAttack->mRect.w = ATTACKSIZE;
			EnemyAttack->mRect.h = 60;
			EnemyAttack->mAttackTime = 10;
			EnemyAttack->mTag = EENEMYATTACK_F;
		}
		else{
			CEnemyAttack *EnemyAttack = new CEnemyAttack();
			EnemyAttack->mRect.x = mRect.x - 30;
			EnemyAttack->mRect.y = mRect.y;
			EnemyAttack->mRect.w = ATTACKSIZE;
			EnemyAttack->mRect.h = 60;
			EnemyAttack->mAttackTime = 10;
			EnemyAttack->mTag = EENEMYATTACK_F;
		}
		//攻撃フラグをfalseにする
		mAttack = false;
	}

	if (mAniAttack > -10){
		mAniAttack--;
	}

	if (mAttack == false){
		CEnemy::mMoving = false;
		mAniMoving++;
		mRect.x += SPEED;
	}


	if (mRect.y>CEnemy::spInstance->mRect.y){
		DrawTaskManager::GetInstance()->ChangePriority(&m_Draw);
	}

	//攻撃フラグが立っている間はリターン
	if (mAttack)return;

	//攻撃フラグが立って90フレーム後に攻撃するための値を設定
	mAttackLag = 90;
}

void CEnemy::Render() {
	//左向き
	if (mRect.x > CPlayer::spInstance->mRect.x){
		//死亡フラグが立っていないとき
		if (mDeath == false){
			if (mInvincibleFlag == false){
				//移動していないとき
				if (mMoving == false){
					if (mAniAttack == -10){
						mRect.Render(TextureEnemy, 0, 300, 200, 0);
					}
					else if (mAniAttack > 10){
						mRect.Render(TextureEnemy, 0, 300, 200, 0);
					}
					else if (mAniAttack > 0){
						mRect.Render(TextureEnemy, 0, 300, 200, 0);
					}
					else if (mAniAttack > -10){
						mRect.Render(TextureEnemy, 0, 300, 200, 0);
					}
				}
				//移動しているとき
				else{
					if (mAniMoving % 60 < 30){
						mRect.Render(TextureEnemy, 0, 300, 200, 0);
					}
					else if (mAniMoving % 60 < 60){
						mRect.Render(TextureEnemy, 0, 300, 200, 0);
					}
				}
			}
			//無敵フラグが立っていないとき
			else{
				//点滅する
				if (mInvincibleTime % 10 < 5){
					mRect.Render(TextureEnemy, 0, 0, 0, 0);
				}
				else{
					//移動していないとき
					if (mMoving == false){
						if (mAniAttack == -10){
							mRect.Render(TextureEnemy, 0, 300, 200, 0);
						}
						else if (mAniAttack > 10){
							mRect.Render(TextureEnemy, 0, 300, 200, 0);
						}
						else if (mAniAttack > 0){
							mRect.Render(TextureEnemy, 0, 300, 200, 0);
						}
						else if (mAniAttack > -10){
							mRect.Render(TextureEnemy, 0, 300, 200, 0);
						}
						//攻撃時のアニメーション
						if (mAniAttack > 60){
							mRect.Render(TextureEnemy, 0, 300, 200, 0);
						}
						else if (mAniAttack > 0){
							mRect.Render(TextureEnemy, 0, 300, 200, 0);
						}
					}
					//移動しているとき
					else{
						if (mAniMoving % 60 < 30){
							mRect.Render(TextureEnemy, 0, 300, 200, 0);
						}
						else if (mAniMoving % 60 < 60){
							mRect.Render(TextureEnemy, 0, 300, 200, 0);
						}
					}
				}
			}
		}
		//死亡フラグが立った時
		else{
			if (mDeathCount > 30){
				mRect.Render(TextureEnemy, 0, 300, 200, 0);
			}
			else{
				mRect.Render(TextureEnemy, 0, 300, 200, 0);
			}
		}
	}

	//右向き
	else{
		//死亡フラグが立っていないとき
		if (mDeath == false){
			//無敵フラグが立っていないとき
			if (mInvincibleFlag == false){
				//移動していないとき
				if (mMoving == false){
					if (mAniAttack == -10){
						mRect.Render(TextureEnemy, 0, 300, 200, 0);
					}
					//攻撃アニメーション
					else if (mAniAttack > 10){
						mRect.Render(TextureEnemy, 0, 300, 200, 0);
					}
					else if (mAniAttack > 0){
						mRect.Render(TextureEnemy, 0, 300, 200, 0);
					}
					else if (mAniAttack >= -10){
						mRect.Render(TextureEnemy, 0, 300, 200, 0);
					}
				}
				//移動しているとき
				else{
					//移動アニメーション
					if (mAniMoving % 60 < 30){
						mRect.Render(TextureEnemy, 0, 300, 200, 0);
					}
					else if (mAniMoving % 60 < 60){
						mRect.Render(TextureEnemy, 0, 300, 200, 0);
					}
				}
			}

			//無敵状態フラグが立っているとき
			else{
				//点滅する
				if (mInvincibleTime % 10 < 5){
					mRect.Render(TextureEnemy, 0, 0, 0, 0);
				}
				else{
					//移動していないとき
					if (mMoving == false){
						if (mAniAttack == -10){
							mRect.Render(TextureEnemy, 0, 300, 200, 0);
						}
						//攻撃アニメーション
						else if (mAniAttack > 10){
							mRect.Render(TextureEnemy, 0, 300, 200, 0);
						}
						else if (mAniAttack > 0){
							mRect.Render(TextureEnemy, 0, 300, 200, 0);
						}
						else if (mAniAttack >= -10){
							mRect.Render(TextureEnemy, 0, 300, 200, 0);
						}
					}
					//移動しているとき
					else{
						//移動アニメーション
						if (mAniMoving % 60 < 30){
							mRect.Render(TextureEnemy, 0, 300, 200, 0);
						}
						else if (mAniMoving % 60 < 60){
							mRect.Render(TextureEnemy, 0, 300, 200, 0);
						}
					}
				}
			}
		}

		//死亡フラグが立った時
		else{
			if (mDeathCount > 30){
				mRect.Render(TextureEnemy, 0, 300, 200, 0);
			}
			else{
				mRect.Render(TextureEnemy, 0, 300, 200, 0);
			}
		}
	}

}

void CEnemy::Collision(CBase *i, CBase *y) {
	//プレイヤー1と当たったとき
	
		if (y->mTag == EPLAYER){
			if (y->mEnabled){
				if (mRect.Collision(y->mRect)){
					//プレイヤーと接触すると攻撃フラグが立つ
					mAttack = true;
					mMoving = false;
					
					//追尾
					if (mRect.x < CPlayer::spInstance->mRect.x){
						mRect.x += SPEED;
					}
					else if (CPlayer::spInstance->mRect.x < mRect.x){
						mRect.x -= SPEED;
					}

					if (mRect.y < CPlayer::spInstance->mRect.y){
						mRect.y += SPEED;
						if (mRect.y > -140){
							mRect.y -= SPEED;
						}
					}
					else if (CPlayer::spInstance->mRect.y < mRect.y){
						mRect.y -= SPEED;
					}



				
					return;

				}
			}
		}


	if (mRect.y - CPlayer::spInstance->mRect.y < 20){
		if (y->mTag == EPLAYERATTACK){
			if (mRect.Collision(y->mRect)){
				//無敵状態で無ければ
				if (mInvincibleFlag == false){
					//体力が減る
					mHp -= 1;
					//無敵状態へ
					mInvincibleFlag = true;
					mInvincibleTime = INVINCIBLETIME;
				}
				return;
			}
		}
	}
}

//CEnemy*CEnemy::spInstance = 0;
