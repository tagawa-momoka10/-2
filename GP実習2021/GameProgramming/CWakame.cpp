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

extern CTexture Texturewa;
bool CWakame::mMoving;

CWakame::CWakame(){
	mDraw.RegistDraw(this, (DrawFunc)&CWakame::Render, DrawPriority::Transparent, "CWakame");
	mTag = EWAKAME;
	m_RectW.x = 40;
	m_RectW.y = 600;
	m_RectW.w = 20;
	m_RectW.h = 300;
	mAniMoving = INITIALIZE;

}

void CWakame::Update(){
	mEnabled = true;
}


void CWakame::Collision(CBase *i, CBase *y){
	////プレイヤー1と当たったとき

	//if (y->mTag == EPLAYER){
	//	if (mRect.Collision(y->mRect)){
	//		if (CKey::Push('A')) {
	//			mRect.x += SPEED;

	//		}
	//		if (CKey::Push('D')) {
	//			mRect.x -= SPEED;

	//		}
	//		if (CKey::Push('S')) {
	//			mRect.y += SPEED;

	//		}
	//	}
	//}
}


void CWakame::Render(){
	if (mTag == EWAKAME){
		m_RectW.Render(Texturewa, 0, 200, 600, 0);
	}
}