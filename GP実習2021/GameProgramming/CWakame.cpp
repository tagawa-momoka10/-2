#include "CWakame.h"
#include "CPlayer.h"
#include "CKey.h"
#include "SampleProperty.h"
#include "TaskManager.h"
#include "DrawTaskManager.h"
#include "CPlayerAttack.h"
#include "CEnemy.h"
#include "CKey.h"

#define ANICNT 40		//アニメーション
#define INITIALIZE 0	//初期化

//extern CTexture TextureChara1;
//extern CTexture TextureChara1Attack;
bool CWakame::mMoving;

CWakame::CWakame(){
	mDraw.RegistDraw(this, (DrawFunc)&CWakame::Render, DrawPriority::Transparent, "CWakame");
	mTag = EWAKAME;
	mRect.x = 40;
	mRect.y = 100;
	mRect.w = 20;
	mRect.h = 50;
	mAniMoving = INITIALIZE;

}

void CWakame::Update(){

}


void CWakame::Collision(CBase *i, CBase *y){
	if (y->mTag == EENEMY_F){
		mRect.x -= 2;
		mRect.y -= 2;
	}
	if (y->mTag == EPLAYER){
		if (CKey::Push('A')){
			mRect.x += 2;
		}
		if (CKey::Push('D')){
			mRect.x -= 2;
		}
		if (CKey::Push('S')){
			mRect.y -= 2;
		}

	}
}

void CWakame::Render(){
}