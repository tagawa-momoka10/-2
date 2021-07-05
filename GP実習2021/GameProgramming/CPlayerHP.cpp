#include "CPlayerHP.h"
#include "CKey.h"
#include "SampleProperty.h"
#include "TaskManager.h"
#include "CPlayer.h"

extern CTexture TexturePlayerHP;//主人公HP
extern CTexture TexturePlayerHPb;//HPバック

#define INITIALIZE 0;	//初期化
CPlayerHP*CPlayerHP::spInstance = 0;

CPlayerHP::CPlayerHP()
:mPositionX1(0), mPositionX2(0)
,mPositionY1(0), mPositionY2(0)
, mAniCnt(0)
, mAniMoving(0)

{
	//描画タスクに登録
	mDraw.RegistDraw(this, (DrawFunc)&CPlayerHP::Render, DrawPriority::Transparent, "CPlayerHP");
	mTag = EPLAYERHP;
	
	m_Rect1.x = 200;
	m_Rect1.y = 50;
	m_Rect1.w = 100;
	m_Rect1.h = 25;

	m_Rect2.x = 200;
	m_Rect2.y = 50;
	m_Rect2.w = 100;
	m_Rect2.h = 25;

	spInstance = this;

}

void CPlayerHP::Update(){
	if (CPlayer::mHp < 101){
		mPositionY1 = m_Rect1.y;
		mPositionX1 = m_Rect1.x;
		m_Rect1.y = CPlayer::spInstance->mRect.y + CPlayer::spInstance->mRect.h + m_Rect1.h + 20;
		m_Rect1.x = CPlayer::spInstance->mRect.x;

		mPositionY2 = m_Rect2.y;
		mPositionX2 = m_Rect2.x;
		m_Rect2.y = CPlayer::spInstance->mRect.y + CPlayer::spInstance->mRect.h + m_Rect2.h + 20;
		m_Rect2.x = CPlayer::spInstance->mRect.x;

		m_Rect2.x--;
		
	}
}


void CPlayerHP::Render() {
	m_Rect1.Render(TexturePlayerHP, 0, 200, 50, 0);

	m_Rect2.Render(TexturePlayerHP, 0, 200, 50, 0);

}
