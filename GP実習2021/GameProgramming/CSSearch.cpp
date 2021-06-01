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

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture TextureEnemy1;

CSSearch::CSSearch()
: mMoving(true)
, mAniAttack(-10)
, mAniMoving(0)
{
	m_Draw.RegistDraw(this, (DrawFunc)&CSSearch::Render, DrawPriority::Transparent, "CSSearch");
	mRect.w = 300;
	mRect.h = 100;

	mTag = EENEMMY_SS;
	spInstance = this;
}

void CSSearch::Update() {

	if (mAniAttack > -10){
		mAniAttack--;
	}

	if (mAttack == false){
		mMoving = true;
		mAniMoving++;
		//本体に追尾して移動する
		if (mRect.x < CEnemy::spInstance->mRect.x){
		}
		else if (CEnemy::spInstance->mRect.x < mRect.x){
		}

		if (mRect.y < CEnemy::spInstance->mRect.y){
			if (mRect.y > -140){
			}
		}
		else if (CEnemy::spInstance->mRect.y < mRect.y){
		}

	}


	if (mRect.y>CEnemy::spInstance->mRect.y){
		DrawTaskManager::GetInstance()->ChangePriority(&m_Draw);
	}


}

void CSSearch::Render() {
	//左向き
	if (mRect.x > CEnemy::spInstance->mRect.x){


		//移動していないとき
		if (mMoving == false){
			if (mAniAttack == -10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniAttack > 10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniAttack > 0){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniAttack > -10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
		}
		//移動しているとき
		else{
			if (mAniMoving % 60 < 30){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniMoving % 60 < 60){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
		}

		//無敵フラグが立っていないとき

		//移動していないとき
		if (mMoving == false){
			if (mAniAttack == -10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniAttack > 10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniAttack > 0){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniAttack > -10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
		}
		//移動しているとき
		else{
			if (mAniMoving % 60 < 30){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniMoving % 60 < 60){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
		}
	}

	

	//右向き
	else{
		//無敵フラグが立っていないとき
		//移動していないとき
		if (mMoving == false){
			if (mAniAttack == -10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			//攻撃アニメーション
			else if (mAniAttack > 10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniAttack > 0){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniAttack >= -10){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
		}
		//移動しているとき
		else{
			//移動アニメーション
			if (mAniMoving % 60 < 30){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
			else if (mAniMoving % 60 < 60){
				mRect.Render(TextureEnemy1, 0, 600, 200, 0);
			}
		}
	}

	//無敵状態フラグが立っているとき

	//移動していないとき
	if (mMoving == false){
		if (mAniAttack == -10){
			mRect.Render(TextureEnemy1, 0, 600, 200, 0);
		}
		//攻撃アニメーション
		else if (mAniAttack > 10){
			mRect.Render(TextureEnemy1, 0, 600, 200, 0);
		}
		else if (mAniAttack > 0){
			mRect.Render(TextureEnemy1, 0, 600, 200, 0);
		}
		else if (mAniAttack >= -10){
			mRect.Render(TextureEnemy1, 0, 600, 200, 0);
		}
	}
	//移動しているとき
	else{
		//移動アニメーション
		if (mAniMoving % 60 < 30){
			mRect.Render(TextureEnemy1, 0, 600, 200, 0);
		}
		else if (mAniMoving % 60 < 60){
			mRect.Render(TextureEnemy1, 0, 600, 200, 0);
		}

	}

}


void CSSearch::Collision(CBase *i, CBase *y) {
	//プレイヤー1と当たったとき
	if (y->mTag == EPLAYER){
		if (y->mEnabled){
			if (mRect.Collision(y->mRect)){
				if (mAttack == true && mAttackLag == 0){
					mEnabled = false;


				}
			}
		}
	}

}
CSSearch*CSSearch::spInstance = 0;
