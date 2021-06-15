#include "CSSearch.h"
#include "CTexture.h"
#include "SampleProperty.h"
#include "CPlayer.h"
#include "CEnemyAttack.h"
#include "CSceneGame.h"
#include "DrawTaskManager.h"
#include "CScore.h"
#include "CEnemy.h"

#define ANIATTACK 20		//攻撃アニメーション用
#define ANICNT 40		//アニメーション
#define ATTACKRANGE 20	//攻撃射程
#define POSITION 100		//プレイヤー位置

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture TextureEnemy1;
CSSearch*CSSearch::spInstance = 0;


CSSearch::CSSearch()
: mMoving(true)
, mAniAttack(-10)
, mAniMoving(0)
{
	m_Draw.RegistDraw(this, (DrawFunc)&CSSearch::Render, DrawPriority::Transparent, "CSSearch");
	mRect1.x = 300;
	mRect1.y = 200;
	mRect1.w = 150;
	mRect1.h = 100;

	mTag = EENEMMY_SS;
	spInstance = this;
	//mCSPosition = POSITION;
}

void CSSearch::Update() {

	if (mAniAttack > -10){
		mAniAttack--;
	}

	if (m_Attack == false){
		mMoving = true;
		mAniMoving++;
	}



	if (mMoving = true){
		CEnemy::spInstance->mRect1.x = mRect.x + CEnemy::mEnemyPosition;
		mMoving = true;

	}

	if (mMoving = true){
		CEnemy::spInstance->mRect1.x = mRect.x + CEnemy::mEnemyPosition;
		mMoving = true;

	}

	if (mMoving = true){
		CEnemy::spInstance->mRect1.y = mRect.y + CEnemy::mEnemyPosition;
		mMoving = true;

	}


	if (mMoving = true){
		CEnemy::spInstance->mRect1.y = mRect.y + CEnemy::mEnemyPosition;
		mMoving = true;

	}
}


void CSSearch::Render() {
	//左向き
	if (mRect1.x > CEnemy::spInstance->mRect1.x){


		//移動していないとき
		if (mMoving == false){
			if (mAniAttack == -10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack > 10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack > 0){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack > -10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
		}
		//移動しているとき
		else{
			if (mAniMoving % 60 < 30){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniMoving % 60 < 60){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
		}

		//無敵フラグが立っていないとき

		//移動していないとき
		if (mMoving == false){
			if (mAniAttack == -10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack > 10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack > 0){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack > -10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
		}
		//移動しているとき
		else{
			if (mAniMoving % 60 < 30){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniMoving % 60 < 60){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
		}
	}

	

	//右向き
	else{
		//無敵フラグが立っていないとき
		//移動していないとき
		if (mMoving == false){
			if (mAniAttack == -10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			//攻撃アニメーション
			else if (mAniAttack > 10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack > 0){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniAttack >= -10){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
		}
		//移動しているとき
		else{
			//移動アニメーション
			if (mAniMoving % 60 < 30){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
			else if (mAniMoving % 60 < 60){
				mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
			}
		}
	}

	//無敵状態フラグが立っているとき

	//移動していないとき
	if (mMoving == false){
		if (mAniAttack == -10){
			mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
		}
		//攻撃アニメーション
		else if (mAniAttack > 10){
			mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
		}
		else if (mAniAttack > 0){
			mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
		}
		else if (mAniAttack >= -10){
			mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
		}
	}
	//移動しているとき
	else{
		//移動アニメーション
		if (mAniMoving % 60 < 30){
			mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
		}
		else if (mAniMoving % 60 < 60){
			mRect1.Render(TextureEnemy1, 0, 300, 200, 0);
		}

	}

}


void CSSearch::Collision(CBase *i, CBase *y) {
	//プレイヤー1と当たったとき
	if (y->mTag == EPLAYER){
		if (y->mEnabled){
			if (mRect1.Collision(y->mRect1)){
				if (m_Attack == true && mAttackLag == 0){
					mEnabled = false;
					//CEnemy::mAttack = true;
				}
			}
		}
	}

}